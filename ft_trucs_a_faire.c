/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trucs_a_faire.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 16:31:15 by marvin            #+#    #+#             */
/*   Updated: 2019/07/21 16:31:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <unistd.h>

void ft_putchar(char c)
{
    write(1,&c,1);
}

void ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
        ft_putchar(str[i++]);
}

int ft_count(char **tab)
{
    int i;
    i = 0;
    while (tab[i])
        i++;
    return(i);
}

void    ft_putnbr(int nb)
{
    unsigned int n;
    (nb < 0 ? ft_putchar('-') : NULL);
    n = (n < 0 ? -nb : nb);
    (n >= 10 ? ft_putnbr(n/10) : NULL);
    ft_putchar(n%10 + '0');
}
int main(void)
{
    char *tab[] = {"Vider Cahier Ecole", "Rassembler livres d'école", "Trier les habits pour 42", "Préparer Trousse Toilette", NULL};
    int c;
    int i;

    i = -1;
    c = ft_count(tab);
    ft_putstr("Nombre de choses à faire : ");
    ft_putnbr(c);
    ft_putchar('\n');
    while (++i < c)
    {
        ft_putstr("- ");
        ft_putstr(tab[i]);
        ft_putchar('\n');
    }
    return(0);
}

