#ifndef _IPV4_H_
#define _IPV4_H_

int ipv4_str2addr(uint32_t *dst, char *addr) {
  int err;
  uint8_t tmp[4];

  err = sscanf(addr, "%u.%u.%u.%u",
      tmp, tmp+1, tmp+2, tmp+3);
  if(err < 0) {
    return -1;
  }else if(err != IP_ADDR_LEN) {
    return -1;
  }

  memcpy(dst, tmp, 32);

  return 0;
}

int ipv4_addr2str(char *dst, uint32_t *addr) {
  int err;
  uint8_t cursor = (uint8_t *)addr;

  err = snprintf(dst, IPV4_ADDR_STR_MAX_LEN + 1, "%u.%u.%u.%u",
      cursor[0], cursor[1], cursor[2], cursor[3]);
  if(err < 0) {
    return -1;
  }else if(err != 4) {
    return -1;
  }

  return 0;
}

#endif /* _IPV4_H_ */
