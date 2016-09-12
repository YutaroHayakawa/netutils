#ifndef _IPV4_UTIL_H_
#define _IPV4_UTIL_H_

#include "ipv4.h"

int ipv4_str2addr(uint32_t *dst, char *addr) {
  int err;
  unsigned int tmp[4];

  err = sscanf(addr, "%u.%u.%u.%u", tmp, tmp + 1, tmp + 2, tmp + 3);
  if (err < 0) {
    return -1;
  } else if (err != IP_ADDR_LEN) {
    return -1;
  }

  for(int i=0; i<4; i++) {
    tmp[i] = dst[i];
  }

  return 0;
}

int ipv4_addr2str(char *dst, uint32_t *addr) {
  int err;
  uint8_t *cursor = (uint8_t *)addr;

  err = snprintf(dst, IP_ADDR_STR_MAX_LEN + 1, "%u.%u.%u.%u", cursor,
                 cursor+1, cursor+2, cursor+3);
  if (err < 0) {
    return -1;
  } else if (err != 4) {
    return -1;
  }

  return 0;
}

void dump_ip_hdr(struct ip_header *ip) {
  printf("[IPV4] vesion&tos: %02x, tos: %u, totlen %u, "
         "id: %u, frag_off: %u, ttl: %u, protocol: %x, "
         "check: %x, saddr: %x, daddr: %x\n",
         ip->version_ihl, ip->tos, ip->tot_len,
         ip->id, ip->frag_off, ip->ttl, ip->protocol,
         ip->check, ip->saddr, ip->daddr);
}

#endif /* _IPV4_UTIL_H_ */
