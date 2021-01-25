#
# Copyright (C) 2016 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

###########################
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := vendor.nathan.hwstbcmdservice@1.0-impl
LOCAL_MULTILIB := 32
LOCAL_PROPRIETARY_MODULE := true
LOCAL_MODULE_RELATIVE_PATH := hw

LOCAL_SRC_FILES := \
    Hwstbcmdservice.cpp

LOCAL_C_INCLUDES := \
	frameworks/native/libs/binder/include \
    system/core/liblog \
	system/core/include \
    vendor/nathan/shell_cmd/histbcmdservice/hal     


LOCAL_SHARED_LIBRARIES := \
    libhidlbase \
    libhidltransport \
    libutils \
    liblog \
    libcutils \
    libhardware \
	libstbcmdservicehal \
    vendor.nathan.hwstbcmdservice@1.0

#LOCAL_CFLAGS += -Wlong-long -Wformat -Wpointer-arith

#LOCAL_CFLAGS += -D$(CHIPNAME)

include $(BUILD_SHARED_LIBRARY)
############################################

include $(CLEAR_VARS)
LOCAL_MODULE := vendor.nathan.hwstbcmdservice@1.0-service
LOCAL_INIT_RC := vendor.nathan.hwstbcmdservice@1.0-service.rc
LOCAL_PROPRIETARY_MODULE := true
LOCAL_MODULE_RELATIVE_PATH := hw
LOCAL_MULTILIB := 32
LOCAL_SRC_FILES := \
  service.cpp \

LOCAL_SHARED_LIBRARIES := \
  libhidlbase \
  libhidltransport \
  liblog \
  libbinder \
  libhwbinder \
  libutils \
  libhardware \
  vendor.nathan.hwstbcmdservice@1.0

include $(BUILD_EXECUTABLE)
