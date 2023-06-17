#ifndef UTILES_H
# define UTILES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
    char            *key;
    char            *value;
    struct s_envlist   *prev;
    struct s_envlist   *next;
} t_list;
