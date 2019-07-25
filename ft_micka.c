/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_micka.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 01:56:05 by marvin            #+#    #+#             */
/*   Updated: 2019/07/15 01:56:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
    write(1,&c,1);
}

void ft_putstr(char *str)
{
    int i;
    i=0;
    while (str[i])
    {
        ft_putchar(str[i]);
        i++;
    }
}

int ft_strlen(char *str)
{
    int i;
    
    i = 0;
    while (str[i])
    {
        i++;
    }
    return(i);
}

int my_atoi(char *str)
{
	int i;
	int nbr;
	int stack;

    stack = 0;
    i=0;
    while (str[i])
    {
        nbr = 0;
        while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
            nbr = nbr*10 + (str[i++] - '0');
        stack += nbr;
        i++;
    }
    return(stack);
}

int ft_micka(char **tab)
{
    int i;
    int nb;
    nb = 0;
    i = 1;
    while (i < 4)
    {
        nb = nb + my_atoi(tab[i]);
        i++;
    }
    return(nb);
}



int main(int argc, char **argv)
{
    int nb;

    if (argc == 4)
    {
        if((nb = ft_micka(argv)) == 42)
        {
            ft_putstr("OK");
            ft_putchar('\n');
        }
        else
            ft_putchar('\n');
    }
    else
        ft_putchar('\n');
    return(0);
}