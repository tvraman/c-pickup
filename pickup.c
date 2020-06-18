#include <stdio.h>

int main (int argC, char  **argV) {
  printf("How many sticks would you like to play with?\n");
  int n;
  scanf("%d", &n);
  printf("Playing with %d sticks.\n", n);
  int* fibs;
  fibs[0] = 1;
fibs[1] = 2;
 int index = 1;
 while (fibs [index -1] < n) {
   fibs[index] = fibs[index -1] + fibs[index -2];
   index++;
}
}
