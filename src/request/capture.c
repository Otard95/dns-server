#include <netinet/in.h>
#include <arpa/inet.h>
#include "./data.h"
#include "./capture.h"
#include "../dns/packet.h"

int capture_udp(int socket, Request *req)
{
  
  socklen_t size = 0;
  uint8_t buff[MAX_PACKET_LEN];
  ssize_t n_bytes = recvfrom(socket, &buff, MAX_PACKET_LEN, 0, (struct sockaddr *) req->client, &size);

  if (n_bytes < 0) {
    return -1;
  }

  req->client_ip = inet_ntoa(req->client->sin_addr);
  req->data_len = n_bytes;
  parse_packet(&req->packet, buff, n_bytes);

  return 0;

}

