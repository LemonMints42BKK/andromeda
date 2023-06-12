#ifndef UTILES_H
# define UTILES_H

struct s_list
{
    char            *name;
    char            *var;
    struct s_env    prev;
    struct s_env    next;
} t_list;

#endif