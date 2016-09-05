#ifndef _ETH_UTIL_H_
#define _ETH_UTIL_H_

#include <stdio.h> // sscanf sprintf

#include "ethernet.h"

int eth_str2addr(uint8_t *dst, char *addr) {
  int err;

  err = sscanf(addr, "%02x:%02x:%02x:%02x:%02x:%02x",
      dst[0], dst[1], dst[2], dst[3], dst[4], dst[5]);
  if(err == EOF) {
    return -1;
  }

  return 0;
}

int eth_addr2str(char *dst, uint8_t *addr) {
  int err;

  err = snprintf(dst, ETH_ADDR_STR_MAX_LEN + 1, "%02x:%02x:%02x:%02x:%02x:%02x",
      addr[0], addr[1], addr[2], addr[3], addr[4], addr[5]);
  if(err < 0) {
    return -1;
  }

  return 0;
}

#endif /* _ETH_UTIL_H_ */
