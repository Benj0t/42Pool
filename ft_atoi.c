#include <unistd.h>

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

int main()
{
	char *str;
	str="  -124zizi26 45";
	ft_atoi(str);
	return (0);
}
