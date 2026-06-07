#
# SPDX-FileCopyrightText: The LineageOS Project
# SPDX-FileCopyrightText: 2026 Lynden Lewis <lyndenl25@yahoo.com>
# SPDX-License-Identifier: Apache-2.0
#

# Product characteristics
PRODUCT_CHARACTERISTICS := default

# API levels (Matches the Android 9 base shipping level)
PRODUCT_SHIPPING_API_LEVEL := 28

# Overlays
PRODUCT_ENFORCE_RRO_TARGETS := *

# Soong namespaces
PRODUCT_SOONG_NAMESPACES += \
    $(LOCAL_PATH)

# Copy fstab to ramdisk for early mount
PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/rootdir/etc/fstab.mt6761:$(TARGET_COPY_OUT_RAMDISK)/fstab.mt6761

# Health
PRODUCT_PACKAGES += \
    android.hardware.health@2.1-impl \
    android.hardware.health@2.1-impl.recovery \
    android.hardware.health@2.1-service

# Keymaster
PRODUCT_PACKAGES += \
    libkeymaster4 \
    libkeymaster4support

# Rootdir scripts (Built via rootdir/Android.bp)
PRODUCT_PACKAGES += \
    disable_tee_ta_log.sh \
    enable_tee_ta_log.sh \
    init.ssdaemon_vendor.sh \
    fstab.enableswap \
    fstab.mt6761 \
    factory_init.connectivity.rc \
    factory_init.project.rc \
    factory_init.rc \
    init.aee.rc \
    init.ago.rc \
    init.connectivity.rc \
    init.modem.rc \
    init.mt6761.rc \
    init.mt6761.usb.rc \
    init.project.rc \
    init.sensor_1_0.rc \
    init.vendor.rc \
    meta_init.connectivity.rc \
    meta_init.modem.rc \
    meta_init.project.rc \
    meta_init.rc \
    multi_init.rc


# Inherit proprietary files
$(call inherit-product, vendor/zte/Z3153/Z3153-vendor.mk)