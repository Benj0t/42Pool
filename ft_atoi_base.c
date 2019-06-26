/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 22:36:46 by marvin            #+#    #+#             */
/*   Updated: 2019/06/27 00:01:12 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int  ft_strlen(char *str)
{
    int  len;

    len = 0;
    if (!str)
        return (0);
    while (str[len])
        len++;
    return (len);
}

int     ft_check(char *str, int nb)
{
    int i;
    i = -1;
    while (str[++i]) 
    {
        if (str[i] == '-' || str[i] == '+')
            return (-1);
        if (str[i] >= '0' && str[i] <= '9')
        {
            if (str[i] - '0' > nb-1)
                return (-1);
        }
        if (str[i] >= 'a')
        {
            if (str[i] - 'a' > nb-1)
                return (-1);
        }
    }
    return (0); 
}

int ft_skipwspace(char *str)
{
    int i;

    i = 0;
    while(str[i] == ' ' || str[i]== '\n' || str[i] == '\t'|| str[i] == '\v' || 
			str[i] == '\f' || str[i] == '\r')
			i++;
    return(i);
}

int     ft_power(int nb, int pow)
{
    int     result;

    result = 1;
    if (pow == 0)
        return (1);
    while (--pow > 0 )
        result *= nb;
    return(result);
}

int ft_convert_1(char *str, int base)
{
    int result;
    int i;
    int sign;
    int pow;
    int len;
    
    pow = 0;
    sign = 0;
    result = 0;
    i = ft_skipwspace(str);
	if (str[i] == '-')
		sign=1;
	if (str[i] == '+' || str[i] == '-' )
		i++;
    if (ft_check(str + i, base) == -1)
        return(-1);
    pow = ft_strlen(str+i);
    while (str[i])
    {
        if (str[i] >= '0' && str[i] <= '9')
            result = result + (str[i] - '0') * ft_power(base, pow);
        if  (str[i] >= 'a' && str[i] <= ('a'+(base-11)))
            result = result + (str[i] - 'a' +10) * ft_power(base, pow);
        pow--;
        i++;
    }
    if (sign == 1)
        result = -result; 
    return (result);
}


void    ft_strlowercase(char *str)
{
    int i;
    i=-1;
    while(str[++i])
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
    }
}

int main(int ac, char **av)
{
    char *str;

    if (ac == 2)
    {
        if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(av[1])+1))))
            return(0);
        str=av[1];
        ft_strlowercase(str);
        printf("valeur de str(%s) en base (%d) est = %d\n", str, 2, ft_convert_1(str, 2));
    }
    return(0);
}