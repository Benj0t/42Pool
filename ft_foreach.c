/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 00:23:28 by marvin            #+#    #+#             */
/*   Updated: 2019/06/16 00:49:28 by md4              ###   ########.fr       */
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

void	ft_putnbr_plus_1(int nb)
{
	unsigned int n;

    nb = nb + 1;
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

void    ft_foreach(int *tab, int length, void(*f)(int))
{
    int     i;
    i = -1;
    while (++i < length)
        (*f)(tab[i]);
}

int     main(void)
{
    int tab[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 42};
    ft_foreach(tab, 10, &ft_putnbr_plus_1);
    //ft_foreach(tab, &ft_putnbr(int nb));
    return (0);
}