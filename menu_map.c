#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Descriptor Struct
struct fun_desc {
    char *name;
    char (*fun)(char);
};

char* map(char *array, int array_length, char (*f) (char)){
    char* mapped_array = (char*)(malloc(array_length*sizeof(char)));
    for (int i = 0; i < array_length; ++i) {
        mapped_array[i] = f(array[i]);
    }
    return mapped_array;
}

char my_get(char c){
    return fgetc(stdin);
}

char cprt(char c){
    if (c >= 0x20 && c <= 0x7E) {
        printf("%c\n", c);
    }
    else{
        printf(".\n");
    }
    return c;
}

char encrypt(char c){
    if (c >= 0x20 && c <= 0x4E){
        c = c + 0x20;
    }
    return c;
}

char decrypt(char c){
    if (c >= 0x40 && c <= 0x7E){
        c = c - 0x20;
    }
    return c;
}


char xoprt(char c){
  printf("%02x, %03o\n" ,c ,c );
  return c;
}
void print_menu(struct fun_desc menu[], int menu_length) {
    printf("Select operation from the following menu:\n");
    for (int i = 0; i < menu_length; i++) {
        printf("%d) %s\n", i, menu[i].name);
    }
}

void print_array(const char *carray, int size) {
    printf("array: ");
    for (int i = 0; i < size; i++) {
        printf("%c", carray[i]);
    }
    printf("\n");
}

int main() {
    // Initialize char array and function descriptor array
    char *carray = (char*)(calloc(5,sizeof(char))); 
    struct fun_desc menu[] = {
        { "Get String", my_get },
        { "Print String", cprt },
        { "Print Hex", xoprt },
        { "Encrypt", encrypt },
        { "Decrypt", decrypt },
        { NULL, NULL }
    };
    int menu_length = sizeof(menu) / sizeof(menu[0]) - 1; // Subtract 1 for the NULL entry
    char buffer[256];

    while (1) {
        int choice;
        print_menu(menu, menu_length);
        printf("Enter your choice: \n");

        if(fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("\nEOF detected. Exiting.\n");
            break;
        }

        sscanf(buffer, "%d", &choice);
        if (0 <= choice && choice < menu_length) {
            printf("Within bounds\n");
            char *clone = map(carray, 5, menu[choice].fun);
            free(carray);
            carray = clone;
            if(choice == 0){
                choice = choice + 1;
            }
        } else {
            printf("Not within bounds. Exiting.\n");
            break;
        }
    }
    free(carray);
    return 0;
}