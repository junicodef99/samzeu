LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
            $(call all-subdir-java-files)

LOCAL_MODULE_TAGS := optional

LOCAL_MODULE:= fr.utbm.samzeu.missile

include $(BUILD_JAVA_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SRC_FILES := \
		$(call all-c-files-under, jni)
LOCAL_C_INCLUDES += \
		$(JNI_H_INCLUDE )\
	   	device/utbm/samzeu/libusb-1.0.3/libusb/ \
		device/utbm/samzeu/libusb-1.0.3/libusb/os

LOCAL_SHARED_LIBRARIES := libusb libcutils libutils

LOCAL_MODULE := mlbin-jni
LOCAL_MODULE_TAGS := optional
LOCAL_PRELINK_MODULE := false
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE := fr.utbm.samzeu.missile.xml
LOCAL_MODULE_CLASS := ETC
LOCAL_MODULE_PATH := $(TARGET_OUT_ETC)/permissions
LOCAL_SRC_FILES := $(LOCAL_MODULE)
include $(BUILD_PREBUILT)
