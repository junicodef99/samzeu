commonsources := core.c \
		 descriptor.c \
		 io.c \
		 sync.c \
		 os/threads_posix.c \
		 os/linux_usbfs.c \
LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_SRC_FILES := $(commonsources)
LOCAL_C_INCLUDES += $(LOCAL_PATH)
LOCAL_C_INCLUDES += $(LOCAL_PATH)/os
LOCAL_MODULE := libusb
LOCAL_MODULE_TAGS := optional
include $(BUILD_SHARED_LIBRARY)
