/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <pnopjira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:37:07 by kchatvet          #+#    #+#             */
/*   Updated: 2023/07/02 19:51:24 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int execute(char cmd[MAX_COMMAND_LENGTH], t_andro *data, char **env);
int	setup_data(t_andro *data);

int	main(int argc, char **argv, char **envp)
{
	t_andro	*data;
	
    (void)argc;
	(void)argv;
	data = (t_andro*)malloc(sizeof(t_andro));
	if (!data)
		return(errno);
	setup_data(data);
  	get_env(&data->envlist, envp);
//	print_env(data);
	enable_signals();
	andro_rd_history();
	while (1)
	{
		if (!myfgets(data->cmd, MAX_CMD_LENGTH, stdin, data->status))
			return (perror("Error"), EXIT_FAILURE);    
     	if (ft_strchr(data->cmd, '\n'))
			*ft_strchr(data->cmd, '\n') = '\0';
		data->final_tb = tokenize(data->cmd);
//		print_final_tb(data);
		if (data->cmd[0] != '\0')
			data->status = execute(&data->cmd[0], data, envp);
		// if (data->status == 2)
		// {
			
		// }
		data->cmd[0] = '\0';
   	}
	clean_exit(errno, data);
	return (errno);
}

int	setup_data(t_andro *data)
{
	data->cmd[0] = '\0';
	data->envlist = NULL;
	data->final_tb = NULL;
	data->status = 0;
	return (EXIT_SUCCESS);
}
//int execute(t_andro data, t_envlist *envlist, char **env)

/* print envilonment*/
void	print_env(t_andro *data)
{
	t_envlist	*ptr;

	ptr = data->envlist;
	while (ptr)
	{
		printf ("%s=%s\n", ptr->key, ptr->value);
		ptr = ptr->next;
	}
}

/* print final_table*/

void	print_final_tb(t_andro *data)
{
	t_command	*ptr;

	ptr = data->final_tb;
	while (ptr)
	{
		printf("number_of_simple_command:%d\n", ptr->n_simple_cmd);
		ptr = ptr->next;
	}
}

int execute(char cmd[MAX_COMMAND_LENGTH], t_andro *data, char **env)
{
    char *args[MAX_CMD_LENGTH];
    char *token;
	int status;
  
	int arg_index;
	pid_t pid; 
	char *sh_path;
	int in_cmd;

	status = 0;

	// t_envlist *ptr;

    // ptr = envlist;
    // while (ptr != NULL)
    // {
    //     printf ("%s=%s\n", ptr->key, ptr->value);
    //     ptr = ptr->next;
    // }
//	andro_env(envlist);

//	char *test_path;

//	test_path ="/usr/local/rvm/gems/ruby-3.1.4/bin:/usr/local/rvm/gems/ruby-3.1.4@global/bin:/usr/local/rvm/rubies/ruby-3.1.4/bin:/vscode/bin/linux-x64/695af097c7bd098fbf017ce3ac85e09bbc5dda06/bin/remote-cli:/home/codespace/.local/bin:/home/codespace/.dotnet:/home/codespace/nvm/current/bin:/home/codespace/.php/current/bin:/home/codespace/.python/current/bin:/home/codespace/java/current/bin:/home/codespace/.ruby/current/bin:/home/codespace/.local/bin:/usr/local/oryx:/usr/local/go/bin:/go/bin:/usr/local/sdkman/bin:/usr/local/sdkman/candidates/java/current/bin:/usr/local/sdkman/candidates/gradle/current/bin:/usr/local/sdkman/candidates/maven/current/bin:/usr/local/sdkman/candidates/ant/current/bin:/usr/local/rvm/gems/default/bin:/usr/local/rvm/gems/default@global/bin:/usr/local/rvm/rubies/default/bin:/usr/local/share/rbenv/bin:/opt/conda/bin:/usr/local/php/current/bin:/usr/local/python/current/bin:/usr/local/py-utils/bin:/usr/local/nvs:/usr/local/share/nvm/versions/node/v19.9.0/bin:/usr/local/hugo/bin:/usr/local/dotnet/current:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/local/rvm/bin";
	
   /* kanit edit on 19/6/2003 */  

    //  cmd[ft_strcspn(cmd, "\n")] = '\0';  // Remove trailing newline  

	 //   if (cmd[0] != "\n")
	//		 cmd[ft_strcspn(cmd, "\n")] = '\0';

	
 //	cmd[ft_strcspn(cmd, "\n")] = '\0';

        // Tokenize input into arguments
         arg_index = 0;
	     token = ft_strtok(cmd, " ");
	//        token = ft_split(cmd, ' ');
         while (token != NULL) 
	 {
             args[arg_index++] = token;
             token = ft_strtok(NULL, " ");
	  //       token = ft_split(NULL, ' ');
	     
         }
         args[arg_index] = NULL;

         // Exit shell if "exit" command is entered
         /* comment exit Segmentation fault (core dumped)
      if (ft_strncmp(args[0], "exit", ft_strlen(args[0])) == 0 ||\
		                  args[0] == EOF) */
		 
		 if (ft_strcmp(args[0], "exit") == 0)		                
	       {																					
             clean_exit(errno, data);
           } 
		  in_cmd = 42; 
		  in_cmd = exe_builtin_cmd(args, data);
	
	//	  printf("%d status %d errno %d->",in_cmd,status,errno);
	

         // Fork a child process to execute external commands
	if (in_cmd)
	{	 
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
	}



	//	 printf("\nkanit%d\n",errno);

		 return (status);
    }

