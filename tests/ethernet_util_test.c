#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <net/if.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>
#include "../ethernet_util.h"

int main(void) {
    struct ether_addr ethaddr;
    int err;

    err = get_eth_addr("em0", &ethaddr);

    printf(FORMAT_ETH_ADDR "\n", ETH_ADDR_OCTETS(&ethaddr));

    return 0;
}
