#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void    ft_putchar(char c)
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

int ft_check_base(char *str)
{
    int i;

    i=-1;
    if (str[0] == '\0' || str[1] == '\0')
        return(-1);
    while (str[++i])
    {
        if (str[i] == '-' || str[i] == '+')
            return(-1);
        if (!(str[i] > 32 && str[i] < 128 ))
            return(-1);
    }
    return(1);
}

int ft_check_comp(char *str)
{
    int i;
    int j;
    
    i=0;
    j=1;
    if (ft_check_base(str) < 0)
        return(-1);
    while(str[i]) 
    {    
        while (str[++j])
        {
            if (str[i] == str[j])
                return(-1);
        }
        i++;
        j = i+1;
    } 
    return(1);
}

void ft_putnbr_base(int nbr, char *base)
{
    int tmp[42];
    int size;
    int i;

    i=0;
    size = ft_strlen(base);
    if (ft_check_comp(base) > 0)
    {
        if (nbr < 0)
        {
            nbr = -nbr;
            ft_putchar('-');
        }
        while (nbr)
        {
            tmp[i++] = nbr % size;
            nbr /= size;
        }
        while (--i >= 0)
            ft_putchar(base[tmp[i]]);
    }
}

int main()
{
    ft_putnbr_base(-14,"poneyvif");
    return(0);
}