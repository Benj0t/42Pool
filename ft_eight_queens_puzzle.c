/* **************************************************************************************** */
/*                                                                                          */
/*                                                                      :::      ::::::::   */
/*   ft_dames.c                                                       :+:      :+:    :+:   */
/*                                                                  +:+ +:+         +:+     */
/*   By: bemoreau (ft.mdavid) <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                              +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 23:59:02 by bemoreau (ft.mdavid)            #+#    #+#             */
/*   Updated: 2019/06/27 23:59:02 by bemoreau (ft.mdavid)           ###   ########.fr       */
/* **************************************************************************************** */
/* **************************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void ft_putchar(char c)
{
	write(1,&c,1);
}

void ft_putstr(char *str)
{
	int i;
	i=-1;
	while (str[++i])
		ft_putchar(str[i]);
}

void ft_putnbr(int n)
{
	unsigned int nb;
	nb = n;
	if (n < 0)
	{
		nb = -n;
		ft_putchar('-');
	}
	if (nb >= 10)
	{
		ft_putnbr(nb/10);
		ft_putnbr(nb%10);
	}
	if (nb <10)
		ft_putchar(nb%10 + 48);
}

void ft_putendl(char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
}

int ft_check(char **dame,int j, int i, int a, int b)
{
	int c;
	c = 0;
	while (++c <= 8)
	{
		while (i <= 7 && j <= 7 && i >= 0 && j >= 0)
		{
			if (dame[j][i] == '1')
			{
				return (1);
			}
			if (c == 1 || c == 2 || c == 3)
				i++;
			if (c == 5 || c == 6 || c == 7)
				i--;
			if (c == 7 || c == 8 || c == 1)
				j++;
			if (c == 5 || c == 4 || c == 3)
				j--;
		}
		i = a;
		j = b;
	}
	return (0);
}

int ft_backtrack(char **dame, int i, int j, int c)
{
	int f;
	if (c == 8)
		return (1);	
	while (j <= 7)
	{
		if (ft_check(dame,i,j,i,j))
		{
			i++;
		}
		else
		{
			dame[j][i] = '1';
			if (!(ft_backtrack(dame, 0, j + 1, c + 1)))
			{
				dame[j][i] = '0';
				i++;
			}
			else
			{
				return (1);
			}
			
		}
		if (i == 8)
		{
			i = 0;
			j++;
		}
		
	}
	return(0);
}

void ft_eight_queens(void)
{
	int nb;
	char **dame;
	int i;
	int j;
	int c;

	i=0;
	j=0;
	dame = (char**)malloc(sizeof(char*)*9);
	dame[8] = NULL;
	while (i <= 7)
	{
		dame[i] = (char*)malloc(sizeof(char)*9);
		j=0;
		while (j <= 7)
		{
			dame[i][j] = '0';
			j++;
		}
		dame[i][8] = '\0';
		i++;
	}
	i = 0;
	j = 0;
	c = 0;
	nb = 0;
	ft_backtrack(dame, i +1 , j , c);
	i=0;
	while (i <= 7)
	{
		ft_putendl(dame[i]);
		i++;
	}
}

int main()
{	
	ft_eight_queens();
	return(0);
}