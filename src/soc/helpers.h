#include <stdint.h>

#ifndef HELPERS_H
#define HELPERS_H

int sock_udp_create(uint16_t port);
int sock_udp_destroy(int sock);

#endif /* end of include guard: HELPERS_H */
