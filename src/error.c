#include <stdlib.h>
#include <stdio.h>
#include "./error.h"

void exit_error(char *msg)
{
  printf("[ERROR] ");
  fflush(stdout);
  perror(msg);
  exit(EXIT_FAILURE);
}
