#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char * str) {
  //check NULL pointer first!!!
  if (str == NULL)
    return;
  
  int n = 0; //to store the length of str
  while (str[n] != '\0'){
    n++;
  } //n : \0 excluded
  if( n != 0 ){
    char p[n+1];
    //strncpy( p, str, n+1);
    int j = 0;
    for ( int i = n-1; i >= 0; i--){
      p[j] = str[i];
      j++;
      //printf("%c",p[j]);
    }
    p[j]='\0';
    //printf("%s\n", p);
    strncpy(str,p,n+1);
    return;
  }
  return;
}

int main(void) {
  char str0[] = "";
  char str1[] = "123";
  char str2[] = "abcd";
  char str3[] = "Captain's log, Stardate 42523.7";
  char str4[] = "Hello, my name is Inigo Montoya.";
  char str5[] = "You can be my wingman anyday!";
  char str6[] = "Executor Selendis! Unleash the full power of your forces! There may be no tomorrow!";
  char * array[] = {str0, str1, str2, str3, str4, str5, str6};
  for (int i = 0; i < 7; i++) {
    reverse(array[i]);
    printf("%s\n", array[i]);
  }
  return EXIT_SUCCESS;
}
