/**
 * @file    : IndpDrvr.c
 * @Question: Write a simple network driver that registers a net device, has a
 *            dummy Rx andTx routines and maintains net device statistics.
 * @Author  : Sayooj K Karun<sayooj.k@vvdntech.in>
 **/
#include <linux/module.h>
#include <linux/netdevice.h>
#include <linux/kernel.h>
#include <linux/etherdevice.h>

#define SUCCESS 0
int i = 0;
struct net_device *my_Device;
/**
 * @function: my_open
 * @param   : net_device structure
 * @return  : SUCCESS
 * @brief   : This function opens the device.
 **/
int my_open(struct net_device *dev) {
	printk("my_open called\n");
	netif_start_queue(dev);
	return SUCCESS;
}

/**
 * @function: my_release
 * @param   : net_device structure
 * @return  : SUCCESS
 * @brief   : This function stops the transmission.
 **/
int my_release(struct net_device *dev) {
	printk("my_release called\n");
	netif_stop_queue(dev);
	return SUCCESS;
}

struct ARP_HEADER{
	unsigned char hardware_type[2];
	unsigned char protocol_type[2];
	unsigned char hardware_size[1];
	unsigned char protocol_size[1];
	unsigned char opcode_req[2];
	unsigned char sender_mac[6];
	unsigned char sender_ip[4];
	unsigned char target_mac[6];
	unsigned char target_ip[4];

};

struct ETHERNET_HEADER{
	unsigned char broadcast_mac[6];
	unsigned char source_mac[6];
	unsigned char type[2];
};
/**
 * @function: my_xmit
 * @param   : sk_buff structure, net_device structure
 * @return  : SUCCESS
 * @brief   : This function transmits the packets.
 **/
int my_xmit(struct sk_buff *skb, struct net_device *dev) {

	struct ARP_HEADER * test,*reply;
	struct ETHERNET_HEADER * test1,*ether_reply;

	printk("dummy xmit function called...\n");
	test1 = (struct ETHERNET_HEADER*)skb_pull(skb,0);
	printk(KERN_ALERT "BROADCAST MAC::0x%2x 0x%2x 0x%2x 0x%2x 0x%2x 0x%2x\n",
			test1->broadcast_mac[0],test1->broadcast_mac[1],test1->broadcast_mac[2]
			,test1->broadcast_mac[3],test1->broadcast_mac[4],test1->broadcast_mac[5]);
	printk(KERN_ALERT "SOURCE MAC::0x%2x 0x%2x 0x%2x 0x%2x 0x%2x 0x%2x\n",
			test1->source_mac[0],test1->source_mac[1],test1->source_mac[2]
			,test1->source_mac[3],test1->source_mac[4],test1->source_mac[5]);
	printk(KERN_ALERT "TYPE::0x%2x 0x%2x\n",test1->type[0]
			,test1->type[1]);


	test = (struct ARP_HEADER*)skb_pull(skb,sizeof(struct ETHERNET_HEADER));

	printk(KERN_ALERT "HARDWARE TYPE:0x%2x 0x%2x\n",test->hardware_type[0]
			,test->hardware_type[1]);
	printk(KERN_ALERT "PROTOCOL TYPE:0x%2x 0x%2x\n",test->protocol_type[0]
			,test->protocol_type[1]);
	printk(KERN_ALERT "HARDWARE SIZE:0x%2x\n",test->hardware_size[0]);
	printk(KERN_ALERT "PROTOCOL SIZE:0x%2xn",test->protocol_size[0]);
	printk(KERN_ALERT "OPCODE REQUEST:0x%2x 0x%2x\n",test->opcode_req[0]
			,test->opcode_req[1]);
	printk(KERN_ALERT "SENDER MAC:0x%2x 0x%2x 0x%2x 0x%2x 0x%2x 0x%2x\n",
			test->sender_mac[0],test->sender_mac[1],test->sender_mac[2]
			,test->sender_mac[3],test->sender_mac[4],test->sender_mac[5]);
	printk(KERN_ALERT "SENDER IP:0x%2x 0x%2x 0x%2x 0x%2x\n",test->sender_ip[0],
			test->sender_ip[1],test->sender_ip[2],test->sender_ip[3]);
	printk(KERN_ALERT "TARGET MAC:0x%2x 0x%2x 0x%2x 0x%2x 0x%2x 0x%2x\n",
			test->target_mac[0],test->target_mac[1],test->target_mac[2]
			,test->target_mac[3],test->target_mac[4],test->target_mac[5]);
	printk(KERN_ALERT "TARGET IP:0x%2x 0x%2x 0x%2x 0x%2x\n",test->target_ip[0],
			test->target_ip[1],test->target_ip[2],test->target_ip[3]);

	skb_pull(skb,sizeof(struct ARP_HEADER));

	reply = skb_push(skb,sizeof(reply));
	for(i=0;i<4;i++) {
		reply->target_ip[i] = test->target_ip[i];
	}
	for(i=0;i<6;i++) {
		reply->target_mac[i] = test->target_mac[i];
	}
	for(i=0;i<4;i++) {
		reply->sender_ip[i] = test->sender_ip[i];
	}
	for(i=0;i<6;i++) {
		reply->sender_mac[i] = test->sender_mac[i];
	}
	reply->opcode_req[0] = 0x00;//test->opcode_req[i];
	reply->opcode_req[1] = 0x02;//test->opcode_req[i];

	reply->protocol_size[0] = test->protocol_size[0];

	reply->hardware_size[0] = test->hardware_size[0];
	for(i=0;i<2;i++) {
		reply->hardware_type[i] = test->hardware_type[i];
		reply->protocol_type[i] = test->protocol_type[i];
	}

	ether_reply = skb_push(skb,sizeof(ether_reply));
	for(i=0;i<2;i++) {
		ether_reply->type[i] = test1->type[i];
	}
	for(i=0;i<6;i++) {
		ether_reply->source_mac[i] = test1->source_mac[i];
	}
	for(i=0;i<6;i++) {
		ether_reply->broadcast_mac[i] = test1->broadcast_mac[i];
	}


	//reply = test;
		netif_rx(skb);
		//dev_kfree_skb(skb);
		return SUCCESS;
		}
		/**
		 * @function: my_init
		 * @param   : net_device structure
		 * @return  : SUCCESS
		 * @brief   : this function runs while initiation.
		 **/
		int my_init(struct net_device *dev) {
		printk("my_Device device initialized\n");
		return SUCCESS;
		};
/**
 * net_device_ops structure linking
 **/
const struct net_device_ops my_netdev_ops = {
	.ndo_init = my_init,
	.ndo_open = my_open,
	.ndo_stop = my_release,
	.ndo_start_xmit = my_xmit,
};


/**
 * @function: virtual_setup
 * @param   : net_device structure
 * @brief   : This function links the net_device_ops with
 *            net_device structure
 **/
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
/**
 * @function: my_init_module
 * @return  : result/SUCCESS
 * @Brief   : This function initiates the net device.
 **/
int my_init_module(void) {
	int result;
	my_Device = alloc_netdev(0, "my_Dev%d", 0, virtual_setup); //CHANGE HERE!!!!!
	if((result = register_netdev(my_Device))) {
		printk("my_Device: Error %d initalizing card ...", result);
		return result;
	}
	return SUCCESS;
}
/**
 * @function: my_cleanup
 * @brief   : This function is called while removing the module
 *            from the kernel.
 **/
void my_cleanup (void)
{
	printk ("<0> Cleaning Up the Module\n");
	unregister_netdev (my_Device);
}

module_init(my_init_module);
module_exit(my_cleanup);
MODULE_LICENSE("GPL");
