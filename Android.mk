#
# SPDX-FileCopyrightText: The LineageOS Project
# SPDX-FileCopyrightText: 2026 Lynden Lewis <lyndenl25@yahoo.com>
# SPDX-License-Identifier: Apache-2.0
#

LOCAL_PATH := $(call my-dir)

ifeq ($(TARGET_DEVICE),Z3153)
include $(call all-subdir-makefiles,$(LOCAL_PATH))
endif
