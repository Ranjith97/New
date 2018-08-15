/**
 * @file      : macaddr.c
 * @Brief     : This file contains the source code to print the MAC address
 *              of the device.
 * @Author    : Ranjith Kumar K V (ranjithkumatkv@vvdntech.in)
 * @Copyright : 2012-2013, VVDN Technologies Pvt. Ltd. Permission is hereby
 *              granted to everyone in VVDN Technologies to use the Software
 *              without restriction, including without limitation the rights to
 *              use, copy, modify, merge, publish, distribute, distribute with
 *              modifications.
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
 * @function    : my_init
 * @brief       : This function is used to insert device driver.
 */
static int __init my_init(void){
    if ((ret = alloc_chrdev_region(&first, FIRST_OF_RANGE, RANGE, "driver")) \
        < ERR_VAL){
        return ret;
    }
    dev = __dev_get_by_name(&init_net,"wlp6s0");
    printk("The MAC adress is : %pM\n", dev->dev_addr);
    return SUCCESS;
}
/*
 * @function    : my_exit
 * brief        : This function is used to remove the device driver.
 */
static void __exit my_exit(void){
    unregister_chrdev_region(first, MINOR_NUM);
    printk(KERN_INFO "Frist Driver Unloaded\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
