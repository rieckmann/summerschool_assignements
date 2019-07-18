#include <stdio.h>
#include <stdlib.h>
#include "output.h"

// piece of code I recycled from the CTutorial
int int_sorter(const void *first_arg, const void *second_arg) {
  // cast the pointers to the right type
  int first = *(int *)first_arg;
  int second = *(int *)second_arg;
  // carry out the comparison
  if (first < second) {
    return -1;
  } else if (first == second) {
    return 0;
  } else {
    return 1;
  }
}

int main(int argc, char *argv[]) {

  if (argc != 2) {
    printf("Please enter an additional integer!\n");
    exit(1);
  }

  int n = atoi(argv[1]); // argv[0] is the program name

  // test if a valid integer was entered
  if (n<=0 | n>=100){
    printf("Valid integers are in the range 0 < n < 100!\n");
    exit(1);
  }

  //allocate memory
  int *nArray = (int *)malloc((n+1) * sizeof(int));

  //populate the array
  for (int i = 0; i <= n; i++) {
      nArray[i]=n-i;
  }

  // sort the array
  qsort(nArray, n+1, sizeof(int), int_sorter);

  //output the array
  outputT5(nArray, n+1);

  //free the allocated memory
  free(nArray);
}
