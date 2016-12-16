/*
 * Copyright (C) 2016 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ANDROID_HARDWARE_EVS_V1_0_EVSCAMERAENUMERATOR_H
#define ANDROID_HARDWARE_EVS_V1_0_EVSCAMERAENUMERATOR_H

#include <android/hardware/evs/1.0/IEvsEnumerator.h>
#include <android/hardware/evs/1.0/IEvsCamera.h>

#include <list>

#include "EvsCamera.h"

namespace android {
namespace hardware {
namespace evs {
namespace V1_0 {
namespace implementation {

class EvsEnumerator : public IEvsEnumerator {
public:
    // Methods from ::android::hardware::evs::V1_0::IEvsEnumerator follow.
    Return<void> getCameraList(getCameraList_cb _hidl_cb)  override;
    Return<void> openCamera(const hidl_string& cameraId, openCamera_cb callback)  override;
    Return<void> closeCamera(const ::android::sp<IEvsCamera>& carCamera)  override;
    Return<void> openDisplay(openDisplay_cb callback)  override;
    Return<void> closeDisplay(const ::android::sp<IEvsDisplay>& display)  override;

    // Implementation details
    EvsEnumerator();

private:
    struct CameraRecord {
        sp<EvsCamera>   pCamera;
        bool            inUse;
        CameraRecord(EvsCamera* p, bool b) : pCamera(p), inUse(b) {}
    };
    std::list<CameraRecord> mCameraList;

    sp<IEvsDisplay>         mActiveDisplay;
};

} // namespace implementation
} // namespace V1_0
} // namespace evs
} // namespace hardware
} // namespace android

#endif  // ANDROID_HARDWARE_EVS_V1_0_EVSCAMERAENUMERATOR_H