#
# SPDX-FileCopyrightText: The LineageOS Project
# SPDX-FileCopyrightText: 2026 Lynden Lewis <lyndenl25@yahoo.com>
# SPDX-License-Identifier: Apache-2.0
#

PRODUCT_MAKEFILES := \
    $(LOCAL_DIR)/twrp_Z3153.mk \
    $(LOCAL_DIR)/lineage_Z3153.mk

COMMON_LUNCH_CHOICES := \
    twrp_Z3153-eng \
    lineage_Z3153-user \
    lineage_Z3153-userdebug \
    lineage_Z3153-eng