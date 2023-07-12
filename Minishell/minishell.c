/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:37:07 by kchatvet          #+#    #+#             */
/*   Updated: 2023/07/12 04:56:06 by kchatvet         ###   ########.fr       */
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
	int in_cmd;
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
             clean_exit(errno, envlist);
           } 
		  in_cmd = 42; 
		  in_cmd = exe_builtin_cmd(args, env);
	
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

   

	


int	main(int argc, char **argv, char **envp)
{
	char			cmd[MAX_COMMAND_LENGTH];
	t_envlist		*envlist;
	t_simple_com	*sim_cmd;
	int status;
	int ct;
    t_andro data;

	
  	get_env(&envlist, envp);
		

	
   // cmd_cd(shell_var);
   
    getcwd(data.user_path, sizeof(data.user_path));
	enable_signals();
	andro_rd_history(data);
//    namep = cmd_pwd();
//    printf("%s",namep);
//    cmd_pwd();

    
    printf("Hi %s\n", data.user_path);
   
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
	 ct = 0;
	 cmd[0] = '\0';
	 	 	
//	 myfgets(cmd, MAX_CMD_LENGTH, stdin);  // Read user input	
 while (1)
    {
	
      //  myfgets(cmd, MAX_CMD_LENGTH, stdin);  // Read user input
		
//		if (status != 2 ) //|| status != 131)
//		{
	//	  printf("\033[0;92mAn\033[0;33mdro\033[0;91mme\033[0;95mda\033[0;34m$\033[0m ");
	/*     if (status == 2 )
		 { 
			ct++;
			if (ct == 2)
			{
			  status = 0;
			  ct = 0;
			}
		 }
	*/	 
      
     //   if (status != 2 )
	//	{
           myfgets(cmd, MAX_CMD_LENGTH, stdin, data);  // Read user input
          
	//	}
	//	else 
	//	{
		  status = 0;	
	//	}
		    
//		}
	//  	myfgets(cmd, MAX_CMD_LENGTH, stdin);  // Read user input
  /*   handdle check falut */
		   if (cmd[0] != '\0')
		     {
				    status = execute(&cmd[0], envlist, envp);
		      } 	
/*   create in prompt
//	  if (cmd[0] == '\0' && (status == 2 )) //|| status == 131))
       if  (status == 2 ) //|| status == 131))
      {
         //  printf("Q\n");
         //   rl_replace_line("kkw", 0);
         //    rl_redisplay();
         //    printf("\n");
      //     status = 0;
   //       printf("Q\n");
       }      
    
*/
	//    printf("status at mini %d", status);
	/*/   while  (status == 2 )
	   {
	        status = execute(&cmd[0], envlist, envp);
			status = 0;
			break;
	   }
	  */ 
	  //  printf("status at mini %d", status);
	//    printf("\nB\n");	    
	    cmd[0] = '\0';


	}		
     
  //  return (0);
//}

	

/*  move to clean_exit
	while (envlist)
	{
		free_t_envlist(&envlist);
		envlist = envlist->next;
	}
 */   
	 clean_exit(errno, envlist);
}
