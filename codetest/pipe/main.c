#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        printf("Usage: %s <command1> <command2>\n", argv[0]);
        return 1;
    }
    //Strategy: parent does the redirection before fork()
    int tempin = dup(0);
    int tempout = dup(1);

    //creat pipe
    int fdpipe[2];
    pipe(fdpipe);

    //redirect stdout for "ls"
    dup2(fdpipe[1], 1);
    close(fdpipe[1]);
    // fork for "ls"
    int ret=fork();
    if (ret == 0){
        //close file descriptors
        //as soon as are not needed
        close(fdpipe[0]);
        char *args[3];
        args[0] = "ls";
        args[1] = "-al";
        args[2] = NULL;
        execvp(args[0], args);
        //error in execvp
        perror("execvp");
        _exit(1);
    }

    //redirection for "grep"
    //redirect stdin
    dup2(fdpipe[0], 0);
    close(fdpipe[0]);

    //creat outfile
    int fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0600);
    if (fd < 0)
    {
        perror("open");
        exit (1);
    }

    //redirect stdout
    dup2(fd, 1);
    close(fd);

    //fork for "grep"
    ret=fork();
    if (ret == 0){
        char *args[3];
        args[0] = "grep";
        args[1] = argv[1];
        args[2] = NULL;
        execvp(args[0], args);
        //error in execvp
        perror("execvp");
        _exit(1);      
    }

    //restore stdin/stdout
    dup2(tempin, 0);
    dup2(tempout, 1);
    //Parent waits for grep
    //process
    waitpid(ret, NULL, NULL);
    printf("All Done!!\n");
    return 0;
}