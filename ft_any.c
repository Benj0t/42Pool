/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 01:00:32 by bemoreau            #+#    #+#             */
/*   Updated: 2019/06/16 01:00:32 by bemoreau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
void	ft_putchar(char c)
{
    write(1,&c,1);
}
void	ft_putnbr(int nb)
{
	unsigned int n;
	if (nb < 0)
	{
		ft_putchar('-');
		n = nb * (-1);
	}
	else
	{
		n = nb;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	if (n <= 9)
	{
		ft_putchar((nb % 10) + 48);
	}
}

int ft_wesh(char *str, char c)
{
    int i;
    i=-1;
    while (str[++i])
    {
        if (str[i] == c)
            return(1);
    }
    return(0);
}

int ft_any(char **tab,int(*f)(char*, char c))
{
    int     i;

    i = -1;
    while(tab[++i])
    {
        if ((*f)(tab[i], 'e') == 1)
            return (1);
    }
    return (0);
}

int main(void)
{
    char *tab[5]= {"pipi" , "caca" , "kiki" , "zyzy" , 0};

    ft_putnbr(ft_any(tab, &ft_wesh));
    return (0);
}