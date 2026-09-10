/*
 * SPDX-FileCopyrightText: The LineageOS Project
 * SPDX-FileCopyrightText: The Android Open Source Project
 * SPDX-FileCopyrightText: 2026 Lynden Lewis <lyndenl25@yahoo.com>
 * SPDX-License-Identifier: Apache-2.0
 */

#include <string>
#include <vector>
#include <android-base/cmsg.h>
#include <android-base/unique_fd.h>

namespace unwindstack {

struct Unwinder {
    std::string FormatFrame(size_t frame_num);
};

std::string Unwinder::FormatFrame(size_t /*frame_num*/) {
    return "";
}

}  // namespace unwindstack

namespace android {
namespace base {

ssize_t ReceiveFileDescriptorVector(int sock, void* data, size_t len, size_t max_fds,
                                    std::vector<android::base::unique_fd>* fds) {
    return ReceiveFileDescriptorVector(borrowed_fd(sock), data, len, max_fds, fds);
}

}  // namespace base
}  // namespace android
