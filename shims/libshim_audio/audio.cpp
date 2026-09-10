/*
 * SPDX-FileCopyrightText: The LineageOS Project
 * SPDX-FileCopyrightText: 2026 Lynden Lewis <lyndenl25@yahoo.com>
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdint.h>

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

/*
 * Legacy audio_format_t TypeConverter mTable shim
 * (In Android 11+, VectorTraits was renamed to DefaultTraits and mTable was removed in favor of audio_format_to_string)
 */
enum audio_format_t : uint32_t {
    AUDIO_FORMAT_DEFAULT = 0,
    AUDIO_FORMAT_PCM_16_BIT = 0x1,
    AUDIO_FORMAT_PCM_8_BIT = 0x2,
    AUDIO_FORMAT_PCM_32_BIT = 0x3,
    AUDIO_FORMAT_PCM_8_24_BIT = 0x4,
    AUDIO_FORMAT_PCM_FLOAT = 0x5,
    AUDIO_FORMAT_PCM_24_BIT_PACKED = 0x6,
    AUDIO_FORMAT_MP3 = 0x01000000u,
    AUDIO_FORMAT_AMR_NB = 0x02000000u,
    AUDIO_FORMAT_AMR_WB = 0x03000000u,
    AUDIO_FORMAT_AAC = 0x04000000u,
    AUDIO_FORMAT_AAC_MAIN = 0x04000001u,
    AUDIO_FORMAT_AAC_LC = 0x04000002u,
    AUDIO_FORMAT_AAC_SSR = 0x04000004u,
    AUDIO_FORMAT_AAC_LTP = 0x04000008u,
    AUDIO_FORMAT_AAC_HE_V1 = 0x04000010u,
    AUDIO_FORMAT_AAC_SCALABLE = 0x04000020u,
    AUDIO_FORMAT_AAC_ERLC = 0x04000040u,
    AUDIO_FORMAT_AAC_LD = 0x04000080u,
    AUDIO_FORMAT_AAC_HE_V2 = 0x04000100u,
    AUDIO_FORMAT_AAC_ELD = 0x04000200u,
    AUDIO_FORMAT_VORBIS = 0x05000000u,
    AUDIO_FORMAT_HE_AAC_V1 = 0x05000001u,
    AUDIO_FORMAT_HE_AAC_V2 = 0x05000002u,
    AUDIO_FORMAT_OPUS = 0x08000000u,
    AUDIO_FORMAT_AC3 = 0x09000000u,
    AUDIO_FORMAT_E_AC3 = 0x0A000000u,
    AUDIO_FORMAT_DTS = 0x0B000000u,
    AUDIO_FORMAT_DTS_HD = 0x0C000000u,
    AUDIO_FORMAT_IEC61937 = 0x0D000000u,
    AUDIO_FORMAT_DOLBY_TRUEHD = 0x0E000000u,
    AUDIO_FORMAT_QCELP = 0x0F000000u,
    AUDIO_FORMAT_EVRC = 0x10000000u,
    AUDIO_FORMAT_EVRCB = 0x11000000u,
    AUDIO_FORMAT_EVRCWB = 0x12000000u,
    AUDIO_FORMAT_EVRCNW = 0x13000000u,
    AUDIO_FORMAT_FLAC = 0x14000000u,
    AUDIO_FORMAT_ALAC = 0x15000000u,
    AUDIO_FORMAT_APE = 0x16000000u,
};

namespace android {

template <typename T>
struct VectorTraits {};

template <typename Traits>
struct TypeConverter {
    struct Table {
        const char *literal;
        audio_format_t value;
    };
    static const Table mTable[];
};

#define MAKE_STRING_FROM_ENUM(enumval) { #enumval, enumval }
#define TERMINATOR { nullptr, AUDIO_FORMAT_DEFAULT }

template <>
const TypeConverter<VectorTraits<audio_format_t>>::Table
TypeConverter<VectorTraits<audio_format_t>>::mTable[] = {
    MAKE_STRING_FROM_ENUM(AUDIO_FORMAT_DEFAULT),
    MAKE_STRING_FROM_ENUM(AUDIO_FORMAT_PCM_16_BIT),
    MAKE_STRING_FROM_ENUM(AUDIO_FORMAT_PCM_8_BIT),
    MAKE_STRING_FROM_ENUM(AUDIO_FORMAT_PCM_32_BIT),
    MAKE_STRING_FROM_ENUM(AUDIO_FORMAT_PCM_8_24_BIT),
    MAKE_STRING_FROM_ENUM(AUDIO_FORMAT_PCM_FLOAT),
    MAKE_STRING_FROM_ENUM(AUDIO_FORMAT_PCM_24_BIT_PACKED),
    MAKE_STRING_FROM_ENUM(AUDIO_FORMAT_MP3),
    MAKE_STRING_FROM_ENUM(AUDIO_FORMAT_AMR_NB),
    MAKE_STRING_FROM_ENUM(AUDIO_FORMAT_AMR_WB),
    MAKE_STRING_FROM_ENUM(AUDIO_FORMAT_AAC),
    MAKE_STRING_FROM_ENUM(AUDIO_FORMAT_AAC_MAIN),
    MAKE_STRING_FROM_ENUM(AUDIO_FORMAT_AAC_LC),
    MAKE_STRING_FROM_ENUM(AUDIO_FORMAT_AAC_SSR),
    MAKE_STRING_FROM_ENUM(AUDIO_FORMAT_AAC_LTP),
    MAKE_STRING_FROM_ENUM(AUDIO_FORMAT_AAC_HE_V1),
    MAKE_STRING_FROM_ENUM(AUDIO_FORMAT_AAC_SCALABLE),
    MAKE_STRING_FROM_ENUM(AUDIO_FORMAT_AAC_ERLC),
    MAKE_STRING_FROM_ENUM(AUDIO_FORMAT_AAC_LD),
    MAKE_STRING_FROM_ENUM(AUDIO_FORMAT_AAC_HE_V2),
    MAKE_STRING_FROM_ENUM(AUDIO_FORMAT_AAC_ELD),
    MAKE_STRING_FROM_ENUM(AUDIO_FORMAT_VORBIS),
    MAKE_STRING_FROM_ENUM(AUDIO_FORMAT_HE_AAC_V1),
    MAKE_STRING_FROM_ENUM(AUDIO_FORMAT_HE_AAC_V2),
    MAKE_STRING_FROM_ENUM(AUDIO_FORMAT_OPUS),
    MAKE_STRING_FROM_ENUM(AUDIO_FORMAT_AC3),
    MAKE_STRING_FROM_ENUM(AUDIO_FORMAT_E_AC3),
    MAKE_STRING_FROM_ENUM(AUDIO_FORMAT_DTS),
    MAKE_STRING_FROM_ENUM(AUDIO_FORMAT_DTS_HD),
    MAKE_STRING_FROM_ENUM(AUDIO_FORMAT_IEC61937),
    MAKE_STRING_FROM_ENUM(AUDIO_FORMAT_DOLBY_TRUEHD),
    MAKE_STRING_FROM_ENUM(AUDIO_FORMAT_QCELP),
    MAKE_STRING_FROM_ENUM(AUDIO_FORMAT_EVRC),
    MAKE_STRING_FROM_ENUM(AUDIO_FORMAT_EVRCB),
    MAKE_STRING_FROM_ENUM(AUDIO_FORMAT_EVRCWB),
    MAKE_STRING_FROM_ENUM(AUDIO_FORMAT_EVRCNW),
    MAKE_STRING_FROM_ENUM(AUDIO_FORMAT_FLAC),
    MAKE_STRING_FROM_ENUM(AUDIO_FORMAT_ALAC),
    MAKE_STRING_FROM_ENUM(AUDIO_FORMAT_APE),
    TERMINATOR
};

}  // namespace android
