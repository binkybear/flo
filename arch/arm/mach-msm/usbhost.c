#include <linux/kobject.h>
#include <linux/sysfs.h>

extern void smb345_event_fi(void);
extern void smb345_event_fastcharge(void);
extern void snd_usb_audio_exec_delayed(unsigned long unused);	// /sound/usb/card.c
//extern void usbhost_suspend(void);  // msm_otg.c


// Copyright (C) 2013 Timur Mehrvarz

/* ----------------------------------------- */
int usbhost_fixed_install_mode;

static ssize_t fixed_install_mode_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
    return sprintf(buf, "%d\n", usbhost_fixed_install_mode);
}

static ssize_t fixed_install_mode_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count)
{
    sscanf(buf, "%d", &usbhost_fixed_install_mode);
    smb345_event_fi();
    return count;
}

static struct kobj_attribute fixed_install_mode_attribute = 
    __ATTR(usbhost_fixed_install_mode, 0666, fixed_install_mode_show, fixed_install_mode_store);

/* ----------------------------------------- */
int usbhost_fastcharge_in_host_mode;

static ssize_t fastcharge_in_host_mode_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
    return sprintf(buf, "%d\n", usbhost_fastcharge_in_host_mode);
}

static ssize_t fastcharge_in_host_mode_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count)
{
    sscanf(buf, "%d", &usbhost_fastcharge_in_host_mode);
    printk("usbhost %s usbhost_fastcharge_in_host_mode=%d\n", __func__,usbhost_fastcharge_in_host_mode);
    smb345_event_fastcharge();

    printk("usbhost %s snd_usb_audio_exec_delayed\n", __func__);
    snd_usb_audio_exec_delayed(0l);

    return count;
}

static struct kobj_attribute fastcharge_in_host_mode_attribute = 
    __ATTR(usbhost_fastcharge_in_host_mode, 0666, fastcharge_in_host_mode_show, fastcharge_in_host_mode_store);

/* ----------------------------------------- */
int usbhost_hotplug_on_boot;

static ssize_t hotplug_on_boot_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
    return sprintf(buf, "%d\n", usbhost_hotplug_on_boot);
}

static ssize_t hotplug_on_boot_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count)
{
    sscanf(buf, "%d", &usbhost_hotplug_on_boot);
    return count;
}

static struct kobj_attribute hotplug_on_boot_attribute = 
    __ATTR(usbhost_hotplug_on_boot, 0666, hotplug_on_boot_show, hotplug_on_boot_store);

/* ----------------------------------------- */
int usbhost_hostmode;

static ssize_t hostmode_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
    return sprintf(buf, "%d\n", usbhost_hostmode);
}

static ssize_t hostmode_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count)
{
    sscanf(buf, "%d", &usbhost_hostmode);
    printk("usbhost %s usbhost_hostmode=%d\n", __func__,usbhost_hostmode);
    return count;
}

static struct kobj_attribute hostmode_attribute = 
    __ATTR(usbhost_hostmode, 0666, hostmode_show, hostmode_store);

/* ----------------------------------------- */
volatile int usbhost_charging_state;

static ssize_t charging_state_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
    return sprintf(buf, "%d\n", usbhost_charging_state);
}

static ssize_t charging_state_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count)
{
    sscanf(buf, "%d", &usbhost_charging_state);
    return count;
}

static struct kobj_attribute charging_state_attribute = 
    __ATTR(usbhost_charging_state, 0666, charging_state_show, charging_state_store);

/* ----------------------------------------- */
volatile int usbhost_external_power;

static ssize_t external_power_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
    return sprintf(buf, "%d\n", usbhost_external_power);
}

static ssize_t external_power_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count)
{
    sscanf(buf, "%d", &usbhost_external_power);
    return count;
}

static struct kobj_attribute external_power_attribute = 
    __ATTR(usbhost_external_power, 0666, external_power_show, external_power_store);

/* ----------------------------------------- */
int usbhost_charge_slave_devices;

static ssize_t charge_slave_devices_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
    return sprintf(buf, "%d\n", usbhost_charge_slave_devices);
}

static ssize_t charge_slave_devices_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count)
{
    sscanf(buf, "%d", &usbhost_charge_slave_devices);
    return count;
}

static struct kobj_attribute charge_slave_devices_attribute = 
    __ATTR(usbhost_charge_slave_devices, 0666, charge_slave_devices_show, charge_slave_devices_store);

/* ----------------------------------------- */
int usbhost_lock_usbdisk;

static ssize_t lock_usbdisk_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
    return sprintf(buf, "%d\n", usbhost_lock_usbdisk);
}

static ssize_t lock_usbdisk_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count)
{
    sscanf(buf, "%d", &usbhost_lock_usbdisk);
    return count;
}

static struct kobj_attribute lock_usbdisk_attribute = 
    __ATTR(usbhost_lock_usbdisk, 0666, lock_usbdisk_show, lock_usbdisk_store);


/* ----------------------------------------- */
int usbhost_firm_sleep;

static ssize_t firm_sleep_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
    return sprintf(buf, "%d\n", usbhost_firm_sleep);
}

static ssize_t firm_sleep_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count)
{
    sscanf(buf, "%du", &usbhost_firm_sleep);
    printk("usbhost %s usbhost_firm_sleep=%d\n", __func__,usbhost_firm_sleep);
    return count;
}

static struct kobj_attribute firm_sleep_attribute = 
    __ATTR(usbhost_firm_sleep, 0666, firm_sleep_show, firm_sleep_store);


/* ----------------------------------------- */
volatile unsigned long  usbhost_wake_in_suspend_total_ms = 0;

static ssize_t wake_in_suspend_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
    printk("usbhost %s wake_in_suspend_total_ms=%lu\n", __func__,usbhost_wake_in_suspend_total_ms);
    return sprintf(buf, "%lu\n", usbhost_wake_in_suspend_total_ms);
}

static ssize_t wake_in_suspend_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count)
{
    sscanf(buf, "%lu", &usbhost_wake_in_suspend_total_ms);
    printk("usbhost %s wake_in_suspend_total_ms=%lu\n", __func__,usbhost_wake_in_suspend_total_ms);
    return count;
}

static struct kobj_attribute wake_in_suspend_attribute = 
    __ATTR(usbhost_wake_in_suspend_total_ms, 0666, wake_in_suspend_show, wake_in_suspend_store);


/* ----------------------------------------- */
int  usbhost_power_slaves = 1;

static ssize_t power_slaves_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
    printk("usbhost %s power_slaves=%d\n", __func__,usbhost_power_slaves);
    return sprintf(buf, "%d\n", usbhost_power_slaves);
}

static ssize_t power_slaves_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count)
{
    sscanf(buf, "%d", &usbhost_power_slaves);
    printk("usbhost %s power_slaves=%d\n", __func__,usbhost_power_slaves);
    return count;
}

static struct kobj_attribute power_slaves_attribute = 
    __ATTR(usbhost_power_slaves, 0666, power_slaves_show, power_slaves_store);



/* ----------------------------------------- */
static struct attribute *attrs[] = {
    &fixed_install_mode_attribute.attr,
    &hotplug_on_boot_attribute.attr,
    &fastcharge_in_host_mode_attribute.attr,
    &hostmode_attribute.attr,
    &charging_state_attribute.attr,
    &external_power_attribute.attr,
    &charge_slave_devices_attribute.attr,
    &lock_usbdisk_attribute.attr,
    &firm_sleep_attribute.attr,
    &wake_in_suspend_attribute.attr,
    &power_slaves_attribute.attr,
    NULL,
};

static struct attribute_group attr_group = {
    .attrs = attrs,
};

static struct kobject *usbhost_kobj;

int usbhost_init(void)
{
	int retval;

	// default values
	usbhost_fixed_install_mode = 1;
	usbhost_hotplug_on_boot = 0;
	usbhost_fastcharge_in_host_mode = 0;
    usbhost_charging_state = 0;
    usbhost_external_power = 0;
    usbhost_charge_slave_devices = 0;
    usbhost_lock_usbdisk = 0;
    usbhost_firm_sleep = 0;
    usbhost_wake_in_suspend_total_ms = 0l;
    usbhost_power_slaves = 1;

    printk("usbhost %s startup with FI=%d HP=%d FC=%d\n", __func__, usbhost_fixed_install_mode,
    	usbhost_hotplug_on_boot, usbhost_fastcharge_in_host_mode);

    usbhost_kobj = kobject_create_and_add("usbhost", kernel_kobj);
    if (!usbhost_kobj) {
            return -ENOMEM;
    }
    retval = sysfs_create_group(usbhost_kobj, &attr_group);
    if (retval)
            kobject_put(usbhost_kobj);
    return retval;
}

void usbhost_exit(void)
{
	kobject_put(usbhost_kobj);
}

module_init(usbhost_init);
module_exit(usbhost_exit);

