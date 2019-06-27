#include <unistd.h>
#include <stdio.h>
void ft_putchar(char c)
{
	write(1,&c,1);
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

void ft_convert_arg(char *str)
{
	int i;
	int j;
	int neg;
	i=0;
	j=0;
	neg = 0 ;
	if (str[i] == '-')
		neg =1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		j=(j*10)+(str[i]-'0');
		i++;
	}
	if (neg == 1)
		j = -j;
	if (str == "-2147483648")
		j = -2147483648;
	ft_putnbr(j);
}

int main(int argc,char ** argv)
{
	(void)argc;
	ft_convert_arg(argv[1]);
	return (0);
}
