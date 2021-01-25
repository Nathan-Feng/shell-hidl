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
#include <vendor/nathan/hwstbcmdservice/1.0/IHwstbcmdservice.h>
#include <hidl/MQDescriptor.h>

namespace vendor {
namespace nathan {
namespace hwstbcmdservice {
namespace V1_0 {
namespace implementation {

using ::vendor::nathan::hwstbcmdservice::V1_0::IHwstbcmdservice;
using ::android::hardware::Return;
using ::android::hardware::Void;
using ::android::hardware::hidl_vec;
using ::android::hardware::hidl_string;
using ::android::sp;

struct Hwstbcmdservice : public IHwstbcmdservice {
    Hwstbcmdservice();	
	Return<void> hsInvokeHal(const hidl_string& request, int32_t type , hsInvokeHal_cb _hidl_cb) override;
};

extern "C" IHwstbcmdservice* HIDL_FETCH_IHwstbcmdservice(const char* name);

}  // namespace implementation
}  // namespace V1_0
}  // namespace hwstbcmdservice
}  // namespace nathan
}  // namespace vendor
