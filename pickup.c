#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 15

int main (int argC, char  **argV) {
  printf("How many sticks would you like to play with?\n");
  int n;
  scanf("%d", &n);
  printf("Playing with %d sticks.\n", n);
  int fibs[MAX_SIZE];
  fibs[0] = 1;
  fibs[1] = 2;
  int index = 1;
  while (fibs [index -1] < n) {
    fibs[index] = fibs[index -1] + fibs[index -2];
    if (index == MAX_SIZE){
      printf("You'll get bored with such a large number of sticks: %d\n", MAX_SIZE);
      exit(0);
    }
    index++;
  }

  int limit = n - 1;
  int fib_base = fibs[0];
  int fib_p = 0;
  
  for (int i = 0; i<MAX_SIZE; i++ ){
    if (fibs[i] == n)   {
      fib_p = 1;
      break;
}
  }

  if (fib_p != 1){
    printf("I play first.\n");
}

}
