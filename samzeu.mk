$(call inherit-product, device/linaro/pandaboard/pandaboard.mk)

PRODUCT_LOCALES := en_US

DEVICE_PACKAGE_OVERLAYS := device/utbm/samzeu/overlay

PRODUCT_COPY_FILES += device/utbm/samzeu/system/media/bootanimation.zip:system/media/bootanimation.zip \
device/utbm/samzeu/frameworks/missileLibrary/fr.utbm.samzeu.missile.xml:system/etc/permissions/fr.utbm.samzeu.missile.xml \

PRODUCT_PACKAGES += libusb \
			mlbin \
			mlbin-jni \
			fr.utbm.samzeu.missile \	    	

PRODUCT_NAME:= samzeu
PRODUCT_DEVICE:= samzeu
PRODUCT_BRAND:= Android
PRODUCT_MODEL:= Android
