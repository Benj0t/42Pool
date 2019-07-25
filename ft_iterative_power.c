#include <stdio.h>
#include <unistd.h>

int     ft_iterative_power(int nb, int power)
{
    int a;

    a = nb;
    if (power < 0)
        return(0);
    while (--power > 0)
        nb *= a;
    return(nb);
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
		nbr= (nbr*10) + (str[i++]-'0');
	nbr = (neg == 1 ? -nbr : nbr);
	return (nbr);
}

int main(int ac, char **av)
{
    if (ac == 3)
        printf("nb = %d\n", ft_iterative_power(ft_atoi(av[1]), ft_atoi(av[2])));
    return (0);
}