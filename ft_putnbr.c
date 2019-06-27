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


int main(int argc,char ** argv)
{
	if (argc == 2)
		ft_putnbr(ft_atoi(argv[1]));	
	return (0);
}
