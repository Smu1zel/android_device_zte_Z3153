/*
 * Copyright (C) 2026 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

struct audio_config;

namespace android {
namespace hardware {

template <typename T>
struct hidl_vec;

namespace audio {
namespace common {
namespace V5_0 {

struct AudioConfig;
struct AudioPortConfig;

namespace implementation {

struct HidlUtils {
    static int audioConfigFromHal(const audio_config&, AudioConfig*);
    static int audioPortConfigsToHal(const hidl_vec<AudioPortConfig>&);
};

int HidlUtils::audioConfigFromHal(const audio_config&, AudioConfig*) {
    return 0;
}

int HidlUtils::audioPortConfigsToHal(const hidl_vec<AudioPortConfig>&) {
    return 0;
}

}  // namespace implementation
}  // namespace V5_0
}  // namespace common
}  // namespace audio
}  // namespace hardware
}  // namespace android
