#include <stdio.h>
#include <stdlib.h>
#include "output.h"

int main(int argc, char *argv[]) {

  if (argc != 2) {
    printf("Please enter an additional integer!\n");
    exit(1);
  }

  int n = atoi(argv[1]); // argv[0] is the program name

  for (int i = 0; i <= n; i++) {
      outputT2(i);
      // added this for nicer output
      printf("\n");
  }
}
