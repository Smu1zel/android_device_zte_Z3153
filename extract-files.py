#!/usr/bin/env -S PYTHONPATH=../../../tools/extract-utils python3
#
# SPDX-FileCopyrightText: The LineageOS Project
# SPDX-License-Identifier: Apache-2.0
#

from extract_utils.fixups_blob import (
    blob_fixup,
    blob_fixups_user_type,
)
from extract_utils.main import (
    ExtractUtils,
    ExtractUtilsModule,
)

namespace_imports = [
    'device/zte/Z3153',
    'hardware/mediatek',
]

blob_fixups: blob_fixups_user_type = {
    'vendor/bin/hw/android.hardware.wifi@1.0-service-lazy-mediatek': blob_fixup()
        .replace_needed('libwifi-hal.so', 'libwifi-hal-mtk.so'),
    'vendor/bin/netdagent': blob_fixup()
        .add_needed('libshim_netutils.so'),
    'vendor/lib/libmtk-ril.so': blob_fixup()
        .add_needed('libshim_netutils.so'),
    'vendor/lib/libmtknetutils.so': blob_fixup()
        .add_needed('libshim_netutils.so'),
    'vendor/lib/libcam.hal3a.v3.so': blob_fixup()
        .add_needed('libshim_gui.so'),
    'vendor/lib/libMtkOmxVenc.so': blob_fixup()
        .add_needed('libshim_gui.so'),
    'vendor/bin/hw/android.hardware.audio@5.0-service-mediatek': blob_fixup()
        .replace_needed('android.hardware.bluetooth.a2dp@1.0.so', 'libshim_bt_a2dp.so'),
    'vendor/lib/hw/android.hardware.audio@5.0-impl-mediatek.so': blob_fixup()
        .add_needed('libshim_audio.so'),
    (
        'vendor/lib/hw/audio.primary.mt6761.so',
        'vendor/lib/hw/sound_trigger.primary.mt6761.so',
    ): blob_fixup()
        .remove_needed('android.hardware.bluetooth.a2dp@1.0.so'),
}

module = ExtractUtilsModule(
    'Z3153',
    'zte',
    blob_fixups=blob_fixups,
    namespace_imports=namespace_imports,
)

if __name__ == '__main__':
    utils = ExtractUtils.device(module)
    utils.run()
