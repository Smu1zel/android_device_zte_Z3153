/*
 * Copyright (C) 2026 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <string>

namespace android {
namespace hardware {
namespace bluetooth {
namespace a2dp {
namespace V1_0 {

struct IBluetoothAudioOffload {
    static const char* descriptor;
    static void* getService(const std::string& name, bool getStub);
    int registerAsService(const std::string& name);
};

const char* IBluetoothAudioOffload::descriptor =
    "android.hardware.bluetooth.a2dp@1.0::IBluetoothAudioOffload";

void* IBluetoothAudioOffload::getService(const std::string& /*name*/, bool /*getStub*/) {
    return nullptr;
}

int IBluetoothAudioOffload::registerAsService(const std::string& /*name*/) {
    return 0;
}

}  // namespace V1_0
}  // namespace a2dp
}  // namespace bluetooth
}  // namespace hardware
}  // namespace android
