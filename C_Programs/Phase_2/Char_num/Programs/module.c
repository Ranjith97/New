/**
 * @file            : module.c
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

static int my_open(struct inode *i, struct file *f)
{
    printk(KERN_INFO "Driver open\n");
    return SUCCESS;
}
static int my_release(struct inode *i, struct file *f)
{
    printk(KERN_INFO "Driver close\n");
    return SUCCESS;
}
static ssize_t my_read(struct file *f, char __user *buf, size_t len, \
        loff_t *off)
{
    sprintf(message, "sum=%d sub=%d product=%d div=%d", add, sub, mul, div);
    if (copy_to_user(buf, message, sizeof(message)) == SUCCESS) {
        printk(KERN_INFO "The result has been sent.\n");
        return SUCCESS;
    }
    else {
        return FALSE;
    }
}
static ssize_t my_write(struct file *f, const char __user *buf, size_t len, \
        loff_t *off)
{
    sscanf(buf, "%d %d", &num1, &num2);
    add = num1 + num2;
    sub = num1 - num2;
    mul = num1 * num2;
    div = num1 / num2;
    return SUCCESS;
}

static struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = my_open,
    .release = my_release,
    .read = my_read,
    .write = my_write
};

static int __init my_init(void)
{
    if ((alloc_chrdev_region(&first, FST_MINOR, MINOR_RANGE, "drvalloc")) \
            < ERR) {
        printk(KERN_INFO "Allocation of char driver failed.\n");
        return FALSE;
    }
    cdev_init(&c_dev, &fops);
    c_dev.owner = THIS_MODULE;
    c_dev.ops = &fops;
    if ((cdev_add(&c_dev, first, MINOR_RANGE)) < ERR) {
        printk(KERN_INFO "Device addition error.\n");
        device_destroy(cl, first);
        class_destroy(cl);
        unregister_chrdev_region(first, MINOR_RANGE);
        return FALSE;
    }
    if ((cl = class_create(THIS_MODULE, "Chardriverclass")) == NULL) {
        printk(KERN_INFO "Chardriverclass error.\n");
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

static void __exit my_exit(void)
{
    cdev_del(&c_dev);
    device_destroy(cl, first);
    class_destroy(cl);
    unregister_chrdev_region(first, MINOR_RANGE);
}

MODULE_LICENSE("GPL");

module_init(my_init);
module_exit(my_exit);
