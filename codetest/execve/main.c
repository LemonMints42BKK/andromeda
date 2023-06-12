#include <stdio.h>
#include <unistd.h>

int main() {
    char* const argv[] = {A, B, NULL};
    execve(P, argv, NULL);
    printf("This line won't be executed\n");
    return 0;
}