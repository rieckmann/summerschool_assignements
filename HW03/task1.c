#include <stdio.h>
#include <stdlib.h>
#include "output.h"

int length(char* str){
  int i = 0;
  while(str[i]!=0){
    i++;
  }
  return i;
}

int main(int argc, char *argv[]) {

  if (argc != 2) {
    printf("Wrong number of Arguments supplied, expected one string argument\n");
    exit(1);
  }

  // get size of string and deduct string length from that
  int l = length(argv[1]);

  // output the result
  printf("The entered string is: \n%s \n",argv[1]);
  printf("The number of characters in the string is: \n");
  outputT1(l);
}
