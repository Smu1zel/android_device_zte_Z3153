/*
 * SPDX-FileCopyrightText: The LineageOS Project
 * SPDX-FileCopyrightText: The Android Open Source Project
 * SPDX-FileCopyrightText: 2026 Lynden Lewis <lyndenl25@yahoo.com>
 * SPDX-License-Identifier: Apache-2.0
 */

#include <gatekeeper/gatekeeper_messages.h>
#include <stdint.h>
#include <new>
#include <utility>

namespace gatekeeper {

struct LegacySizedBuffer {
    uint8_t* buffer;
    uint32_t length;
};

static inline SizedBuffer make_sized_buffer(LegacySizedBuffer* buf) {
    if (buf != nullptr && buf->buffer != nullptr) {
        uint8_t* raw = buf->buffer;
        uint32_t len = buf->length;
        buf->buffer = nullptr;
        buf->length = 0;
        return SizedBuffer(raw, len);
    }
    return SizedBuffer();
}

extern "C" {

void _ZN10gatekeeper13EnrollRequestC1EjPNS_11SizedBufferES2_S2_(
        void* thisptr, uint32_t user_id, LegacySizedBuffer* password_handle,
        LegacySizedBuffer* provided_password, LegacySizedBuffer* enrolled_password) {
    new (thisptr) EnrollRequest(
            user_id,
            make_sized_buffer(password_handle),
            make_sized_buffer(provided_password),
            make_sized_buffer(enrolled_password));
}

void _ZN10gatekeeper13EnrollRequestC2EjPNS_11SizedBufferES2_S2_(
        void* thisptr, uint32_t user_id, LegacySizedBuffer* password_handle,
        LegacySizedBuffer* provided_password, LegacySizedBuffer* enrolled_password) {
    _ZN10gatekeeper13EnrollRequestC1EjPNS_11SizedBufferES2_S2_(
            thisptr, user_id, password_handle, provided_password, enrolled_password);
}

void _ZN10gatekeeper13EnrollRequestD1Ev(void* thisptr) {
    static_cast<EnrollRequest*>(thisptr)->~EnrollRequest();
}

void _ZN10gatekeeper13EnrollRequestD2Ev(void* thisptr) {
    _ZN10gatekeeper13EnrollRequestD1Ev(thisptr);
}

void _ZN10gatekeeper13VerifyRequestC1EjyPNS_11SizedBufferES2_(
        void* thisptr, uint32_t user_id, uint64_t challenge,
        LegacySizedBuffer* enrolled_password_handle, LegacySizedBuffer* provided_password_payload) {
    new (thisptr) VerifyRequest(
            user_id, challenge,
            make_sized_buffer(enrolled_password_handle),
            make_sized_buffer(provided_password_payload));
}

void _ZN10gatekeeper13VerifyRequestC2EjyPNS_11SizedBufferES2_(
        void* thisptr, uint32_t user_id, uint64_t challenge,
        LegacySizedBuffer* enrolled_password_handle, LegacySizedBuffer* provided_password_payload) {
    _ZN10gatekeeper13VerifyRequestC1EjyPNS_11SizedBufferES2_(
            thisptr, user_id, challenge, enrolled_password_handle, provided_password_payload);
}

void _ZN10gatekeeper13VerifyRequestD1Ev(void* thisptr) {
    static_cast<VerifyRequest*>(thisptr)->~VerifyRequest();
}

void _ZN10gatekeeper13VerifyRequestD2Ev(void* thisptr) {
    _ZN10gatekeeper13VerifyRequestD1Ev(thisptr);
}

void _ZN10gatekeeper14EnrollResponseC1EjPNS_11SizedBufferE(
        void* thisptr, uint32_t user_id, LegacySizedBuffer* enrolled_password_handle) {
    new (thisptr) EnrollResponse(
            user_id,
            make_sized_buffer(enrolled_password_handle));
}

void _ZN10gatekeeper14EnrollResponseC2EjPNS_11SizedBufferE(
        void* thisptr, uint32_t user_id, LegacySizedBuffer* enrolled_password_handle) {
    _ZN10gatekeeper14EnrollResponseC1EjPNS_11SizedBufferE(
            thisptr, user_id, enrolled_password_handle);
}

void _ZN10gatekeeper14EnrollResponseD1Ev(void* thisptr) {
    static_cast<EnrollResponse*>(thisptr)->~EnrollResponse();
}

void _ZN10gatekeeper14EnrollResponseD2Ev(void* thisptr) {
    _ZN10gatekeeper14EnrollResponseD1Ev(thisptr);
}

void _ZN10gatekeeper14VerifyResponseD1Ev(void* thisptr) {
    static_cast<VerifyResponse*>(thisptr)->~VerifyResponse();
}

void _ZN10gatekeeper14VerifyResponseD2Ev(void* thisptr) {
    _ZN10gatekeeper14VerifyResponseD1Ev(thisptr);
}

}  // extern "C"

}  // namespace gatekeeper
