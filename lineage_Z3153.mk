#
# SPDX-FileCopyrightText: The LineageOS Project
# SPDX-FileCopyrightText: 2026 Lynden Lewis <lyndenl25@yahoo.com>
# SPDX-License-Identifier: Apache-2.0
#

# Inherit from those products. Most specific first.
$(call inherit-product, $(SRC_TARGET_DIR)/product/generic_ramdisk.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/languages_full.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/full_base_telephony.mk)

# Inherit some common Lineage stuff.
$(call inherit-product, vendor/lineage/config/common_full_phone.mk)

# Inherit from Z3153 device
$(call inherit-product, device/zte/Z3153/device.mk)

PRODUCT_DEVICE := Z3153
PRODUCT_NAME := lineage_Z3153
PRODUCT_BRAND := ZTE
PRODUCT_MODEL := Z3153V
PRODUCT_MANUFACTURER := ZTE

PRODUCT_GMS_CLIENTID_BASE := android-zte

BUILD_FINGERPRINT := ZTE/VZW_Z3153V/Z3153:10/QP1A.190711.020/20210811.113413:user/release-keys
