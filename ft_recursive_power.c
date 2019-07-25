#include <unistd.h>
#include <stdio.h>

int     ft_recursive_power(int nb, int power)
{
    if (power < 0)
        return(0);
    return(power == 0 ? 1 : nb * ft_recursive_power(nb, power-1));
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
        printf("nb = %d\n", ft_recursive_power(ft_atoi(av[1]), ft_atoi(av[2])));
    return (0);
}