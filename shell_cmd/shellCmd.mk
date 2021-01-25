#########################################################################
#
#                       Nathan custom
#
# 1 hidl related
######################################################################### 

BOARD_VENDOR_SEPOLICY_DIRS += vendor/nathan/shell_cmd/sepolicy
#for hidl settings	
#DEVICE_FRAMEWORK_COMPATIBILITY_MATRIX_FILE += vendor/nathan/hidl/device_framework_matrix_cmd.xml	
#DEVICE_MATRIX_FILE += vendor/nathan/shell_cmd/compatibility_matrix_cmd.xml

PRODUCT_PACKAGES += \
	libhistbcmdservice_jni \
	libhistbcmdservicemanageclient \
	libstbcmdservicehal \
	hishellcmd
	
# treble hwstbcmdservice
PRODUCT_PACKAGES += \
    vendor.nathan.hwstbcmdservice@1.0 \
    vendor.nathan.hwstbcmdservice@1.0-impl \
    vendor.nathan.hwstbcmdservice@1.0-service	
