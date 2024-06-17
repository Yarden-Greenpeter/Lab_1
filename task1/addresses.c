#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int addr5;
int addr6;

int foo()
{
    return -1;
}
void point_at(void *p);
void foo1();
char g = 'g';
void foo2();

int secondary(int x)
{
    int addr2;
    int addr3;
    char *yos = "ree";
    int *addr4 = (int *)(malloc(50));

	int iarray[3];
    float farray[3];
    double darray[3];
    char carray[3];

	int iarray2[] = {1,2,3};
    char carray2[] = {'a','b','c'};
    int* iarray2Ptr;
    char* carray2Ptr; 
    
	printf("- &addr2: %p\n", &addr2);
    printf("- &addr3: %p\n", &addr3);
    printf("- foo: %p\n", &foo);
    printf("- &addr5: %p\n", &addr5);
	printf("Print distances:\n");
    point_at(&addr5);

    printf("Print more addresses:\n");
    printf("- &addr6: %p\n", &addr6);
    printf("- yos: %p\n", yos);
    printf("- gg: %p\n", &g);
    printf("- addr4: %p\n", addr4);
    printf("- &addr4: %p\n", &addr4);

    printf("- &foo1: %p\n", &foo1);
    printf("- &foo1: %p\n", &foo2);
    
    printf("Print another distance:\n");
    printf("- &foo2 - &foo1: %ld\n", (long) (&foo2 - &foo1));

   
    printf("Arrays Mem Layout (T1b):\n");

    /* task 1 b here */
    printf("Hexadecimal values of pointers:\n");

    printf("iarray: %p, iarray+1: %p\n", (void*)iarray, (void*)(iarray+1));
    printf("farray: %p, farray+1: %p\n", (void*)farray, (void*)(farray+1));
    printf("darray: %p, darray+1: %p\n", (void*)darray, (void*)(darray+1));
    printf("carray: %p, carray+1: %p\n", (void*)carray, (void*)(carray+1));
    /*
    from the output we can see that arrays are stored in contiguous memory blocks, 
    and each element's address is different by the size of the array's element type.
    */

    /* task 1 d here */
    iarray2Ptr = iarray2;
    carray2Ptr = carray2;
    printf("Pointers and arrays (T1d): \n");
    printf("iarray2: ");
    for (int i = 0; i < 3; ++i) {
        printf("%d ", *(iarray2Ptr + i));
    }
    printf("\n");

    printf("carray2: ");
    for (int i = 0; i < 3; ++i) {
        printf("%c ", *(carray2Ptr + i));
    }
    printf("\n");

    

}

int main(int argc, char **argv)
{ 

    printf("Print function argument addresses:\n");

    printf("- &argc %p\n", &argc);
    printf("- argv %p\n", argv);
    printf("- &argv %p\n", &argv);
	
	secondary(0);
    
    printf("Command line arg addresses (T1e):\n");
    /* task 1 e here */
    
    return 0;
}

void point_at(void *p)
{
    int local;
    static int addr0 = 2;
    static int addr1;

    long dist1 = (size_t)&addr6 - (size_t)p;
    long dist2 = (size_t)&local - (size_t)p;
    long dist3 = (size_t)&foo - (size_t)p;

    printf("- dist1: (size_t)&addr6 - (size_t)p: %ld\n", dist1);
    printf("- dist2: (size_t)&local - (size_t)p: %ld\n", dist2);
    printf("- dist3: (size_t)&foo - (size_t)p:  %ld\n", dist3);
    
    printf("Check long type mem size (T1a):\n");
    /* part of task 1 a here */
    /*
Stack:
    &argc (0x7ffd2cb6833c)
    argv (0x7ffd2cb68458)
    &argv (0x7ffd2cb68330)
    &addr2 (0x7ffd2cb682d8)
    &addr3 (0x7ffd2cb682dc)
    &addr4 (0x7ffd2cb682e0)
Code:
    foo (0x5612ac6b01a9)
    &foo1 (0x5612ac6b057f)
    &foo1 (0x5612ac6b0599)
    &foo2 - &foo1 (26)
Global/Static Data:
    yos (0x5612ac6b1008)
    gg (0x5612ac6b3010)
    addr4 (0x5612ae5266b0)
    addr0 (0x5612ac6b3014)
    addr1 (0x5612ac6b3024)
    &addr6 (0x5612ac6b3020)
Observations
Stack Addresses: Typically high memory addresses and close to each other since they grow
                 towards lower memory.
Code Addresses:  Located in the middle to high memory regions, where the executable code 
                 resides.
Global/Static Data Addresses: Usually located in the middle memory region, where global 
                              and static variables reside.
    */

    printf("- addr0: %p\n", &addr0);
    printf("- addr1: %p\n", &addr1);

    /*
    part of task 1 c here
    The point_at function provides insights into memory layout by calculating and printing 
    distances between key memory addresses (&addr6, &local, &foo) and a pointer p. 
    This understanding aids in debugging and ensuring correct memory access and utilization
    in programs. arrays are stored in contiguous memory blocks, 
    and each element's address is different by the size of the array's element type.
    */
}

void foo1()
{
    printf("foo1\n");
}

void foo2()
{
    printf("foo2\n");
}