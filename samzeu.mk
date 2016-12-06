$(call inherit-product, device/linaro/pandaboard/pandaboard.mk)

DEVICE_PACKAGE_OVERLAYS := device/utbm/samzeu/overlay

PRODUCT_COPY_FILES += device/utbm/samzeu/system/media/bootanimation.zip:system/media/bootanimation.zip

PRODUCT_PACKAGES += libusb

PRODUCT_NAME:= samzeu
PRODUCT_DEVICE:= samzeu
PRODUCT_BRAND:= Android
PRODUCT_MODEL:= Android
