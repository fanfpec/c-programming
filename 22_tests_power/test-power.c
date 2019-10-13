#include <stdio.h>
#include <stdlib.h>

unsigned power(unsigned x, unsigned y);

void doTest(unsigned x, unsigned y, unsigned ans){
  //if ( power( x, y ) != ans ){
  //  printf("%d to the %d-the power is: %d\nwhile the correct answer is: %d\n", x, y, power(x,y), ans);
  if ( power( x, y ) != ans || sizeof(power(x,y))!=sizeof(unsigned)){
    printf("%d to the %d-the power is: %d\nwhile the correct answer is: %d\n", x, y, power(x,y), ans);
    exit(EXIT_FAILURE);
  }
}

int main(void){
  doTest( 0, 0, 1);
  //doTest( 1, 0, 1);
  doTest( 0, 1, 0);
  doTest( 1.5, 2, 2.25);
  doTest( 2, 0, 1);
  return EXIT_SUCCESS;
}
