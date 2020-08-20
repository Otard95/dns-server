#include <stdio.h>
#include "./soc/helpers.h"
#include "./request/data.h"
#include "./request/capture.h"
#include "./dns/packet.h"
#include "./error.h"

int main(void)
{

  Request *req = new_request();
  int socket = sock_udp_create(53);

  if (capture_udp(socket, req) < 0) {
    exit_error("[ERROR] Faild to reqeive packet");
  }

  printf("[INFO] Recievd packet from %s with size %ld\n", req->client_ip, req->data_len); fflush(stdout);
  print_packet_info(&req->packet);
  
  if (req->packet->header->RCode != 0) {
    // Unsupported query type
    // respond
  }
  
  // Parse query questions
  // Lookup host names
  // If has answer, build response
  // else respond with RCode 

  destroy_request(req);
  if (sock_udp_destroy(socket) < 0) {
    exit_error("Failed to close socket");
  }

  puts("[INFO] Unbound socket and finished!");

  return 0;
}

