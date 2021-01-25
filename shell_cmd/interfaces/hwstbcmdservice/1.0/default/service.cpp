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
#define LOG_TAG "vendor.nathan.hwstbcmdservice@1.0-service"

#include <vendor/nathan/hwstbcmdservice/1.0/IHwstbcmdservice.h>
#include <hidl/LegacySupport.h>
#include <android/log.h>
#include <binder/ProcessState.h>

using vendor::nathan::hwstbcmdservice::V1_0::IHwstbcmdservice;
using android::hardware::defaultPassthroughServiceImplementation;

int main() {
    android::ProcessState::initWithDriver("/dev/vndbinder");
    android::ProcessState::self()->setThreadPoolMaxThreadCount(4);
    android::ProcessState::self()->startThreadPool();

	printf("---> nathan hwstbcmdservice vendor service main run \n");
    return defaultPassthroughServiceImplementation<IHwstbcmdservice>(4);
}
