/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 11:18:06 by pnopjira          #+#    #+#             */
/*   Updated: 2023/06/26 06:38:47 by kchatvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILES_H
# define UTILES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_envlist
{
    char            *key;
    char            *value;
    struct s_envlist   *prev;
    struct s_envlist   *next;
}   t_envlist;

typedef struct s_simple_com
{
    int     num_available_args;
    int     num_args;
    char    **args;
    // simple_command();
    // void    insert_arg(char *arg);//The method SimpleCommand
}   t_simple_com;

size_t  ft_strcspn(const char *s, const char *reject);
int    ft_strcmp(char *s1, char *s2);
char *ft_strtok(char* str, const char* delim);
void clean_exit(int code_error, t_envlist *envlist);

// typedef struct s_command
// {
//     int                 num_available_simple_commands;
//     int                 num_simple_commands;
//     t_simple_com     **sim_commands;
//     char                *in_file;
//     char                *out_file;
//     char                *err_file;
//     int                 background;

//     void                prompt();
//     void                print();
//     void                excute();
//     void                clean();

//     command();
//     void                insert_simple_command(t_simple_com *sim_com);// the method Command
//     static t_command    cur_command();
//     static t_simple_com cur_simple_command();
// }   t_command;

#endif