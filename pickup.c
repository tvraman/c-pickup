#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 15
int next_move (int fibs[], int n);
int main (int argC, char  **argV) {
  printf("How many sticks would you like to play with?\n");
  int n, k;
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

  if (fib_p != 1){ /*  first move */
    printf("I play first.\n");
    k = next_move (fibs, n);
    n -= k;
    limit = 2*k;
    printf("I pick %d sticks. %d sticks left; You can pick up to %d.\n",k, n, limit);
  } /*  first turn */
  while (n > 0){ /*  take turns */
    printf("How many sticks do you pick?\n");
    scanf("%d", &k);
    if (k > limit){
      printf("You cannot   pick more than %d sticks.\n", limit);
      exit(1);
    }
    n -= k;
    limit = 2*k;
    next_move(fibs, n);
  }
}
int next_move (int fibs[], int n) {
  int base, k;
  for (int i = 0; i<MAX_SIZE; i++ ){ /*  update base */ 
    if (fibs[i] < n)   {
      base = fibs[i];
    } else {
      break;
    }
  } /*  done updating base  */

  k = n -base;
  /*  check for 3k <n rule */ 
  while (3*k >= n) { /*  reduce game */
    /*  Update base */
    for (int i = 0; i<MAX_SIZE; i++ ){ /*  update base */ 
      if (fibs[i] < k)   {
        base = fibs[i];
      } else {
        break;
      }
    }
    k = k - base;
  } /*  done reducing game */
  return k;
    
    
}
