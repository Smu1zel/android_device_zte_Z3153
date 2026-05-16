#
# SPDX-FileCopyrightText: The LineageOS Project
# SPDX-FileCopyrightText: 2026 Lynden Lewis <lyndenl25@yahoo.com>
# SPDX-License-Identifier: Apache-2.0
#

# Product characteristics
PRODUCT_CHARACTERISTICS := default

# API levels (Matches the Android 9 base shipping level)
PRODUCT_SHIPPING_API_LEVEL := 28

# Soong namespaces
PRODUCT_SOONG_NAMESPACES += \
    $(LOCAL_PATH)