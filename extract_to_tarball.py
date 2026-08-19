#!/usr/bin/env python3
import os
import sys
import shutil
import subprocess
import tempfile

def parse_proprietary_files(file_path):
    files = []
    with open(file_path, 'r') as f:
        for line in f:
            line = line.strip()
            if not line or line.startswith('#'):
                continue
            # Strip leading '-'
            if line.startswith('-'):
                line = line[1:]
            # Strip sha1sum
            if '|' in line:
                line = line.split('|')[0].strip()
            # Handle source:destination
            if ':' in line:
                src, dest = line.split(':', 1)
                files.append((src.strip(), dest.strip()))
            else:
                files.append((line, line))
    return files

def is_sparse(image_path):
    try:
        with open(image_path, 'rb') as f:
            header = f.read(4)
            return header == b'\x3a\xff\x26\xed' # Sparse image magic
    except Exception:
        return False

def convert_sparse_to_raw(sparse_path, raw_path):
    print(f"Converting sparse image {sparse_path} to raw image...")
    subprocess.run(['simg2img', sparse_path, raw_path], check=True)

def main():
    if os.geteuid() != 0:
        print("This script must be run as root (sudo) to mount the filesystem images.", file=sys.stderr)
        sys.exit(1)

    if len(sys.argv) < 5:
        print("Usage: sudo python3 extract_to_tarball.py <proprietary-files.txt> <system.img> <vendor.img> <output.tar.gz>", file=sys.stderr)
        sys.exit(1)

    prop_file = sys.argv[1]
    system_img = sys.argv[2]
    vendor_img = sys.argv[3]
    output_tar = sys.argv[4]

    # Parse files
    files_to_extract = parse_proprietary_files(prop_file)
    print(f"Parsed {len(files_to_extract)} files to extract.")

    temp_dirs = []
    raw_system = system_img
    raw_vendor = vendor_img

    try:
        # Handle sparse images
        if is_sparse(system_img):
            raw_system = tempfile.mktemp(suffix=".raw.img")
            convert_sparse_to_raw(system_img, raw_system)
            temp_dirs.append(raw_system)
        if is_sparse(vendor_img):
            raw_vendor = tempfile.mktemp(suffix=".raw.img")
            convert_sparse_to_raw(vendor_img, raw_vendor)
            temp_dirs.append(raw_vendor)

        # Create mount points
        mount_system = tempfile.mkdtemp(prefix="mount_system_")
        mount_vendor = tempfile.mkdtemp(prefix="mount_vendor_")
        temp_dirs.extend([mount_system, mount_vendor])

        # Mount images
        print("Mounting images...")
        subprocess.run(['mount', '-o', 'loop,ro', raw_system, mount_system], check=True)
        subprocess.run(['mount', '-o', 'loop,ro', raw_vendor, mount_vendor], check=True)

        # Create staging directory
        staging_dir = tempfile.mkdtemp(prefix="staging_vendor_")
        temp_dirs.append(staging_dir)

        # Extract files
        print("Extracting files...")
        for src, dest in files_to_extract:
            # Determine source path
            if src.startswith('vendor/'):
                src_path = os.path.join(mount_vendor, src[len('vendor/'):])
            elif src.startswith('odm/'):
                src_path = os.path.join(mount_vendor, 'odm', src[len('odm/'):])
            else:
                # Non-vendor/non-odm files belong to the system partition.
                # In system-as-root images, the filesystem contains the 'system/' directory at the root.
                if src.startswith('system/'):
                    src_path = os.path.join(mount_system, src)
                else:
                    src_path = os.path.join(mount_system, 'system', src)

            # Determine destination path in staging
            dest_path = os.path.join(staging_dir, 'vendor/zte/Z3153/proprietary', dest)
            os.makedirs(os.path.dirname(dest_path), exist_ok=True)

            if not os.path.exists(src_path):
                print(f"Warning: Source file {src_path} does not exist. Skipping.")
                continue

            # Copy file or symlink preserving attributes
            if os.path.islink(src_path):
                link_target = os.readlink(src_path)
                os.symlink(link_target, dest_path)
            else:
                shutil.copy2(src_path, dest_path)

        # Create tarball
        print(f"Creating tarball {output_tar}...")
        # We want to tar the files inside staging_dir (preserving directory structure from the root of vendor/)
        subprocess.run(['tar', '-czf', output_tar, '-C', staging_dir, '.'], check=True)
        print("Tarball created successfully.")

    finally:
        print("Cleaning up...")
        # Unmount
        for mount_point in [mount_system, mount_vendor]:
            if os.path.ismount(mount_point):
                subprocess.run(['umount', mount_point])
        # Remove temp files/directories
        for path in temp_dirs:
            if os.path.exists(path):
                if os.path.isdir(path):
                    shutil.rmtree(path, ignore_errors=True)
                else:
                    os.remove(path)

if __name__ == '__main__':
    main()
