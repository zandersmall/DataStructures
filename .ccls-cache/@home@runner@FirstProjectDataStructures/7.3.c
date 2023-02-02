#include <stdio.h>
#include <stdlib.h>

int main() {
int *iPtr;
float f = 2.0;

printf("The hex representation of %f is: %x\n", f, *((int *)&f));
  
return 0;
}