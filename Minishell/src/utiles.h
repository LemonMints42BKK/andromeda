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

#endif