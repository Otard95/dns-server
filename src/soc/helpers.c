#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include "./helpers.h"
#include "../error.h"

int sock_udp_create(uint16_t port)
{
  struct sockaddr_in name;
  int sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
  
  if (sock < 0) {
    exit_error("Failed to create socket");
  }

  name.sin_family = AF_INET;
  name.sin_port = htons(port);
  name.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

  if (bind(sock, (struct sockaddr *) &name, sizeof(name)) < 0) {
    exit_error("Failed to bind to port");
  }

  printf("[INFO] Socket bound to %s:%d\n", inet_ntoa(name.sin_addr), port);

  return sock;
}

int sock_udp_destroy(int sock) {
  int tries = 0;
  int res;
  do {
    res = close(sock);
    tries++;
  } while (tries < 5 && res < 0);
  return res;
}

