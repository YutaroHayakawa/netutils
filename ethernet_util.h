#ifndef _ETHERNET_UTIL_H_
#define _ETHERNET_UTIL_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <net/if.h>
#include <net/if_dl.h>
#include <net/ethernet.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>
#include <ifaddrs.h>

/*
 * Format for printing out Ethernet Address
 */
#define FORMAT_ETH_ADDR "%02x:%02x:%02x:%02x:%02x:%02x"

/*
 * 6 octets of Ethernet address.
 * ethaddr: struct eth_addr*
 */
#define ETH_ADDR_OCTETS(ethaddrp) \
    (ethaddrp)->octet[0], (ethaddrp)->octet[1], (ethaddrp)->octet[2], (ethaddrp)->octet[3], (ethaddrp)->octet[4], (ethaddrp)->octet[5]

/*
 * Get an Ethernet address by getifaddrs(3).
 */
int get_eth_addr(const char *ifname, struct ether_addr *ethaddr)
{
    struct ifaddrs *ifap;
    struct ifaddrs *searcher;
    struct sockaddr_dl *dl_addr;
    int ret = 0;

    if((ret = getifaddrs(&ifap)) < 0) {
        return ret;
    }

    searcher = ifap;

    while(searcher->ifa_next != NULL) {
        if(strcmp(searcher->ifa_name, ifname) == 0 &&
                searcher->ifa_addr->sa_family == AF_LINK) {
            dl_addr = (struct sockaddr_dl *)searcher->ifa_addr;
            memcpy(ethaddr->octet, LLADDR(dl_addr), ETHER_ADDR_LEN);
            ret = 0;
            break;
        }
        searcher = searcher->ifa_next;
    }

    if(ret != 0) {
        ret = -1;
    }

    freeifaddrs(ifap);
    return ret;
}
#endif /* !_ETHERNET_UTIL_H_ */
