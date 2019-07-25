#ifndef LIST_H
# define LIST_H

typedef struct          s_list
{
    t_list              *next;
    void                *data;
    int                 nb;
}                       t_list;

#endif