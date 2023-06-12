#ifndef UTILES_H
# define UTILES_H

typedef struct s_list
{
    char            *name;
    char            *var;
    struct s_list   *prev;
    struct s_list   *next;
} t_list;

#endif