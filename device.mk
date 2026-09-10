#
# SPDX-FileCopyrightText: The LineageOS Project
# SPDX-FileCopyrightText: 2026 Lynden Lewis <lyndenl25@yahoo.com>
# SPDX-License-Identifier: Apache-2.0
#

LOCAL_PATH := device/zte/Z3153

# Product characteristics
PRODUCT_CHARACTERISTICS := default

# API levels (Matches the Android 9 base shipping level)
PRODUCT_SHIPPING_API_LEVEL := 28

# Overlays
PRODUCT_ENFORCE_RRO_TARGETS := *

# Soong namespaces
PRODUCT_SOONG_NAMESPACES += \
    $(LOCAL_PATH)

# Permissions / Features
PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/rootdir/etc/fstab.mt6761:$(TARGET_COPY_OUT_RAMDISK)/fstab.mt6761 \
    frameworks/native/data/etc/android.hardware.audio.low_latency.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.audio.low_latency.xml \
    frameworks/native/data/etc/android.hardware.bluetooth.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.bluetooth.xml \
    frameworks/native/data/etc/android.hardware.bluetooth_le.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.bluetooth_le.xml \
    frameworks/native/data/etc/android.hardware.camera.flash-autofocus.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.camera.flash-autofocus.xml \
    frameworks/native/data/etc/android.hardware.camera.front.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.camera.front.xml \
    frameworks/native/data/etc/android.hardware.sensor.accelerometer.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.sensor.accelerometer.xml \
    frameworks/native/data/etc/android.hardware.sensor.compass.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.sensor.compass.xml \
    frameworks/native/data/etc/android.hardware.sensor.gyroscope.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.sensor.gyroscope.xml \
    frameworks/native/data/etc/android.hardware.sensor.light.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.sensor.light.xml \
    frameworks/native/data/etc/android.hardware.sensor.proximity.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.sensor.proximity.xml \
    frameworks/native/data/etc/android.hardware.telephony.gsm.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.telephony.gsm.xml \
    frameworks/native/data/etc/android.hardware.touchscreen.multitouch.distinct.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.touchscreen.multitouch.distinct.xml \
    frameworks/native/data/etc/android.hardware.wifi.direct.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.wifi.direct.xml \
    frameworks/native/data/etc/android.hardware.wifi.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.wifi.xml \
    frameworks/native/data/etc/android.software.midi.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.software.midi.xml \
    frameworks/native/data/etc/android.software.sip.voip.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.software.sip.voip.xml \
    frameworks/native/data/etc/android.hardware.usb.host.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.usb.host.xml \
    frameworks/native/data/etc/android.hardware.usb.accessory.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.usb.accessory.xml \
    $(LOCAL_PATH)/prebuilt/ztecharger:$(TARGET_COPY_OUT_VENDOR)/bin/ztecharger \
    $(LOCAL_PATH)/rootdir/etc/init.ztecharger.rc:$(TARGET_COPY_OUT_VENDOR)/etc/init/init.ztecharger.rc

# Copy ztecharger resources to system and ramdisk
PRODUCT_COPY_FILES += \
    $(foreach f,$(wildcard $(LOCAL_PATH)/rootdir/res/images/ztecharger/*),$(f):$(TARGET_COPY_OUT_SYSTEM)/res/images/ztecharger/$(notdir $(f))) \
    $(foreach f,$(wildcard $(LOCAL_PATH)/rootdir/res/images/ztecharger/*),$(f):$(TARGET_COPY_OUT_RAMDISK)/res/images/ztecharger/$(notdir $(f)))


# AIDL Services & HALs
PRODUCT_PACKAGES += \
    android.hardware.health-service.example \
    android.hardware.health-service.example_recovery \
    android.hardware.lights-service.example \
    android.hardware.vibrator-service.example \
    android.hardware.power-service.example \
    android.hardware.memtrack-service.example \
    compatibility_matrix.4.xml

# Vendor Compatibility Shims (Device-specific & LineageOS Standard)
PRODUCT_PACKAGES += \
    libshim_gui \
    libshim_camera \
    libshim_netutils \
    libshim_bt_a2dp \
    libshim_audio \
    libcamera_metadata_shim \
    libui_shim \
    libprocessgroup_shim

# Graphics
PRODUCT_PACKAGES += \
    libdrm.vendor \
    libsensorndkbridge

# Audio
PRODUCT_PACKAGES += \
    android.hardware.audio.common@5.0-util \
    libtinyxml \
    libtinycompress

# Low-RAM Optimization
PRODUCT_PROPERTY_OVERRIDES += \
    ro.config.low_ram=true

# ART - Disable UFFD GC on kernel 4.9 (requires kernel 5.4+ / userfaultfd MREMAP_DONTUNMAP)
PRODUCT_ENABLE_UFFD_GC := false


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

# Disable RSA auth popup and force ADB enabled by default
# This is temporary.
PRODUCT_SYSTEM_DEFAULT_PROPERTIES += \
    ro.adb.secure=0 \
    persist.sys.usb.config=adb

# Inherit proprietary files
$(call inherit-product, vendor/zte/Z3153/Z3153-vendor.mk)