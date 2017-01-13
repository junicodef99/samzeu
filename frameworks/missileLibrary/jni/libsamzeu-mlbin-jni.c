#include <jni.h>
#include <stdio.h>
#include <stdlib.h>


#include <libusb.h>
#include <android/log.h>

#define ML_VENDOR_ID			0x0416
#define ML_DEVICE_ID			0x9391

#define ML_ACTION_FIRE			0x10
#define ML_ACTION_MOVE_DOWN		0x1
#define ML_ACTION_MOVE_LEFT		0x8
#define ML_ACTION_MOVE_RIGHT		0x4
#define ML_ACTION_MOVE_UP		0x2
#define ML_ACTION_STOP			0x0

#define LOGI(TAG,...) __android_log_print(ANDROID_LOG_INFO   , TAG,__VA_ARGS__)

static struct libusb_device_handle *devh;


JNIEXPORT jint JNICALL Java_fr_utbm_samzeu_missile_Missile_mlbinInitUsb(JNIEnv *env, jobject obj)
{
	libusb_device **list;
	libusb_device *device = NULL;
	int count, ret, i;
		//system.out.println("mlbin exiting\n");
	ret = libusb_init(NULL);

	if(ret < 0) {
		//system.out.println("Couldn't initialize libusb.\n");
		goto error;
	}

	count = libusb_get_device_list(NULL, &list);
	if (count < 0) {
		//system.out.println("Couldn't get device list\n");
		goto list_error;
	}

	for (i = 0; i < count; i++) {
		struct libusb_device_descriptor desc;
		device = list[i];
		libusb_get_device_descriptor(device, &desc);
		//system.out.println("Found a new device : %x:%x\n",desc.idVendor, desc.idProduct);
		if (desc.idVendor == ML_VENDOR_ID &&
			desc.idProduct == ML_DEVICE_ID)
			break;
		device = NULL;
	}

	if (!device) {
		//LOGI("Couldn't find the device\n");
		goto not_found_error;
	}

	ret = libusb_open(device, &devh);
	if (ret) {
		//system.out.println("Couldn't open device: %d\n", ret);
		goto open_dev_error;
	}

	libusb_detach_kernel_driver(devh, 0);
	ret = libusb_claim_interface(devh, 0);
	if(ret < 0) {
	//system.out.println("Couldn't claim the interface : %d.\n", ret);
		goto if_error;
	}

	libusb_free_device_list(list, count);
	//system.out.println("Interface setup.\n");
	return 0;

if_error:
	libusb_close(devh);
detach_error:
open_dev_error:
not_found_error:
	libusb_free_device_list(list, count);
list_error:
	libusb_exit(NULL);
error:
	exit(1);
}

JNIEXPORT jint JNICALL Java_fr_utbm_samzeu_missile_Missile_mlbinFreeUsb(JNIEnv *env, jobject obj)
{
	libusb_release_interface(devh, 0);
	libusb_close(devh);
	libusb_exit(NULL);
	//system.out.println("mlbin exiting\n");
	return 0;
}

JNIEXPORT jint JNICALL Java_fr_utbm_samzeu_missile_Missile_mlbinFire(JNIEnv *env, jobject obj)
{
	unsigned char data[] = {0x5f, ML_ACTION_FIRE, 0xe0, 0xff, 0xfe};
	libusb_control_transfer(devh, 0x21, 0x09, 0, 0, data, 5, 300);
	//system.out.println("Fire!\n");
	return 0;
}

JNIEXPORT jint JNICALL Java_fr_utbm_samzeu_missile_Missile_mlbinMoveDown(JNIEnv *env, jobject obj)
{
	unsigned char data[] = {0x5f, ML_ACTION_MOVE_DOWN, 0xe0, 0xff, 0xfe};
	libusb_control_transfer(devh, 0x21, 0x09, 0, 0, data, 5, 300);
	//system.out.println("Move Down!\n");
	return 0;
}

JNIEXPORT jint JNICALL Java_fr_utbm_samzeu_missile_Missile_mlbinMoveLeft(JNIEnv *env, jobject obj)
{
	unsigned char data[] = {0x5f, ML_ACTION_MOVE_LEFT, 0xe0, 0xff, 0xfe};
	libusb_control_transfer(devh, 0x21, 0x09, 0, 0, data, 5, 300);
	//system.out.println("Move Left!\n");
	return 0;
}

JNIEXPORT jint JNICALL Java_fr_utbm_samzeu_missile_Missile_mlbinMoveRight(JNIEnv *env, jobject obj)
{
	unsigned char data[] = {0x5f, ML_ACTION_MOVE_RIGHT, 0xe0, 0xff, 0xfe};
	libusb_control_transfer(devh, 0x21, 0x09, 0, 0, data, 5, 300);
	//system.out.println("Move Right!\n");
	return 0;
}

JNIEXPORT jint JNICALL Java_fr_utbm_samzeu_missile_Missile_mlbinMoveUp(JNIEnv *env, jobject obj)
{
	unsigned char data[] = {0x5f, ML_ACTION_MOVE_UP, 0xe0, 0xff, 0xfe};
	libusb_control_transfer(devh, 0x21, 0x09, 0, 0, data, 5, 300);
	//system.out.println("Move Up!\n");
	return 0;
}

JNIEXPORT jint JNICALL Java_fr_utbm_samzeu_missile_Missile_mlbinStop(JNIEnv *env, jobject obj)
{
	unsigned char data[] = {0x5f, ML_ACTION_STOP, 0xe0, 0xff, 0xfe};
	libusb_control_transfer(devh, 0x21, 0x09, 0, 0, data, 5, 300);
  	//system.out.println("Stop!\n");
	return 0;
}
