LOCAL_PATH := $(call my-dir)

###############################################
## libhicmdservice jni
###############################################
include $(CLEAR_VARS)

#LOCAL_PROPRIETARY_MODULE := true
LOCAL_MODULE := libhistbcmdservice_jni
LOCAL_MODULE_TAGS := optional
LOCAL_CFLAGS := -DANDROID_NDK
LOCAL_MULTILIB := both
LOCAL_CFLAGS += -Wlong-long -Wformat -Wpointer-arith \
                -Wpointer-to-int-cast -Wint-to-pointer-cast -Wtype-limits
LOCAL_SRC_FILES := \
  com_nathan_adp_cmd.cpp

LOCAL_LDLIBS := -ldl -llog
LOCAL_C_INCLUDES += $(JNI_H_INCLUDE) \
	$(LOCAL_PATH)/../libs \
	$(TOP)/system/libhidl/transport/token/1.0/utils/include/ \
	$(TOP)/system/libhidl/base/include/ \
    $(call include-path-for, libhardware)/hardware \
    $(TOP)/frameworks/native/include \
	$(LOCAL_PATH) \
	$(TOP)/frameworks/native/libs/ui/include \
    $(TOP)/frameworks/native/libs/arect/include \
	$(TOP)/libnativehelper/include/nativehelper \
	$(TOP)/hardware/libhardware/include/hardware    \
	$(TOP)/hardware/libhardware/include/ \
	$(TOP)/frameworks/base/core/jni \
    $(TOP)/frameworks/native/libs/nativewindow/include/

LOCAL_SHARED_LIBRARIES := \
  libandroid_runtime \
  libbinder \
  libutils \
  libcutils \
  libhistbcmdservicemanageclient \
  libgui \
  libhwbinder \
  libnativehelper  
  
LOCAL_JNI_SHARED_LIBRARIES := libandroid_runtime
LOCAL_HEADER_LIBRARIES := jni_headers 
LOCAL_PRELINK_MODULE := false
include $(BUILD_SHARED_LIBRARY)

###############################################
