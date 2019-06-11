#include <unistd.h>

void ft_putchar(char c)
{
	write(1,&c,1);
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

int main()
{
	colle(50,50);
	return(0);
}
