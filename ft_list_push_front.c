#include <stdlib.h>
#include "liste.h"

t_list *ft_create_elem(char *str)
{
    t_list *list;
    list = (t_list *)malloc(sizeof(t_list));
    if (list)
    {
        list->data = str;
        list->next = NULL;
    }
    return(list);
}
void ft_list_push_front(t_list **begin_list, void *data)
{
    t_list *tmp;
    if (*begin_list)
    {    
        tmp = ft_create_elem(data);
        tmp->next = *begin_list;
        *begin_list->next = tmp;
    }
    else
        begin_list = ft_create_elem(data);
}

int ft_check(char *str)
{
    int i;
    int j;
    
    i=0;
    j=0;
    if (str[0] == '\0' || str[1] == '\0')
        return(-1);
    while(str[i]) 
    {    
        if (str[i] == '-' || str[i] == '+')
            return(-1);
        if (str[i] < 32 || str[i] > 126)
            return(-1);
        write(1,"coucou",6);
        while (str[j])
        {
            if (str[i] == str[j])
                return(-1);
            j++;
        }
        i++;
        j = i+1;
    } 
    write(1,"coucou",6);
    return(1);
}