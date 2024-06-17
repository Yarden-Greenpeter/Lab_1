#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
char* map(char *array, int array_length, char (*f) (char)){
  char* mapped_array = (char*)(malloc(array_length*sizeof(char)));
  for (int i = 0; i < array_length; ++i) {
      mapped_array[i] = f(array[i]);
  }
  return mapped_array;
}

char xoprt(char ch) {return ch + 1;}

int main(int argc, char **argv){
  /*Test Task 2a:*/
  /*char arr1[] = {'H', 'E', 'Y', '!'};
  int array_length = sizeof(arr1) / sizeof(arr1[0]);
  char* arr2 = map(arr1, array_length, xoprt);
  for (int i = 0; i < array_length; ++i) {
      printf("%d ", arr2[i]);
  }
  printf("\n");
  free(arr2);*/
  //-----------------------------------------------------

  return 0;
}