#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n);

size_t doTest(int * array, size_t n) {
  printf("maxSeq(");
  if (array == NULL) {
    printf("NULL");
  }
  else {
    printf("{");
    for (size_t i =0; i < n; i++) {
      printf("%d", array[i]);
     if (i < n -1) {
	printf(", ");
      }
    }
    printf("}");
  }
  printf(", %zu) is \n", n);
  size_t len = maxSeq (array, n);
  if (len == 0) {
    printf("NULL\n");
  }
  else {
    printf("%zu\n", len);
  }
  return len;
}

int main(void) {
  int array1[] = { 77, 33, 19, 99, 42, 6, 27, 4,1111}; //2
  int array2[] = { -3, -42, -99, -1000, -999, -88, -77, 0}; //5
  //int array3[] = { 425, 59, -3, 77, 0, 36}; //2
  int array4[] = { 1,1,2,3,4,10};
  int array5[] = { 1,1,1,-1,-5};
  //int array6[] = { -9,-8};
  if( doTest (array1, 9) != 2 ) return EXIT_FAILURE;
  if( doTest (array2, 8) != 5 ) return EXIT_FAILURE;
  //if( doTest (array3, 6) != 2 ) return EXIT_FAILURE;
  if( doTest (NULL, 0) != 0 ) return EXIT_FAILURE;
  //if( doTest (array1, 0) != 2 ) return EXIT_FAILURE;
  if( doTest (array4, 6) != 5 ) return EXIT_FAILURE;
  //if( doTest (array4, 5) != 5 ) return EXIT_FAILURE;
  if( doTest (array5, 5) != 1 ) return EXIT_FAILURE;
  //if( doTest (array6, 2) != 2 ) return EXIT_FAILURE;
  //doTest (array2, 0);
  return EXIT_SUCCESS;
}
