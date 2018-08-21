/*
 * =====================================================================================
 * @File        :  	mynetdevice.c 
 * @Brief       :   Sample network device driver program, which responds to the ARP requests.
 * @Author      :   Dinesh KB (dinesh.kb@vvdntech.in)
 * @Copyright   :   2018-2019 , VVDN Technologies Pvt. Ltd. Permission is
 *                  hereby granted to everyone in VVDN Technologies to use
 *                  the Software without restriction, including without
 *                  limitation the rights to use, copy, modify, merge,publish,
 *                  distribute, distribute with modifications.
 * =====================================================================================
 */

#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/netdevice.h>

/* Defined MACROS */
#define ETH_P_ARP 			0x0806
#define MAX_IPV4_LEN 		4
#define MAX_HW_ADDR_LEN 6
#define SUCCESS 				0
#define FAILURE 				-1

/* Structure for updating the statistics of the net device*/
struct pcpu_dstats {
  u64     rx_packets;
  u64     rx_bytes;
  u64     tx_packets;
  u64     tx_bytes;
  struct u64_stats_sync   syncp;	/* Need to know the use of this */
};

/* Device specific private structure 
 * This structure is optional and the contents purely depends on the implementation
 */
typedef struct my_device_specific_structure {
	unsigned int flags;
	unsigned int count;
}my_dev_struct_t;


/* ARP Header */
struct my_arphdr {
  __be16    ar_hrd;   /* format of hardware address */
  __be16    ar_pro;   /* format of protocol address */
  unsigned char ar_hln;   /* length of hardware address */
  unsigned char ar_pln;   /* length of protocol address */
  __be16    ar_op;    /* ARP opcode (command)   */
}; 

/* Complete ARP */
struct arp_payload {
	struct my_arphdr hdr;
	unsigned char sender_mac[MAX_HW_ADDR_LEN];
	unsigned char src_ip[MAX_IPV4_LEN];
	unsigned char target_mac[MAX_HW_ADDR_LEN];
	unsigned char dest_ip[MAX_IPV4_LEN];
};

/* Ethernet Header */
struct eth_hdr {
  u8	h_dest[6];  /* destination address */
  u8	h_src[6];  /* source address */
  __be16 h_proto;   /* packet type ID field */
};

/* Initialization of the net_device structure */
struct net_device *my_net = NULL;

/*
 * @Function name			:			my_transmit
 * @Brief							:			This function will be called during incoming requests.
 *													It snoops and replies only for the ARP requests and
 *													drops the other packets
 * @Parameter 1				:			Pointer to the socket buffer.
 * @Parameter 2				: 		Pointer to the net_device structure.
 */

static netdev_tx_t my_transmit(struct sk_buff *skb, struct net_device *dev)
{
	/* Updating the statistics */
	struct pcpu_dstats *dstats = this_cpu_ptr(dev->dstats);
	/* Synchronizing the stats update */
	u64_stats_update_begin(&dstats->syncp);
  dstats->rx_packets++;
  dstats->rx_bytes += skb->len;
  u64_stats_update_end(&dstats->syncp);
	
	printk("[%s:%d] Net device has received a packet\n", __func__, __LINE__);
	/* Checking the packet contents 
	 * This block of code will filter and respond ARP requests and drop other packets
	 */
	{
		struct eth_hdr hdr_buf;
		unsigned short ether_type = 0;
		/* Copying the contents of the ethernet header */
		memcpy(&hdr_buf, skb->data, sizeof(hdr_buf));
  	ether_type = hdr_buf.h_proto;
		skb_pull(skb, sizeof(hdr_buf));	
		printk("[%s:%d] Received the packet of type : 0x%x\n", __func__, __LINE__, ether_type);
		/* Verifying the packet is an ARP request */
		if (ether_type == htons(ETH_P_ARP)) {
			/* Copying the contents of the ARP main header */
    	struct my_arphdr *arp = (struct my_arphdr *)skb->data;
			/* Copying the data payload of the ARP request */
			unsigned char *pkt = (skb->data) + sizeof(struct my_arphdr);
			unsigned char offset = 0;
			unsigned char src_ip[MAX_IPV4_LEN] = "", dest_ip[MAX_IPV4_LEN] = "";
			unsigned char src_hwaddr[MAX_HW_ADDR_LEN] = "", dest_hwaddr[MAX_HW_ADDR_LEN] = "";

			/* Verifying the MAC address length is proper */
			if(arp->ar_hln > MAX_HW_ADDR_LEN){
				printk("[%s:%d] Invalid Hardware address of length %u\n",
											 __func__, __LINE__, arp->ar_hln);
				goto free;
			}
			/* Copying the src MAC Address of the packet */
			memcpy(src_hwaddr, pkt + offset, MAX_HW_ADDR_LEN);
			/* Incrementing offset to MAX_HW_ADDR_LEN */
			offset += MAX_HW_ADDR_LEN;
			printk("ARP : Sender mac : %02x:%02x:%02x:%02x:%02x:%02x\n", 
							src_hwaddr[0], src_hwaddr[1], src_hwaddr[2], src_hwaddr[3], src_hwaddr[4], src_hwaddr[5]);
			/* Verifying the IP length is proper */
			if(arp->ar_pln > MAX_IPV4_LEN){
				printk("[%s:%d] Invalid IP address of length %u\n", __func__, __LINE__, arp->ar_pln);
				goto free;
			}
			/* Copying src IP address */
			memcpy(src_ip, pkt + offset, MAX_IPV4_LEN);
			offset += MAX_IPV4_LEN;
			printk("ARP : Sender IP : %u.%u.%u.%u\n", src_ip[0], src_ip[1], src_ip[2], src_ip[3]);
			/* Copying Target MAC address */
			memcpy(dest_hwaddr, pkt + offset, MAX_HW_ADDR_LEN);
			offset += MAX_HW_ADDR_LEN;
			printk("ARP : Target mac : %02x:%02x:%02x:%02x:%02x:%02x\n", 
							dest_hwaddr[0], dest_hwaddr[1], dest_hwaddr[2], dest_hwaddr[3], dest_hwaddr[4], dest_hwaddr[5]);
			/* Copying Target IP address */	
			memcpy(dest_ip, pkt + offset, MAX_IPV4_LEN);
			offset += MAX_IPV4_LEN;
			printk("ARP : Target IP : %u.%u.%u.%u\n", dest_ip[0], dest_ip[1], dest_ip[2], dest_ip[3]);
			skb_pull(skb, sizeof(struct arp_payload));
			/* Response Block 
			 * This block responses for the ARP request.
			 */
			{
				struct arp_payload *payload = NULL;
				struct eth_hdr *eth_header = NULL;
				/* Allocating memory for the ARP payload in SKB */
				payload = (struct arp_payload *)skb_push(skb, sizeof(struct arp_payload));
				if(payload == NULL){
					printk("[%s:%d] Error in allocating memory for the payload\n", __func__, __LINE__);
					goto free;
				}
				/* Updating the opcode as reply */
				arp->ar_op = htons(2);
				/* Copying ARP header */
				memcpy(&payload->hdr, arp, sizeof(struct my_arphdr));
				/* Updating the sender_mac with device MAC address */	
				memcpy(payload->sender_mac, dev->dev_addr, MAX_HW_ADDR_LEN);
				/* Updating the target_mac with src MAC from recv. pkt */	
				memcpy(payload->target_mac, src_hwaddr, MAX_HW_ADDR_LEN);
				/* Updating the src IP with dest IP from recv. pkt */	
				memcpy(payload->src_ip, dest_ip, MAX_IPV4_LEN);
				/* Updating the dest IP  with src IP from recv. pkt */	
				memcpy(payload->dest_ip, src_ip, MAX_IPV4_LEN);
				/* Allocating memory for eth_header in SKB */	
				eth_header = (struct eth_hdr *)skb_push(skb, sizeof(struct eth_hdr));
				if(eth_header == NULL){
					printk("[%s:%d] Error in allocating memory for the payload\n", __func__, __LINE__);
					goto free;
				}
				/* Updating the source MAC with device MAC */
				memcpy(hdr_buf.h_src, dev->dev_addr, sizeof(dest_hwaddr)); 
				/* Updating the destination MAC with src MAC of received */
				memcpy(hdr_buf.h_dest, src_hwaddr, sizeof(src_hwaddr));
				/* Updating the ethernet header in SKB */
				memcpy(eth_header, &hdr_buf, sizeof(hdr_buf));
				goto success;
			}
		}
	}

free:
	/* Free the non ARP packets */
	printk("Freeing skb....\n");
	dev_kfree_skb(skb);
	return NETDEV_TX_OK;
success:
	/* Synchronizing the stats update */
	u64_stats_update_begin(&dstats->syncp);
  dstats->tx_packets++;
  dstats->tx_bytes += skb->len;
  u64_stats_update_end(&dstats->syncp);
	/* Updating the transmission start with jiffy info */
	dev->trans_start = jiffies;
	/* Updating the timestamp */
	skb_tx_timestamp(skb);
	/* Send the ARP response to the stack */
	netif_rx(skb);
	return NETDEV_TX_OK;
}

/*
 * @Function name			:			my_init
 * @Brief							:			This function will be called when the interface
 *													is initialized
 *													This function will allocate the stats structure
 * @Parameter 1				:			Pointer to the net_device structure.
 */

static int my_init(struct net_device *dev)
{
	/* Allocating stats structure */
	dev->dstats = netdev_alloc_pcpu_stats(struct pcpu_dstats);
	if(dev->dstats == NULL){
		printk("[%s:%d] Failure in allocating memory for pcpu stats\n", __func__, __LINE__);
		return FAILURE;
	}
	return SUCCESS;
}

/*
 * @Function name			:			my_uninit
 * @Brief							:			This function will be called when the interface
 *													is uninitialized.
 *													This function will free the allocated stats structure
 * @Parameter 1				:			Pointer to the net_device structure.
 */

static void my_uninit(struct net_device *dev)
{
	/* De allocating stats structure */
	printk("[%s:%d] De-allocating stats structure\n", __func__, __LINE__);
	free_percpu(dev->dstats);
	return;
}

/*
 * @Function name			:			my_open
 * @Brief							:			This function will be called when the interface
 *													is opened.
 *													This function will allocate the MAC address of the
 *													interface and selects the Tx queue.
 *													Allocate resources if any.
 * @Parameter 1				:			Pointer to the net_device structure.
 */

static int my_open(struct net_device *dev)
{
	/* Allocating MAC address for our device */
	dev->dev_addr[0] = 0x54;	
	dev->dev_addr[1] = 0x48;	
	dev->dev_addr[2] = 0x10;	
	dev->dev_addr[3] = 0xAF;	
	dev->dev_addr[4] = 0x26;	
	dev->dev_addr[5] = 0x16;
	printk("[%s:%d] Allocated mac address to our device\n", __func__, __LINE__);
	netif_start_queue(dev);

	return SUCCESS;
}

/*
 * @Function name			:			my_close
 * @Brief							:			This function will be called when the interface
 *													is closed.
 *													De-allocate resources if any.
 * @Parameter 1				:			Pointer to the net_device structure.
 */

static int my_close(struct net_device *dev)
{
	/* Releasing the resources */
	printk("[%s:%d] Releasing the resources\n", __func__, __LINE__);
	netif_stop_queue(dev);
	return SUCCESS;
}

/* Structure for netdevice operations */
static struct net_device_ops my_netdev_ops = {
	.ndo_init				=	 	my_init,
	.ndo_open				= 	my_open,
	.ndo_stop				= 	my_close,
	.ndo_uninit 		= 	my_uninit,
	.ndo_start_xmit = 	my_transmit
};

/*
 * @Function name			:			my_netdevice_setup
 * @Brief							:			This function will be called when the net device 
 *													got allocated, entries in the net device structure
 *													will get updated here.
 * @Parameter 1				:			Pointer to the net_device structure.
 */

void my_netdevice_setup(struct net_device *dev)
{
	/* Setting up net device with the ehternet specific entries */
	ether_setup(dev);
	/* Allocating appropriate operation structure */
	dev->netdev_ops = &my_netdev_ops;
	return;
}

/*
 * @Function name			:			my_netdevice_init
 * @Brief							:			This function will be called when the module
 *													is installed. 
 *													This function will allocate and register net device.
 */

static int my_netdevice_init(void)
{
	/* Allocate Net device structure */
	my_net = alloc_netdev(0, "vvdn_netdevice", NET_NAME_UNKNOWN, my_netdevice_setup);
	if(my_net == NULL){
		printk("Error in allocating net device\n");
		return FAILURE;
	}
	printk("[%s:%d] Net device is allocated successfully\n", __func__, __LINE__);
	/* Register Net device */
	if(register_netdev(my_net) < 0){
		printk("Error in registering the net device\n");
		return FAILURE;
	}
	return SUCCESS;
}

/*
 * @Function name			:			my_netdevice_exit
 * @Brief							:			This function will be called when the module
 *													is removed. 
 *													This function will de-register and free net device.
 */

static void my_netdevice_exit(void)
{
	/* Unregistering net device */
	unregister_netdev(my_net);
	/* Freeing the allocated net device */
	free_netdev(my_net);
}

module_init(my_netdevice_init);
module_exit(my_netdevice_exit);

/* Module information */
MODULE_LICENSE("GPL");
MODULE_AUTHOR("VVDN");
