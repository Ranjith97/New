#include <linux/kernel.h>
#include<linux/if_arp.h>
#include <linux/etherdevice.h>
#include <linux/module.h>
#include <linux/netdevice.h>

struct net_device *virtualNIC;
int arp_open(struct net_device *dev) {
    printk("virtualNIC_open called\n");
    netif_start_queue(dev);
    return 0;
}

int arp_release(struct net_device *dev) {
    printk("virtualNIC_release called\n");
    netif_stop_queue(dev);
    return 0;
}

int arp_xmit(struct sk_buff *skb, struct net_device *dev) {
    int len;
    char *data, shortpkt[ETH_ZLEN];
//    struct sk_buff * kskb = NULL;
    //  int type = 0;
    printk("dummy xmit function called...\n");
    struct ethhdr *mh = NULL;
    mh = eth_hdr(skb);
    printk(KERN_EMERG "Source MAC=%x:%x:%x:%x:%x:%x\n",mh->h_source[0],mh->h_source[1],mh->h_source[2],mh->h_source[3],mh->h_source[4],mh->h_source[5]);
    printk(KERN_EMERG "dest MAC=%x:%x:%x:%x:%x:%x\n",mh->h_dest[0],mh->h_dest[1],mh->h_dest[2],mh->h_dest[3],mh->h_dest[4],mh->h_dest[5]);
    // memcpy(kskb,skb,sizeof(struct sk_buff));
    printk(KERN_ALERT"%d  %d\n",skb->len,skb->data_len);
    printk(KERN_ALERT"%d\n",skb->mac_len);
    data = skb->data;
    len = skb->len;
    skb->protocol = eth_type_trans(skb,dev);
    printk(KERN_ALERT"type %x\n",htons(skb->protocol));
    /*struct pcpu_dstats *dstats = this_cpu_ptr(dev->dstats);

    u64_stats_update_begin(&dstats->syncp);
    dstats->tx_packets++;
    dstats->tx_bytes += skb->len;
    u64_stats_update_end(&dstats->syncp);*/

    skb_pull(skb,sizeof(shortpkt));
    printk(KERN_EMERG "dest MAC=%x:%x:%x:%x:%x:%x\n",mh->h_dest[0],mh->h_dest[1],mh->h_dest[2],mh->h_dest[3],mh->h_dest[4],mh->h_dest[5]);
    memcpy(shortpkt, skb->data, sizeof(shortpkt));
    if (len < ETH_ZLEN) {
        memset(shortpkt, 0, ETH_ZLEN);
        memcpy(shortpkt, skb->data, skb->len);
        len = ETH_ZLEN;
        data = shortpkt;
    }
 //   dev->trans_start = jiffies; save the timestamp
        /*kskb = dev_alloc_skb(sizeof(struct sk_buff)+ 2);
          memcpy(skb_put(kskb, skb->data_len), skb->data, skb->data_len);
          Write metadata, and then pass to the receive level */
        /* dev->dev_addr[0] = 0x44;
           dev->dev_addr[1] = 0x03;
           dev->dev_addr[2] = 0x2c;
           dev->dev_addr[3] = 0xdf;
           dev->dev_addr[4] = 0xc6;
           dev->dev_addr[5] = 0x9f;
           kskb->dev = dev;
           kskb->protocol = eth_type_trans(kskb, dev);*/
        //kskb->ip_summed = CHECKSUM_UNNECESSARY; /* don't check it */
        //skb_push(kskb,sizeof(struct sk_buff));
        dev_kfree_skb(skb);
    return 0;
}

int arp_init(struct net_device *dev)
{
    printk("virtualNIC device initialized\n");
    /*  allocating pcpu states,dummy network device interface  */
    //	dev->dstats = netdev_alloc_pcpu_stats(struct pcpu_dstats);
    //	if (!dev->dstats)
    //		return -ENOMEM;

    return 0;
}

void arp_dev_uninit(struct net_device *dev)
{
    //	free_percpu(dev->dstats);
}

const struct net_device_ops my_netdev_ops = {
    .ndo_init = arp_init,
    .ndo_open = arp_open,
    .ndo_stop = arp_release,
    .ndo_start_xmit = arp_xmit
};
static void virtual_setup(struct net_device *dev){
    ether_setup(dev);
    dev->dev_addr[0] = 0x1;
    dev->dev_addr[1] = 0x2;
    dev->dev_addr[2] = 0x3;
    dev->dev_addr[3] = 0x4;
    dev->dev_addr[4] = 0x5;
    dev->dev_addr[5] = 0x6;
    dev->netdev_ops = &my_netdev_ops;
}
int arp_dev_init(void)
{

    virtualNIC = alloc_netdev(0,"vvdn_NIC%d",0,virtual_setup);
    register_netdev(virtualNIC);
    printk(KERN_ALERT"EXITING......\n");
    return 0;
}
void arp_dev_exit(void)
{
    unregister_netdev(virtualNIC);
    printk(KERN_ALERT"EXITING......\n");
}
module_init(arp_dev_init);
module_exit(arp_dev_exit);
MODULE_LICENSE("GPL");
