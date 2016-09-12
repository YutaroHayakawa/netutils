#ifndef _ETHERNET_H_
#define _ETHERNET_H_

#define ETH_ADDR_LEN 6           // Address length
#define ETH_ADDR_STR_MAX_LEN 17  // Address string length. Not including '\0'.

/* Well known ethernet types */
#define ETH_T_IPV4 0x0800
#define ETH_T_ARP 0x0806
#define ETH_T_IPV6 0x86dd

/* OS independent ethernet header definition (C99) */
struct eth_header {
  uint8_t smac[ETH_ADDR_LEN];
  uint8_t dmac[ETH_ADDR_LEN];
  uint16_t type;
};

#endif /* _ETHERNET_H_ */
