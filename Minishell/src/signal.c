#include "../minishell.h"

void handle_ctrl_c(int signum) 
{
  // struct termios term;

/* problem when recall history 
   printf("\b\b\n");
   printf("\033[0;92mAn\033[0;33mdro\033[0;91mme\033[0;95mda\033[0;34m$\033[0m ");	

/* proble when cat and double Ctrl+C */
//   rl_replace_line("", 0);
   if (signum = SIGINT)
    {
   	
    //  ioctl(STDIN_FILENO, TCSANOW, term); 
       printf("\n");
       rl_on_new_line();
       rl_replace_line("", 0);
      rl_redisplay();
     // printf("");
    }

}

void handle_ctrl_d(int signum) 
{

    struct termios saved_settings;
    struct termios new_settings;

     new_settings = saved_settings;
     tcgetattr(0, &saved_settings);
     new_settings.c_lflag &= ~ECHO;
     tcsetattr(0, TCSANOW, &new_settings);
  

    signal(SIGQUIT, SIG_IGN);
    rl_on_new_line();
    rl_replace_line("", 0);
    rl_redisplay();
  tcsetattr(0, TCSANOW, &saved_settings);
    
    printf("\n");
    exit(EXIT_SUCCESS);
}

void handle_ctrl_backslash(int signum) 
{
  // signal(SIGQUIT, SIG_IGN);
  //   printf("\b\b");
    // Do nothing

     // Restore the saved terminal settings
    
}

void enable_signals()
{

    signal(SIGINT, handle_ctrl_c);
  //  signal(SIGQUIT, handle_ctrl_backslash);
   signal(SIGQUIT, SIG_IGN);
    signal(SIGTERM, SIG_DFL);
    signal(SIGTSTP, SIG_DFL);
    signal(SIGTTIN, SIG_DFL);
    signal(SIGTTOU, SIG_DFL);
    signal(SIGCHLD, SIG_DFL);


}

// void enable_signals()
// {
//     struct sigaction    sa;

//     sigemptyset(&sa.sa_mask);
//     sa.sa_flags = SA_RESTART | SA_SIGINFO;
//     sa.sa_handler = SIG_IGN;
//     sigaction(SIGINT, &sa, NULL);
// }

