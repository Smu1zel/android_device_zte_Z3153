/*
 * Copyright (C) 2022-2026 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdint.h>
#include <stddef.h>

struct camera_metadata;

namespace android {

class CameraMetadata;
class Sensor;

extern "C" {

void _ZN7android14CameraMetadata6unlockEPK15camera_metadata(void* thisptr, const camera_metadata* buffer) {
    (void)thisptr;
    (void)buffer;
}

int32_t _ZN7android13SensorManager13getSensorListEPPKPKNS_6SensorE(void* thisptr, Sensor const* const** list) {
    (void)thisptr;
    (void)list;
    return 0;
}

}

} // namespace android
