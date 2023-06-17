#include "../minishell.h"

int   andro_rd_history(void)
{
   int  fd;
    char *ch;
   
    fd = open(HISTORY_FILE, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1)
    {
        ft_putstr_fd("Error : history file\n", 2);
        return (EXIT_FAILURE);
    }
      while ((ch = get_next_line(fd)) != NULL)
      {
         ch = ft_strtrim(ch, "\n");
         add_history(ch);
         free(ch);
      }
      if(close(fd) == -1)
      {
        ft_putstr_fd("Error : close history file\n", 2);
        return (EXIT_FAILURE);
      }
      return (EXIT_SUCCESS);
}
