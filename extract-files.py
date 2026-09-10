#!/usr/bin/env -S PYTHONPATH=../../../tools/extract-utils python3
#
# SPDX-FileCopyrightText: The LineageOS Project
# SPDX-FileCopyrightText: 2026 Lynden Lewis <lyndenl25@yahoo.com>
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
    'hardware/lineage/compat',
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
    'vendor/lib/libwifi-hal-mtk.so': blob_fixup()
        .fix_soname(),
    'vendor/lib/hw/audio.primary.mt6761.so': blob_fixup()
        .add_needed('libshim_audio.so')
        .remove_needed('android.hardware.bluetooth.a2dp@1.0.so'),
    'vendor/lib/hw/sound_trigger.primary.mt6761.so': blob_fixup()
        .remove_needed('android.hardware.bluetooth.a2dp@1.0.so'),
    (
        'vendor/lib/libwvhidl.so',
        'vendor/lib/mediadrm/libwvdrmengine.so',
    ): blob_fixup()
        .replace_needed('libprotobuf-cpp-lite.so', 'libprotobuf-cpp-lite-v29.so'),
    (
        'vendor/bin/mnld',
        'vendor/lib/libaalservice.so',
        'vendor/lib/libcam.utils.sensorprovider.so',
    ): blob_fixup()
        .add_needed('android.hardware.sensors@1.0-convert-shared.so'),
    (
        'vendor/lib/libnvram.so',
        'vendor/lib/libsysenv.so',
    ): blob_fixup()
        .add_needed('libbase_shim.so'),
    'vendor/lib/libMtkOmxVdecEx.so': blob_fixup()
        .add_needed('libui_shim.so'),
    'vendor/lib/libutinterface_custom_md.so': blob_fixup()
        .add_needed('libutinterface_md.so'),
    'vendor/lib/libmnl.so': blob_fixup()
        .add_needed('libcutils.so'),
    'vendor/lib/hw/gatekeeper.zte.so': blob_fixup()
        .add_needed('libshim_gatekeeper.so'),
    'vendor/lib/libmtkcam_stdutils.so': blob_fixup()
        .add_needed('libshim_camera.so'),
    (
        'vendor/lib/libladder.so',
        'vendor/lib/libaedv.so',
    ): blob_fixup()
        .add_needed('libshim_unwind.so'),
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
