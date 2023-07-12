#include "../minishell.h"

void   andro_wr_history(char *line, t_andro data)
{
    int fd;
    char    *his;
    
    his = data.user_path;
    his =  ft_strjoin(his,HISTORY_FILE);
//    fd = open(HISTORY_FILE, O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    printf("%s\n",his);
     fd = open(his, O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
     free (his);
    if (fd == -1)
        ft_putstr_fd("Error : To open history file\n", 2);
    ft_putstr_fd(line, fd);
    write(fd, "\n", 1);
    if (close(fd) == -1)
        ft_putstr_fd("Error : To close history file\n", 2);    
}

void   andro_rd_history(t_andro data)
{
    int  fd;
    char *ch;
    char *str;
    char *his;
   
    rl_clear_history();
    his = data.user_path;
    his =  ft_strjoin(his,HISTORY_FILE);

//    fd = open(HISTORY_FILE, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    fd = open(his, O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
     free (his);

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