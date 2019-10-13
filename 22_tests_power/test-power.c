#include <stdio.h>
#include <stdlib.h>

unsigned power(unsigned x, unsigned y);

void doTest(unsigned x, unsigned y, unsigned ans){
  if ( power( x, y ) == ans ){
    exit(EXIT_SUCCESS);
  }
  else{
    exit(EXIT_FAILURE);
  }
}

int main(void){
  doTest( 0, 0, 1);
  doTest( 1, 0, 1);
  doTest( 0, 1, 0);
  doTest( 1.5, 0, EXIT_FAILURE);
  return EXIT_SUCCESS;
}
