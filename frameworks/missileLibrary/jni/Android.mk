LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_PRELINK_MODULE := false

LOCAL_C_INCLUDES += \
		$(JNI_H_INCLUDE )\
	   	device/utbm/samzeu/libusb-1.0.3/libusb/ \
		device/utbm/samzeu/libusb-1.0.3/libusb/os

LOCAL_SRC_FILES := libsamzeu-mlbin-jni.c
LOCAL_SHARED_LIBRARIES := libusb libcutils libutils

LOCAL_MODULE := mlbin-jni
LOCAL_MODULE_TAGS := optional

include $(BUILD_SHARED_LIBRARY)
