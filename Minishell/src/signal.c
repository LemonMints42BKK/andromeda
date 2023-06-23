#include "../minishell.h"

void handle_ctrl_c(int signum) 
{
    printf("\b\b  \n");
    rl_on_new_line();
    rl_replace_line("", 0);
    rl_redisplay();
 
}

void handle_ctrl_d(int signum) {
    
    printf("\n");
    exit(EXIT_SUCCESS);
}

void handle_ctrl_backslash(int signum) 
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

  //  printf("\n");
    // Do nothing

     // Restore the saved terminal settings
    tcsetattr(0, TCSANOW, &saved_settings);
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

