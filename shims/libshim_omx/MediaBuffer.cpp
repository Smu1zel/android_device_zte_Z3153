/*
 * Copyright (C) 2022-2026 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stddef.h>
#include <stdint.h>
#include <media/stagefright/MediaBuffer.h>

namespace android {

extern "C" {

void _ZN7android11MediaBufferC1Ejj(void* thisptr, size_t size, uint32_t flags) {
    (void)flags;
    new (thisptr) MediaBuffer(size);
}

}

} // namespace android
