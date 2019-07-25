#include <stdlib.h>
#include "liste.h"

void ft_add_end(t_list **begin_list,void* *data)
{
    t_list  *explor;
    t_list *tmp;

    explor = *begin_list;
    tmp = (t_list*)malloc(sizeof(t_list));
    tmp->data = data;
    tmp->next = NULL;
    if (explor)
    {
        while (explor->next != NULL)
            explor = explor->next;
        explor->next = tmp;
    }
    if (*begin_list == NULL)
        *begin_list = tmp;
    tmp->next = NULL;
}