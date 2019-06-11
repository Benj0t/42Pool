#include <stdlib.h>
#include <stdio.h>

char *ft_itoa(int nb)
{
	int n;
	int i;
	int neg;
	char *str;
	i=1;
	neg=0;
	if (nb == -2147483648)
		return("-214783648");
	if (nb <0)
	{
		neg=1;
		nb = -nb;
		i++;
	}
	n=nb;
	while (n >= 10)
	{
		n/=10;
		i++;
	}
	if (!(str = (char*)malloc(sizeof(char) * (i))))
		return(NULL);
	if (neg == 1)
		str[0]= '-';
	str[i]='\0';
	while (i--)
	{
		if (str[i] == '-')
			break;
		str[i]=nb%10 + '0';
		nb=nb/10;
	}
	return(str);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return(0);
	int nb;
	nb = atoi(argv[1]);
	printf("%s", ft_itoa(nb));
	return(0);
}
