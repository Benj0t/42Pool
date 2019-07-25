#include <unistd.h>

void ft_putchar(char c)
{
    write(1,&c,1);
}

void ft_putnbr(int nb)
{
    unsigned int n;

    n = (nb < 0) ? -nb : nb;
    (nb < 0) ? ft_putchar('-') : NULL;
    (n >= 10) ? ft_putnbr(n/10) : NULL;
    ft_putchar(n%10 + '0');
}

int main()
{
    ft_putnbr(-514642);
    return(0);
}