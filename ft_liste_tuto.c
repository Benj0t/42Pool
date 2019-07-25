#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "liste.h"
t_list *ft_add_end(t_list *list,char *data)
{
    t_list  *explor;
    t_list *tmp;

    explor = list;
    tmp = (t_list*)malloc(sizeof(t_list));
    tmp->data = data;
    tmp->next = NULL;
    if (explor)
    {
        while (explor->next != NULL)
            explor = explor->next;
        explor->next = tmp;
    }
    if (list == NULL)
        list = tmp;
    tmp->next = NULL;
    return(list);
}

int     main()
{
    t_list  *list;

    list = NULL;
    printf("Adresse de list avant 1er add_link = %p\n",list);
    list = ft_add_end(list, "ZeraTor");
    list = ft_add_end(list, "MisterMv");
    list = ft_add_end(list, "MdLeBoss");
    list = ft_add_end(list, "Moman");
    list = ft_add_end(list, "Jiraya");
    list = ft_add_end(list, "TrackMania2019");
    
    while (list != NULL)
    {
        printf("valeur de data = %s\n", (char*)list->data);
        list = list->next;
    }
    return (0);
}