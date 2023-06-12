#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		write(fd, s++, 1);
}

// int main() {
//     int fd;
//     char* envDir = getenv("HOME");

//     fd = open(".env", O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
//     if (fd == -1)
//     {
//         printf("Error : history file\n");
//         return (0);
//     }
//     printf("envDir: %s\n", envDir);
//     if (envDir != NULL) {
//        ft_putstr_fd(envDir, fd);
//     } else {
//         printf("HOME environment variable not found\n");
//     }
//     if (close(fd) == -1)
//     {
//          printf("Error : close history file\n");
//         return (0);
//     }
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

int main() {
    char* homeDir = getenv("ENV");
    if (homeDir != NULL) {
        printf("Home directory: %s\n", homeDir);
    } else {
        printf("HOME environment variable not found\n");
    }
    return 0;
}
