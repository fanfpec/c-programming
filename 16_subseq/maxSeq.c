#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n){
  if ( n == 0){
    return 0;
  }
  //int smaller_ele = array[0]; 
  size_t len = 1;
  size_t len_temp = 1;
  for (size_t i = 1; i < n; i ++){
    if (array[i] > array[i-1]){
      //smaller_ele = array[i];
      len_temp ++;
    }else{
      len_temp = 1;
    }
    if (len < len_temp)
      len = len_temp;
  }
  return len;
}
