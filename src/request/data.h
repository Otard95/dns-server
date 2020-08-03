#include "../dns/packet.h"

#ifndef DATA_H
#define DATA_H

typedef struct _request_t {
  struct sockaddr_in *client;
  char *client_ip;
  ssize_t data_len;
  DNSPacket packet;
} Request;

Request* new_request();
void destroy_request(Request*);

#endif /* end of include guard: DATA_H */
