#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 //Task 2a
char* map(char *array, int array_length, char (*f) (char)){
  char* mapped_array = (char*)(malloc(array_length*sizeof(char)));
  for (int i = 0; i < array_length; ++i) {
      mapped_array[i] = f(array[i]);
  }
  return mapped_array;
}

//Task 2b
/* Ignores c, reads and returns a character from stdin using fgetc. */
char my_get(char c){
  return fgetc(stdin);
}

/* If c is a number between 0x20 and 0x7E, cprt prints the character of ASCII value c 
followed by a new line. Otherwise, cprt prints the dot ('.') character. After printing, 
cprt returns the value of c unchanged. */
char cprt(char c){
  if (0x20 <= c && c <= 0x7E) printf("%c\n", c);
  else printf(".\n");
  return c;
}

/* Gets a char c. If c is between 0x20 and 0x4E add 0x20 to its value and return it. 
Otherwise return c unchanged */
char encrypt(char c){
  if (0x20 <= c && c <= 0x4E) c = c + 0x20;
  return c;
}

/* Gets a char c and returns its decrypted form subtractng 0x20 from its value. 
But if c was not between 0x40 and 0x7E it is returned unchanged */
char decrypt(char c){
  if (0x40 <= c && c <= 0x7E) c = c - 0x20;
  return c;
}

/* xoprt prints the value of c in a hexadecimal representation, then in 
octal representation, followed by a new line, and returns c unchanged. */
char xoprt(char c){
  printf("%02x, %03o\n" ,c ,c );
  return c;
}

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
  /*Test Task 2b:*/
  /*
  int base_len = 5;
  char arr1[base_len];
  printf("Enter 5 characters: ");
  char* arr2 = map(arr1, base_len, my_get);
  char* arr3 = map(arr2, base_len, cprt);
  char* arr4 = map(arr3, base_len, xoprt);
  char* arr5 = map(arr4, base_len, encrypt);
  char* arr6 = map(arr5, base_len, cprt);
  free(arr1);
  free(arr2);
  free(arr3);
  free(arr4);
  free(arr5);
  free(arr6);
  */

 
  return 0;
}