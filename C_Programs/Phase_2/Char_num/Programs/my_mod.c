/**
 * @file            : my_mod.c
 * @brief           : This module will do the arithmetic operations in the
 *                    kernel level
 * @author          : Ranjith Kumar K V (ranjithkumatkv@vvdntech.in)
 * @Copyright(c)    : 2012-2013 , VVDN Technologies Pvt. Ltd. Permission is
 *                    hereby granted to everyone in VVDN Technologies to use
 *                    the Software without restriction, including without
 *                    limitation the rights to use, copy, modify, merge,
 *                    publish, distribute, distribute with modifications.
 */

#include <linux/module.h>
#include <linux/version.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/init.h>
#include <linux/uaccess.h>
#include <linux/mutex.h>

#define FST_MINOR 0
#define MINOR_RANGE 1
#define SUCCESS 0
#define FALSE -1
#define BUF_SIZE 100
#define ERR 0

int num1 = 0, num2 = 0, add = 0, sub = 0, mul = 0, div = 0;
char message[BUF_SIZE];
static dev_t first;
static struct class *cl;
static struct cdev c_dev;
static DEFINE_MUTEX(mut_lock);

/**
 * @function    : my_open
 * @param1      : inode structure pointer
 * @param2      : file structure pointer
 * @Brief       : This function opens the Device file.
 */
static int my_open(struct inode *i, struct file *f)
{
    if (!mutex_trylock(&mut_lock)) {
        printk(KERN_ALERT "Driver busy.\n");
        return -EBUSY;
    }
    printk(KERN_ALERT "Driver open\n");
    return SUCCESS;
}

/**
 * @function    : my_release
 * @param1      : inode structure pointer
 * @param2      : file structure pointer
 * @Brief       : This function closes the device file.
 */
static int my_release(struct inode *i, struct file *f)
{
    mutex_unlock(&mut_lock);
    printk(KERN_ALERT "Driver close\n");
    return SUCCESS;
}

/**
 * @function    : my read
 * @param1      : file structure pointer
 * @param2      : character buffer
 * @param3      : length of buffer
 * @param4      : offset of file
 * @brief       : This function sends data from kernel space to user space.
 */
static ssize_t my_read(struct file *f, char __user *buf, size_t len, \
        loff_t *off)
{
    sprintf(message, "sum=%d sub=%d product=%d div=%d", add, sub, mul, div);
    if (copy_to_user(buf, message, sizeof(message)) == SUCCESS) {
        printk(KERN_ALERT "The result has been sent.\n");
        memset(message, '\0', sizeof(message));
        return SUCCESS;
    }
    else {
        memset(message, '\0', sizeof(message));
        return FALSE;
    }
}

/**
 * @function    : my_write
 * @param1      : file structure pointer
 * @param2      : character buffer
 * @param3      : length of buffer
 * @param4      : offset of file
 * @brief       : This function receives data from user to kernel level.
 */
static ssize_t my_write(struct file *f, const char __user *buf, size_t len, \
        loff_t *off)
{
    copy_from_user(message, buf, sizeof(buf));
    sscanf(message, "%d %d", &num1, &num2);
    add = num1 + num2;
    sub = num1 - num2;
    mul = num1 * num2;
    div = num1 / num2;
    memset(message, '\0', sizeof(message));
    return SUCCESS;
}

/* File operations structure */
static struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = my_open,
    .release = my_release,
    .read = my_read,
    .write = my_write
};

/**
 * @function    : my_init
 * @brief       : This function initiates the character device driver.
 */
static int __init my_init(void)
{
    mutex_init(&mut_lock);
    if ((alloc_chrdev_region(&first, FST_MINOR, MINOR_RANGE, "drvalloc")) \
            < ERR) {
        printk(KERN_ALERT "Allocation of char driver failed.\n");
        return FALSE;
    }
    cdev_init(&c_dev, &fops);
    c_dev.owner = THIS_MODULE;
    c_dev.ops = &fops;
    if ((cdev_add(&c_dev, first, MINOR_RANGE)) < ERR) {
        printk(KERN_ALERT "Device addition error.\n");
        device_destroy(cl, first);
        class_destroy(cl);
        unregister_chrdev_region(first, MINOR_RANGE);
        return FALSE;
    }
    if ((cl = class_create(THIS_MODULE, "Chardriverclass")) == NULL) {
        printk(KERN_ALERT "Chardriverclass error.\n");
        unregister_chrdev_region(first, MINOR_RANGE);
        return FALSE;
    }
    if ((device_create(cl, NULL, first, NULL, "mydriver")) == NULL) {
        printk(KERN_INFO "Device creation error.\n");
        class_destroy(cl);
        unregister_chrdev_region(first, MINOR_RANGE);
        return FALSE;
    }

    return SUCCESS;
}

/**
 * @function    : my_exit
 * @Brief       : This function is the destructor for the driver.
 */
static void __exit my_exit(void)
{
    cdev_del(&c_dev);
    device_destroy(cl, first);
    class_destroy(cl);
    unregister_chrdev_region(first, MINOR_RANGE);
    mutex_destroy(&mut_lock);
}

MODULE_LICENSE("GPL");

module_init(my_init);
module_exit(my_exit);
