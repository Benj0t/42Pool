#include "./includes/lib.h"


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

int ft_tablen(char **tab)
{
    int i;
    i = 0;
    while (tab[i])
    {
        i++;
    }
    return(i);
}

int ft_strlen(char *str)
{
    int i;
    i=0;
    while (str[i])
        i++;
    return(i);
}