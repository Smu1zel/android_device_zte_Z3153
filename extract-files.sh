#!/bin/bash
#
# Copyright (C) 2016 The CyanogenMod Project
# Copyright (C) 2017-2020 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

set -e

DEVICE=Z3153
VENDOR=zte

# Load extract-utils and do some sanity checks
MY_DIR="${BASH_SOURCE[0]}"
if [ ! -d "$MY_DIR" ]; then MY_DIR="$PWD"; fi

ANDROID_ROOT="$MY_DIR/../../.."

HELPER="$ANDROID_ROOT/tools/extract-utils/extract_utils.sh"
if [ ! -f "$HELPER" ]; then
    HELPER="$ANDROID_ROOT/vendor/lineage/build/tools/extract_utils.sh"
fi
if [ ! -f "$HELPER" ]; then
    echo "Unable to find helper script at $HELPER"
    exit 1
fi
source "$HELPER"

# Default to sanitizing etc.
CLEAN_OBJS=true

while [ "${#}" -gt 0 ]; do
    case "${1}" in
        -n | --no-cleanup )
            CLEAN_OBJS=false
            ;;
        -k | --write-keyzip )
            WRITE_KEYZIP=true
            ;;
        *)
            SRC="${1}"
            ;;
    esac
    shift
done

if [ -z "$SRC" ]; then
    SRC="adb"
fi

# Initialize the helper
setup_vendor "$DEVICE" "$VENDOR" "$ANDROID_ROOT" false "$CLEAN_OBJS"

extract "$MY_DIR"/proprietary-files.txt "$SRC" "$SECTION"

"$MY_DIR"/setup-makefiles.sh
