#ifndef _ETH_UTIL_H_
#define _ETH_UTIL_H_

#include <stdio.h>  // sscanf sprintf

#include "ethernet.h"

int eth_str2addr(uint8_t *dst, char *addr) {
  int err;
  unsigned int tmp[ETH_ADDR_LEN];

  err = sscanf(addr, "%02x:%02x:%02x:%02x:%02x:%02x", tmp, tmp + 1, tmp + 2,
               tmp + 3, tmp + 4, tmp + 5);
  if (err == EOF) {
    return -1;
  }

  for (int i = 0; i < ETH_ADDR_LEN; i++) {
    dst[i] = (uint8_t)tmp[i];
  }

  return 0;
}

int eth_addr2str(char *dst, uint8_t *addr) {
  int err;

  err = snprintf(dst, ETH_ADDR_STR_MAX_LEN + 1, "%02x:%02x:%02x:%02x:%02x:%02x",
                 addr[0], addr[1], addr[2], addr[3], addr[4], addr[5]);
  if (err < 0) {
    return -1;
  }

  return 0;
}

int dump_eth_hdr(struct eth_header *eth) {
  char saddr[ETH_ADDR_STR_MAX_LEN + 1];
  char daddr[ETH_ADDR_STR_MAX_LEN + 1];
  int err;

  err = eth_addr2str(saddr, eth->smac);
  if (err < 0) {
    return -1;
  }

  eth_addr2str(daddr, eth->dmac);
  if (err < 0) {
    return -1;
  }

  printf("[Ethernet] saddr:%s, daddr:%s, type:%x\n", saddr, daddr, eth->type);
}

#endif /* _ETH_UTIL_H_ */
