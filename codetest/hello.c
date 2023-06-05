#include <stdio.h>
#include <stdlib.h>

int a = 5;// Stored in data section
int b[20]; // Stored in bss
const char * hello = "Hello world";
int main() { // Stored in text
int x; // Stored in stack
int *p =(int*) malloc(sizeof(int)); //Stored in heap
printf("(Data) &a=0x%ls\n", &a);
printf("(Bss) &b[0]=0x%ls\n", &b[0]);
printf("(Stack) &x=0x%ls\n", &x);
printf("(Heap) p=0x%ls\n", p);
printf("(ROData) \"Hello\"=0x%s\n", hello);
// printf("(TEXT) main=0x%lx\n", main);
free (p);
}