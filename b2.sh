export ARCH=arm
export SUBARCH=arm
export CROSS_COMPILE=arm-eabi-
sed 's/usbhost_fixed_install_mode = 0;/usbhost_fixed_install_mode = 1;/' arch/arm/mach-msm/usbhost.c > usbhost.c && cp usbhost.c arch/arm/mach-msm/usbhost.c
#export KBUILD_BUILD_USER=Timur-USBhost-FI-Beta-$1_`date "+20%y-%m-%d_%H:%M:%S"` && echo $KBUILD_BUILD_USER && rm -rf /tmp/targetfiles* && time make -j6 && cp arch/arm/boot/zImage ../jb442/device/asus/flo-kernel/kernel
export KBUILD_BUILD_USER=Timur-USBhost-FI-$1_`date "+20%y-%m-%d_%H:%M:%S"` && echo $KBUILD_BUILD_USER && rm -rf /tmp/targetfiles* && time make -j6 && cp arch/arm/boot/zImage ../jb443/device/asus/flo-kernel/kernel

