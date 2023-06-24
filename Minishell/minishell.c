/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:37:07 by kchatvet          #+#    #+#             */
/*   Updated: 2023/06/24 01:14:24 by kchatvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "./src/utiles.h"




int execute(char cmd[MAX_COMMAND_LENGTH], t_envlist *envlist, char **env)
{
    /* kanit edit on 19/6/2003 */  
    char *args[MAX_CMD_LENGTH];
    char *token;
	int status;
  
	int arg_index;
	pid_t pid; 
	char *sh_path;
//	char *test_path;

//	test_path ="/usr/local/rvm/gems/ruby-3.1.4/bin:/usr/local/rvm/gems/ruby-3.1.4@global/bin:/usr/local/rvm/rubies/ruby-3.1.4/bin:/vscode/bin/linux-x64/695af097c7bd098fbf017ce3ac85e09bbc5dda06/bin/remote-cli:/home/codespace/.local/bin:/home/codespace/.dotnet:/home/codespace/nvm/current/bin:/home/codespace/.php/current/bin:/home/codespace/.python/current/bin:/home/codespace/java/current/bin:/home/codespace/.ruby/current/bin:/home/codespace/.local/bin:/usr/local/oryx:/usr/local/go/bin:/go/bin:/usr/local/sdkman/bin:/usr/local/sdkman/candidates/java/current/bin:/usr/local/sdkman/candidates/gradle/current/bin:/usr/local/sdkman/candidates/maven/current/bin:/usr/local/sdkman/candidates/ant/current/bin:/usr/local/rvm/gems/default/bin:/usr/local/rvm/gems/default@global/bin:/usr/local/rvm/rubies/default/bin:/usr/local/share/rbenv/bin:/opt/conda/bin:/usr/local/php/current/bin:/usr/local/python/current/bin:/usr/local/py-utils/bin:/usr/local/nvs:/usr/local/share/nvm/versions/node/v19.9.0/bin:/usr/local/hugo/bin:/usr/local/dotnet/current:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/local/rvm/bin";
	
   /* kanit edit on 19/6/2003 */  

    //  cmd[ft_strcspn(cmd, "\n")] = '\0';  // Remove trailing newline  

	 //   if (cmd[0] != "\n")
	//		 cmd[ft_strcspn(cmd, "\n")] = '\0';

	
 //	cmd[ft_strcspn(cmd, "\n")] = '\0';

        // Tokenize input into arguments
         arg_index = 0;
        token = strtok(cmd, " ");
	//        token = ft_split(cmd, ' ');
         while (token != NULL) 
	 {
             args[arg_index++] = token;
             token = strtok(NULL, " ");
	  //       token = ft_split(NULL, ' ');
	     
         }
         args[arg_index] = NULL;

         // Exit shell if "exit" command is entered
         /* comment exit Segmentation fault (core dumped)
      if (ft_strncmp(args[0], "exit", ft_strlen(args[0])) == 0 ||\
		                  args[0] == EOF) */
		 
		 if (ft_strcmp(args[0], "exit") == 0)// ||\
		                  args[0] == NULL) 
	       {																					
             clean_exit(errno, envlist);
         }
	

         // Fork a child process to execute external commands
         pid = fork();
         if (pid == -1) 
	      {
             perror("fork");
             exit(errno);
         }
	     else if (pid == 0) 
	     {
             // Child process
			 sh_path = ft_strjoin("/bin/", args[0]);

			 
//			 printf("\n xx %s \n",sh_path);
			
        //
		 //      if (execve(test_path, args, NULL) == -1) 
		     if (execve(sh_path, args, env) == -1) 
		//	   if (execve(args[0], args, env) == -1) 
	         {
                 perror("execve");
                 exit(errno);
             }
         } 
	    else 
	    {
             // Parent process
             if (waitpid(pid, &status, 0) == -1) 
	         {
                 perror("waitpid");
                 exit(errno);
	         }
         }
/*
	//	 if (no_interup)
         printf("\n debug %s\n",args[0]);
	//	 *cmd = '\0';
		// cmd[0] = NULL;
		 printf("\n debug %s\n",args[0]);
*/
    //     free(sh_path);
		 return (status);
    }

   

	


int	main(int argc, char **argv, char **envp)
{
	char			cmd[MAX_COMMAND_LENGTH];
	t_envlist		*envlist;
	t_simple_com	*sim_cmd;
	int status;
    

  


	get_env(&envlist, envp);
		

	cmd_pwd();
   // cmd_cd(shell_var);
	cmd_pwd();
	enable_signals();
	andro_rd_history();

 /*  temp close pat edit	
	while (1)
	{
		if (!myfgets(cmd, MAX_CMD_LENGTH, stdin))
			return (perror("Error"), EXIT_FAILURE);
      
            
     	if (ft_strchr(cmd, '\n'))
			*ft_strchr(cmd, '\n') = '\0';
		if (strcmp(sim_cmd->args[0], "exit") == 0)
			exit(0);

   	}    
         */
     status = 0;
	 cmd[0] = '\0';
	 	 	
//	 myfgets(cmd, MAX_CMD_LENGTH, stdin);  // Read user input	
 while (1)
    {
	
      //  myfgets(cmd, MAX_CMD_LENGTH, stdin);  // Read user input
		
		if (status != 2)
		{
		  printf("\033[0;92mAn\033[0;33mdro\033[0;91mme\033[0;95mda\033[0;34m$\033[0m ");	
		    
		}
	  	myfgets(cmd, MAX_CMD_LENGTH, stdin);  // Read user input

		if (cmd[0] != '\0')
		     {
				    status = execute(&cmd[0], envlist, envp);
		      } 	
	  if (cmd[0] == '\0' && status == 2)
	    status = 0;
			
		if (cmd[0] == '\0')
		    printf("\n");
		   // clean_exit(errno, envlist);
		   
		
		
	//	printf("status %d\n", status);	
		
	
		
		
	    cmd[0] = '\0';
	

	}		
     
  //  return (0);
//}

		// Fork a child process to execute external commands
		// pid_t pid = fork();
		// if (pid == -1) {
		//     perror("fork");
		//     exit(1);
		// } else if (pid == 0) {
		// Child process
		//     if (execvp(args[0], args) == -1) {
		//         perror("execvp");
		//         exit(1);
		//     }
		// } else {
		// Parent process
		//     if (waitpid(pid, &status, 0) == -1) {
		//         perror("waitpid");
		//         exit(1);
		//     }
		// }


/*  move to clean_exit
	while (envlist)
	{
		free_t_envlist(&envlist);
		envlist = envlist->next;
	}
 */   
	 clean_exit(errno, envlist);
}
