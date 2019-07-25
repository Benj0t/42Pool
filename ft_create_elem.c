#include <stlib.h>
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


int main()
{
    t_list *list;

    list = NULL;
    
    list = ft_add_link(list, "caca");
    printf("%s", list->next);
}