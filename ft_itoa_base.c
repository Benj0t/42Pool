/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 15:35:24 by marvin            #+#    #+#             */
/*   Updated: 2019/06/30 15:35:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void ft_putchar(char c)
{
    write(1,&c,1);
}

void ft_putendl(char *str)
{
    int i;
    i=-1;
    while (str[++i])
        ft_putchar(str[i]);
    ft_putchar('\n');
}


char *itoa_base(int nb, int base)
{
    int i;
    int j;
    char *str;
    i=0;
    j=nb;
    while ((j/10) >= 10)
        i++;
    if (!(str=(char *)malloc(sizeof(char) * (i+1))))
        return(NULL);
	i=-1;
	while (nb >= 10)
	{
		str[++i]= (nb%10 * ft_power(base))
		nb = nb/10;
	}
}

int ft_atoi(char *str)
{
	int i;
	int neg;
	int nbr;
	i=0;
	neg=0;
	nbr=0;
	while(str[i] == ' ' || str[i]== '\n' || str[i] == '\t'|| str[i] == '\v' || 
            str[i] == '\f' || str[i] == '\r')
			i++;
    if (str[i] == '-')
		neg=1;
	if (str[i] == '+' || str[i] == '-' )
		i++;
	while('0' <= str[i] && str[i] <= '9')
	{
		nbr= (nbr*10) + (str[i]-'0');
		i++;
	}
	if (neg == 1)
		nbr = -nbr;
	return (nbr);
}

int main(int ac, char **av)
{
    int base;
    int nb;
    //ft_itoa_base(nb, 16);
    if (ac == 3)
    {
        nb = ft_atoi(av[1]);
        base = ft_atoi(av[2]);
        ft_itoa_base(nb,base);
    }
    return(0);
}
