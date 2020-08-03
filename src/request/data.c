#include <stdio.h>
#include <stdlib.h>
#include "data.h"

Request* new_request()
{
  Request *req = malloc(sizeof(Request));
  req->client = malloc(sizeof(struct sockaddr_in));
  return req;
}

void destroy_request(Request *req)
{
  puts("[DEBUG] Free req->client");
  free(req->client);
  puts("[DEBUG] Free req");
  free(req);
}

