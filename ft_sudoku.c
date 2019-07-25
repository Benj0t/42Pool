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

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
//#include "sudoku.h"

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
    i=-1;
    while(++i < 9)
        str[i] = av[i+1];
}

int ft_check_line(char *str)
{
    int i;
    
    i=0;
    while ((str[i] <= '9' &&str[i] >= '1') || str[i] == '.')
        i++;
    if (i == ft_strlen(str))
        return(1);
    return(-1);
}

int ft_check_numbers(char *str)
{
    int i;
    static int j;

    i=-1;
    while (str[++i])
    {
        if (str[i] <= '9' && str[i] >= '1')
            j++;        
    }
    return((int) j);
}

int     ft_parse(char ***table, int ac, char **av)
{
    int     i;

    i = 0;
    if (ac != 10)
        return(1);
    *table = (char**)malloc(sizeof(char*) * 10);
    (*table)[9] = NULL;
    while (++i < 9)
    {
        if (ft_strlen(av[i]) != 9)
            return(1);
        if (ft_check_line(av[i]) == -1)
            return (1);
        ft_check_numbers(av[i]);
        (*table)[i] = (char*)malloc(sizeof(char) * 10);
        (*table)[i][9] = '\0';
    }
    if (ft_check_numbers("") < 17)
    
        return(1);
    ft_fill(*table, av);
    return (0);
}

int ft_check_cross(char **tab, int x, int y, char c)
{
    int i;
    int j;
    i = 0;
    j = 0;
    while ( i <= 8 )
    {
        if (tab[i][y] == c)
            return(-1);
        i++;
    }
    while (j <= 8)
    {
        if (tab[x][j] == c)
            return(-1);
        j++;
    }
    return(1);
}

int ft_check_bloc(char **tab, int x, int y, char c)
{
    int i;
    int j;

    i = 3*(x/3);
    j = 3*(y/3);
    while (i - 2 <= 3 * (x / 3))
    {
        while (j - 2 <= 3 * (y / 3))
        {
            if (tab[i][j] == c)
                return(-1);
            j++;
        }
        j = 3*(y/3);
        i++;
    }
    return(1);
}

int ft_check(char **tab, int x, int y, char c)
{
    if (tab[x][y] != '.')
        return(-1);
    if (ft_check_bloc(tab, x, y, c) < 0)
        return(-1);
    if (ft_check_cross(tab, x, y, c) < 0)
        return(-1);
    return(1);
}   

int ft_backtrack(char **tab, int i, int j)
{
    char c;
    
    c = '1';
    while (c <= '9')
    {
        j = 0;
        while (tab[i][j] != '.' && tab[i][j] != '\0')
        {
            j++;
            if (j >= 9)
            {
                j=0;
                i++;
                if (i == 9) // ON SE CASSE
                    return(1);      
            }
        }
        if (ft_check(tab, i, j, c) < 0)
        {
            if (c == '9')
                return(-1);
            c++;
        }
        else
        {
            tab[i][j]=c; 
            if (ft_backtrack(tab, i, j+1) < 0)
            {
                tab[i][j] = '.';
                if (c == '9')
                    return (-1);
                c++;
            }
        }
    }
    return(1);
}

int     main(int ac, char **av)
{
    int i;
    int x;
    int y;
    char    **table;
    i = -1;
    x=0;
    y=0;
    if (ac == 10)
    {
        if (ft_parse(&table, ac, av) < 0)
        {
            //printf("Ici les moulineaux\n");
            return (0);
        }
        ft_backtrack(table, x, y);
        //printf("valeur table = %p\n", table);
        while (table[++i])
            printf("%s\n", table[i]);
    }
    return (0);
}