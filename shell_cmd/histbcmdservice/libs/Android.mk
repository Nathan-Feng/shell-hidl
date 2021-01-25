LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_PRELINK_MODULE := false

LOCAL_MODULE_TAGS := optional

LOCAL_SRC_FILES:=           \
    HiStbcmdserviceManagerClient.cpp

LOCAL_SHARED_LIBRARIES := \
    libui \
    libutils \
    libcutils \
    liblog \
    libbinder  \
    libhidlbase \
    libhidltransport \
    libhwbinder \
    vendor.nathan.hwstbcmdservice@1.0

#LOCAL_PROPRIETARY_MODULE := true
LOCAL_MODULE := libhistbcmdservicemanageclient

include $(BUILD_SHARED_LIBRARY)

####################################################################################
