LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)


LOCAL_SRC_FILES := nathan_hal.c

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../gpio/
			
LOCAL_SHARED_LIBRARIES :=\
                    libcutils \
					libutils \
                    liblog

					
LOCAL_MODULE_TAGS := optional
LOCAL_PROPRIETARY_MODULE := true
LOCAL_MODULE := libstbcmdservicehal
LOCAL_MULTILIB := 32
LOCAL_CFLAGS += -Wlong-long -Wformat -Wpointer-arith

include $(BUILD_SHARED_LIBRARY)
