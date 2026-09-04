/*
 * Copyright (C) 2022-2026 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdint.h>
#include <new>
#include <string>
#include <ui/GraphicBuffer.h>
#include <ui/PixelFormat.h>

extern "C" {

void _ZN7android13GraphicBufferC1EjjijNSt3__112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE(
        void* thisptr, uint32_t width, uint32_t height, int32_t format, uint32_t usage,
        std::string requestorName) {
    new (thisptr) android::GraphicBuffer(width, height, format, usage, requestorName);
}

void _ZN7android13GraphicBufferC1EjjijjP13native_handleb(
        void* thisptr, uint32_t width, uint32_t height, int32_t format, uint32_t layerCount,
        uint64_t usage, native_handle_t* handle, bool keepOwnership) {
    new (thisptr) android::GraphicBuffer(handle, android::GraphicBuffer::TAKE_HANDLE, width, height, format, layerCount, usage, 0);
}

}
