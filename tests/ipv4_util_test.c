#include <stdio.h>
#include <sys/types.h>
#include <netinet/in.h>
#include "../ipv4_util.h"

int main(void) {
    struct in_addr ip4addr;
    uint8_t *octet;
    int err;

    err = get_ip4_addr("em0", &ip4addr);

    octet = (uint8_t *)&(ip4addr.s_addr);

    printf(FORMAT_IP4_ADDR "\n", octet[0], octet[1], octet[2], octet[3]);

    return 0;
}
