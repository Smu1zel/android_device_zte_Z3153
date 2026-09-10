#!/bin/bash
#
# SPDX-FileCopyrightText: The LineageOS Project
# SPDX-FileCopyrightText: 2026 Lynden Lewis <lyndenl25@yahoo.com>
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

# Initialize the helper
setup_vendor "$DEVICE" "$VENDOR" "$ANDROID_ROOT"

# Warning headers and copyright
write_headers

write_makefiles "$MY_DIR"/proprietary-files.txt true

# Finish
write_footers
