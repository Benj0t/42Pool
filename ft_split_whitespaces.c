/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 01:53:44 by marvin            #+#    #+#             */
/*   Updated: 2019/07/02 01:53:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void ft_putchar(char c)
{
    write(1,&c,1);
}

int ft_strlen(char *str)
{
    int i;
    i=-1;
    while (str[++i])
    {}
    return(i);
}

void ft_fill(char *tab, char *str, int n)
{
    static int i;
    int j;

    j=0;
    while  (str[i] == '\n' || str[i] == '\t' || str[i] == ' ' && str[i] != '\0')
        i++;
    while (str[i] != '\0' && j <= n)
    {    
        if (str[i] == '\n' || str[i] == '\t' || str[i] == ' ' && str[i] != '\0')
            i++;
        else
        {
            tab[j] = str[i++];
            if (j < n)    
                j++;
            if (j >= n)
                return;
        }
    }    
}

int ft_count_letters(char *str)
{
    static int i;
    int j;
    j=0;
    while  (str[i] == '\n' || str[i] == '\t' || str[i] == ' ' && str[i] != '\0')
        i++;
    while (str[i] != '\n' && str[i] != '\t' && str[i] != ' ' && str[i] != '\0')
    {   
        j++;
        i++;
    }
    while  (str[i] == '\n' || str[i] == '\t' || str[i] == ' ' && str[i] != '\0')
        i++;
    return(j);
}

void ft_skip_whitespaces(char *str, int *j)
{
    int i;
    
    i=0;
    while (str[i])
    {
        if (str[i] != '\n' && str[i] != '\t' && str[i] != ' ' && str[i] != '\0') 
            *j = *j + 1;
        while (str[i] != '\n' && str[i] != '\t' && str[i] != ' '  && str[i] != '\0')
            i++;
        while (str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
            i++;
    }
}

char **ft_split_whitespaces(char *str)
{
    int i;
    int j;
    int h;
    char **tab;

    i=0;
    ft_skip_whitespaces(str, &i);
    h=0;
    j=-1;
    if (!(tab = (char**)malloc(sizeof(char*) * (i+1))))
		return (NULL);
    tab[i] = '\0';
    while (++j < i)
    {
        h = ft_count_letters(str);
        if (!(tab[j] = (char*)malloc(sizeof(char) * (h+1))))
		    return (NULL);
        tab[j][h] = '\0';
        ft_fill(tab[j], str, h);
    }
    return(tab);
}

int main(int ac, char **av)
{
    int i;
    int j;
    char **tab;
    i=0;
    j=0;
    tab = ft_split_whitespaces(av[1]);
    while (tab[i])
    {   
        while (tab[i][j])
        {
            ft_putchar(tab[i][j]);
            j++;
        }
        ft_putchar('\n');
        j=0;
        i++;
    }
    if (ac == 2)
        ft_split_whitespaces(av[1]);
    return(0);
}