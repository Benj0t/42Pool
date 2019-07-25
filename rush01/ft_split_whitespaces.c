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

#include "./includes/lib.h"

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