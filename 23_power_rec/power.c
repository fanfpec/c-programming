#include <stdio.h>
#include <stdlib.h>

unsigned power(unsigned x, unsigned y){
  if( y == 0 ){
    return 1;
  }
  else return x * power( x , y - 1);
}
