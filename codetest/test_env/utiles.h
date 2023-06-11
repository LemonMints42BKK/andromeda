#ifndef UTILES_H
# define UTILES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
    char            *name;
    char            *var;
    struct s_list   *prev;
    struct s_list   *next;
} t_list;

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
t_list  *init_env(int argc, char **argv);
size_t	ft_strlen(const char *s);
#endif