/*
 * SPDX-FileCopyrightText: The LineageOS Project
 * SPDX-FileCopyrightText: The Android Open Source Project
 * SPDX-FileCopyrightText: 2026 Lynden Lewis <lyndenl25@yahoo.com>
 * SPDX-License-Identifier: Apache-2.0
 */

#include <utils/String8.h>
#include <map>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

namespace android {

class PropertyMap {
public:
    PropertyMap();
    ~PropertyMap();

    void clear();
    void addProperty(const String8& key, const String8& value);
    bool hasProperty(const String8& key) const;
    bool tryGetProperty(const String8& key, String8& outValue) const;
    bool tryGetProperty(const String8& key, bool& outValue) const;
    bool tryGetProperty(const String8& key, int32_t& outValue) const;
    bool tryGetProperty(const String8& key, float& outValue) const;

private:
    struct String8Less {
        bool operator()(const String8& a, const String8& b) const {
            return strcmp(a.c_str(), b.c_str()) < 0;
        }
    };
    std::map<String8, String8, String8Less> mProperties;
};

PropertyMap::PropertyMap() {}

PropertyMap::~PropertyMap() {}

void PropertyMap::clear() {
    mProperties.clear();
}

void PropertyMap::addProperty(const String8& key, const String8& value) {
    mProperties[key] = value;
}

bool PropertyMap::hasProperty(const String8& key) const {
    return mProperties.find(key) != mProperties.end();
}

bool PropertyMap::tryGetProperty(const String8& key, String8& outValue) const {
    auto it = mProperties.find(key);
    if (it == mProperties.end()) {
        return false;
    }
    outValue = it->second;
    return true;
}

bool PropertyMap::tryGetProperty(const String8& key, bool& outValue) const {
    int32_t intValue;
    if (!tryGetProperty(key, intValue)) {
        return false;
    }
    outValue = (intValue != 0);
    return true;
}

bool PropertyMap::tryGetProperty(const String8& key, int32_t& outValue) const {
    String8 stringValue;
    if (!tryGetProperty(key, stringValue) || stringValue.empty()) {
        return false;
    }
    char* end;
    long value = strtol(stringValue.c_str(), &end, 10);
    if (*end != '\0') {
        return false;
    }
    outValue = static_cast<int32_t>(value);
    return true;
}

bool PropertyMap::tryGetProperty(const String8& key, float& outValue) const {
    String8 stringValue;
    if (!tryGetProperty(key, stringValue) || stringValue.empty()) {
        return false;
    }
    char* end;
    float value = strtof(stringValue.c_str(), &end);
    if (*end != '\0') {
        return false;
    }
    outValue = value;
    return true;
}

}  // namespace android
