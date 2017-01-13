LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := mlbin.c

LOCAL_C_INCLUDES += 	$(LOCAL_PATH)/../libusb-1.0.3/libusb
LOCAL_SHARED_LIBRARIES := libusb
LOCAL_MODULE := mlbin
LOCAL_MODULE_TAGS := optional

LOCAL_PRELINK_MODULE := false

include $(BUILD_EXECUTABLE)
