#include "../minishell.h"

void   andro_wr_history(char *line)
{
    int fd;

    fd = open(HISTORY_FILE, O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (fd == -1)
        ft_putstr_fd("Error : To open history file\n", 2);
    ft_putstr_fd(line, fd);
    write(fd, "\n", 1);
    if (close(fd) == -1)
        ft_putstr_fd("Error : To close history file\n", 2);    
}

void   andro_rd_history(void)
{
    int  fd;
    char *ch;
    char *str;
   
    rl_clear_history();
    fd = open(HISTORY_FILE, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1)
        ft_putstr_fd("Error : to open history file\n", 2);
    while ((ch = get_next_line(fd)) != NULL)
    {
        str = ft_strtrim(ch, "\n");
        free (ch);
        add_history(str);
        free(str);
       
    }
    if(close(fd) == -1)
        ft_putstr_fd("Error : to close history file\n", 2);
}