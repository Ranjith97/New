/**
 * @file      : macaddr.c
 * @Brief     : This file contains the source code to print the MAC address
 *              of the device.
 * @Author    : Sayooj K Karun <sayooj.k@vvdntech.in>
 * @Copyright : (c) 2017 , VVDN Technologies Pvt. Ltd.
 *              Permission is hereby granted to everyone in VVDN Technologies
 *              to use the Software without restriction, including without
 *              limitation the rights to use, copy, modify, merge, publish,
 *              distribute, distribute with modifications.
 **/

#include <linux/module.h>
#include <linux/netdevice.h>
#include <net/net_namespace.h>

#define FIRST_OF_RANGE  0
#define RANGE           3
#define ERR_VAL         0
#define SUCCESS         0
#define MINOR_NUM       1

/* Global variable for device number */
static dev_t first;
int ret;
struct net_device *dev;

/*
 * @function    : __init firstDrivr_init
 * @return      : ret/SUCCESS
 * @brief       : This function is used to register the character device driver.
 */
static int __init firstDrivr_init(void){
    if ((ret = alloc_chrdev_region(&first, FIRST_OF_RANGE, RANGE, "driver")) \
        < ERR_VAL){
        return ret;
    }
    dev = __dev_get_by_name(&init_net,"eth0");
    printk("The MAC adress is : %pM\n", dev->dev_addr);
    return SUCCESS;
}
/*
 * @function    : __exit dirstDrivr_exit
 * brief        : This function is used to unregister the character device driver.
 */
static void __exit firstDrivr_exit(void){
    unregister_chrdev_region(first, MINOR_NUM);
    printk(KERN_INFO "Frist Driver Unloaded\n");
}

module_init(firstDrivr_init);
module_exit(firstDrivr_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sayooj K Karun <sayooj.k@vvdntech.in>");
MODULE_DESCRIPTION("Finds MAC address");
