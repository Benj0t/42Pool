#include <unistd.h>
#include <stdio.h>

int    ft_iterative_fatorial(int nb)
{
    int i;
    int a;

    i = 1;
    a = 1;
    if ((nb <= 0) | (nb >= 14))
    {
        nb = 0;
        return(nb);
    }

    while (i <= nb)
    {
        a = a*i;
        i++;
    }
    nb = a;
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
	{
		nbr= (nbr*10) + (str[i]-'0');
		i++;
	}
	if (neg == 1)
		nbr = -nbr;
	return (nbr);
}

int        main(int ac, char **av)
{
    if (ac == 2)
        printf("nb = %d\n", ft_iterative_fatorial(ft_atoi(av[1])));
    return (0);
}