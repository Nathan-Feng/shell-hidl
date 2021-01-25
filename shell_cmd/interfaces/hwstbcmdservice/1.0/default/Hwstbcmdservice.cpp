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
#include <private/android_filesystem_config.h>
#include <utils/String16.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/types.h>
#include <sys/ioctl.h>
#include <utils/Log.h>
#include <cutils/properties.h>
#include <string>
#include <pthread.h>

#include <binder/Parcel.h>

#include "Hwstbcmdservice.h"
#include "nathan_hal.h"

#ifdef LOG_TAG
#undef LOG_TAG
#endif
#define LOG_TAG "libhwstbcmdservice"

namespace vendor {
namespace nathan {
namespace hwstbcmdservice {
namespace V1_0 {
namespace implementation {


Hwstbcmdservice::Hwstbcmdservice(){
	ALOGW("Hwstbcmdservice construct\n");
};

Return<void> Hwstbcmdservice::hsInvokeHal(const hidl_string& request, int32_t type, hsInvokeHal_cb _hidl_cb)
{
    ALOGE("zyf Hwstbcmdservice::HS_Invode %s   type:%d",request.c_str(),type);
	const char* result = hsInvokeNative(request.c_str(),type);
	ALOGE("zyf Hwstbcmdservice::HS_Invode result %s ",result);
	hidl_string cb(result);
	_hidl_cb(cb);	
    return Void();
};


IHwstbcmdservice* HIDL_FETCH_IHwstbcmdservice(const char * /*hal*/) {

	return new Hwstbcmdservice();
}


} // namespace implementation
}  // namespace V1_0
}  // namespace hwstbcmdservice
}  // namespace nathan
}  // namespace vendor
