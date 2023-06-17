#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() { 
    int ret = fork();
    const char *argv[3]; 
    if (ret == 0)
    {
        // Child process. 
        // Execute “ls –al” 
        argv[0]="ls"; 
        argv[1]="-al"; 
        argv[2] = NULL; 
        execve("/bin/ls", argv, NULL); 
        // There was an error 
        perror("execve"); 
        _exit(1); 
    }
    else if (ret < 0)
    {
        // There was an error in fork 
        perror("fork");
        exit(2);
    }
    else
    {
        // This is the parent process 
        // ret is the pid of the child 
        // Wait until the child exits 
        waitpid(ret, NULL, 0);
    } // end if
}
