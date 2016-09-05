#ifndef _IPV4_H_
#define _IPV4_H_

#define IP_ADDR_LEN 4 // IPv4 address length(bytes)

/* Well known protocols */
#define IP_PROTO_ICMP 0x01
#define IP_PROTO_TCP 0x06
#define IP_PROTO_UDP 0x11

/* OS independent IPv4 header definition (C99) */
struct ip_header {
  uint8_t version_ihl;
  uint8_t tos;
  uint16_t tot_len;
  uint16_t id;
  uint16_t frag_off;
  uint8_t ttl;
  uint8_t protocol;
  uint16_t check;
  uint32_t saddr;
  uint32_t daddr;
};

#endif /* _IPV4_H_ */
