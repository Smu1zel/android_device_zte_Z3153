#
# SPDX-FileCopyrightText: The LineageOS Project
# SPDX-FileCopyrightText: 2026 Lynden Lewis <lyndenl25@yahoo.com>
# SPDX-License-Identifier: Apache-2.0
#

# Inherit from those products. Most specific first.
$(call inherit-product, $(SRC_TARGET_DIR)/product/core_64_bit.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/base.mk)

# Inherit some common TWRP stuff
$(call inherit-product, vendor/twrp/config/common.mk)

# Inherit from Z3153 device
$(call inherit-product, device/zte/Z3153/device.mk)

PRODUCT_DEVICE := Z3153
PRODUCT_NAME := twrp_Z3153
PRODUCT_BRAND := ZTE
PRODUCT_MODEL := Z3153V
PRODUCT_MANUFACTURER := ZTE