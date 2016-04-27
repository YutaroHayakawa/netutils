#ifndef _IPV4_UTIL_H_
#define _IPV4_UTIL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <net/if.h>
#include <ifaddrs.h>

#define FORMAT_IP4_ADDR "%u.%u.%u.%u"

int get_ip4_addr(const char *ifname, struct in_addr *ipaddr)
{
    struct ifaddrs *ifap;
    struct ifaddrs *searcher;
    struct sockaddr_in *in_addr;
    int ret = 0;

    if((ret = getifaddrs(&ifap)) < 0) {
        return ret;
    }

    searcher = ifap;

    while(searcher->ifa_next != NULL) {
        if(strcmp(searcher->ifa_name, ifname) == 0 &&
                searcher->ifa_addr->sa_family == AF_INET) {
            in_addr = (struct sockaddr_in *)searcher->ifa_addr;
            memcpy(ipaddr, &(in_addr->sin_addr), sizeof(struct in_addr));
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
#endif /* !_IPV4_UTIL_H_ */
