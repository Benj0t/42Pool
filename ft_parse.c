/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 23:18:30 by md4               #+#    #+#             */
/*   Updated: 2019/07/02 00:41:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "sudoku.h"

int ft_strlen(char *str)
{
    int     i;

    i=-1;
    while (str[++i])
        i=i;
    return(i);
}

void ft_fill(char **str, char **av)
{
    int i;
    i=0;
    while(i < 8)
    {  
        str[i] = av[i+1];
        i++;
    }
}

int ft_check_line(char *str)
{
    int i;
    
    i=0;
    while ((str[i] <= '9' &&str[i] >= '0') || str[i] == '.')
        i++;
    if (i == ft_strlen(str))
        return(1);
    return(-1);
}


int     ft_parse(char ***table, int ac, char **av)
{
    int     i;

    i = 0;
    if (ac != 10)
        return(1);
    printf("ici 2\n"); 
    *table = (char**)malloc(sizeof(char*) * 10);
    (*table)[10] = NULL;
    printf("ici 2\n");
    while (++i < 9)
    {
        if (ft_strlen(av[i]) != 9)
            return(1);
        if (ft_check_line(av[i]) == -1)
            return (1);
        (*table)[i] = (char*)malloc(sizeof(char) * 10);
        (*table)[i][10] = '\0';
    }
    printf("ici 2\n");
    ft_fill(*table, av);
    printf("ici 2\n");
    return (0);
}

int     main(int ac, char **av)
{
    int i;
    char    **table;

    i = 0;
    if (ac == 10)
    {
        if (ft_parse(&table, ac, av))
        {
            printf("Ici les moulineaux\n");
            return (0);
        }
        printf("valeur table = %p\n", table);
        while (table[++i])
            printf("%s\n", table[i]);
    }
    return (0);
}
