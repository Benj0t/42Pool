#include "./includes/lib.h"


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


char **ft_init(char **tab, int c)
{
	int i;
	int j;

	i=0;
	j=0;
	tab = (char**)malloc(sizeof(char*)* (c+1));
	tab[c] = NULL;
	while (i < c)
	{
		tab[i] = (char*)malloc(sizeof(char)*(c+1));
		j = 0;
		while (j < c)
		{
			tab[i][j] = '0';
			j++;
		}
		tab[i][j] = '\0';
		i++;
	}
    return(tab);
}


int ft_parse(char **tab)
{
    int x;
    int y;

    x = -1;
    y = -1;
    while(tab[++x])
    {
        while(tab[x][++y])
        {
            if (ft_strlen(tab[x]) != 1 || tab[x][y] < '1' || tab[x][y] > '4')
                return(-1);
        }
        y = -1;
    }
    return(1);
}

void ft_putendl(char *str)
{
	int i;
	i = 0;
	while(str[i])
		ft_putchar(str[i++]);
	ft_putchar('\n');
}