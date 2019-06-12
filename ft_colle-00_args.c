#include <unistd.h>

void ft_putchar(char c)
{
	write(1,&c,1);
}

int ft_atoi(char *str)
{
	int i;
	int nbr;
	int neg;
	i = 0;
	neg = 0;
	nbr = 0;
	while (str[i] == ' ' ||str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		neg = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while ('0' <= str[i] && str[i] <= '9')
	{
		nbr= (nbr*10) + (str[i] - '0');
		i++;
	}
	if (neg == 1)
		nbr = -nbr;
		return(nbr);
}

int colle(int x,int y)
{
	int i;
	int j;
	j=1;
	i=1;
	if (x==0 || y==0)
		return(0);
	while (j <= y)
	{
		if (j == 1 || j==y)
		{
			while (i <= x)
			{
				if (i==1 || i==x)
				{
					ft_putchar('o');
					if (i ==x)
						ft_putchar('\n');
				}
				else
				{
					ft_putchar('-');
				}
				i++;
			}
			i=1;
		}
		else
		{
			while (i <= x)
			{
				if (i == 1 || i == x)
				{
					ft_putchar('|');
					if (i == x)
						ft_putchar('\n');
				}
				else
				{
					ft_putchar(' ');
				}
				i++;
			}
			i=1;
		}
		j++;
	}
	return(0);
}

int main(int argc,char **argv)
{
	int x;
	int y;
	if (argc != 3)
		return(0);
	x=ft_atoi(argv[1]);
	y=ft_atoi(argv[2]);
	colle(x,y);
	return(0);
}
