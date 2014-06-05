#
# Makefile in source subdirectory
#

obj-m           += easycap.o

easycap-y       := easycap_main.o easycap_low.o easycap_sound.o
easycap-y       += easycap_ioctl.o easycap_settings.o
easycap-y       += easycap_testcard.o
easycap-y       += easycap_ioctlmess.o

ccflags-y += -Wall  -Wframe-larger-than=8192 -DEASYCAP_NEEDS_ALSA -DEASYCAP_NEEDS_CARD_CREATE -DEASYCAP_IS_VIDEODEV_CLIENT -DEASYCAP_NEEDS_V4L2_FOPS -DEASYCAP_NEEDS_UNLOCKED_IOCTL -DEASYCAP_NEEDS_V4L2_DEVICE_H

#KERNELDIR ?= /lib/modules/2.6.32-31-generic/build
#PWD       := $(shell pwd)

#all:
#	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

clean:
	@rm -rf *.o *~ core .depend .*.cmd *.ko *.mod.c .tmp_versions

