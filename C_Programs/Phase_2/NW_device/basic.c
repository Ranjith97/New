#include <linux/module.h>
#include <linux/netdevice.h>
#include <linux/kernel.h>
#include <linux/etherdevice.h>

struct net_device *virtualNIC;
unsigned char mac[6];

int virtualNIC_open(struct net_device *dev) {
    printk("virtualNIC_open called\n");
    netif_start_queue(dev);
    return 0;
}

int virtualNIC_release(struct net_device *dev) {
    printk("virtualNIC_release called\n");
    netif_stop_queue(dev);
    return 0;
}
struct arp_header {
    unsigned char hwdtype[1];
    unsigned char prototype[2];
    unsigned char hwdsize[1];
    unsigned char protosize[1];
    unsigned char opcode[1];
    unsigned char smac[6];
    unsigned char sip[4];
    unsigned char dmac[6];
    unsigned char dip[4];
};
struct eth_header {
    unsigned char destmac[6];
    unsigned char sourcemac[6];
    unsigned char type[1];
}
int virtualNIC_xmit(struct sk_buff *skb, struct net_device *dev) {
    struct arp_header *req, *rep;
    struct eth_header *req1, *rep1;

    req1 = (struct eth_header*) skb_pull(skb,0);
    if (req1->type ==  )
    if ()
    memcpy(mac, sourcemac, 6);

    dev_kfree_skb(skb);
    return 0;
}

int virtualNIC_init(struct net_device *dev) {
    printk("virtualNIC device initialized\n");
    return 0;
}
void virtualNIC_uninit(struct net_device *dev) {
    printk("virtualNIC device uninitialized\n");
}
const struct net_device_ops my_netdev_ops = {
    .ndo_init = virtualNIC_init,
    .ndo_uninit = virtualNIC_uninit,
    .ndo_open = virtualNIC_open,
    .ndo_stop = virtualNIC_release,
    .ndo_start_xmit = virtualNIC_xmit,
};

static void virtual_setup(struct net_device *dev){
    ether_setup(dev);
    dev->dev_addr[0] = 0x10;
    dev->dev_addr[1] = 0x11;
    dev->dev_addr[2] = 0x12;
    dev->dev_addr[3] = 0x13;
    dev->dev_addr[4] = 0x14;
    dev->dev_addr[5] = 0x15;
    dev->netdev_ops = &my_netdev_ops;
}

int virtualNIC_init_module(void) {
    int result;
    virtualNIC = alloc_netdev(0, "my_dev",0,virtual_setup);
    if((result = register_netdev(virtualNIC))) {
        printk("virtualNIC: Error %d initalizing card ...", result);
        return result;
    }
    return 0;
}

void virtualNIC_cleanup (void)
{
    printk ("<0> Cleaning Up the Module\n");
    unregister_netdev (virtualNIC);
}

module_init(virtualNIC_init_module);
module_exit(virtualNIC_cleanup);
MODULE_LICENSE("GPL");
