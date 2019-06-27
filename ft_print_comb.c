#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
	write(1,&c,1);
}

void ft_putstr(char a,char b, char c)
{
	ft_putchar(a);
	ft_putchar(b);
	ft_putchar(c);
	if (!(a == '7' && b == '8' && c == '9'))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}

}

void ft_print_comb(void)
{
	char a;
	char b;
	char c;

	a = ('0' -1);
	b = '0';
	c = '1';
	while (a++ <= '6')
	{
		while (++b <= '8')
		{
			while (++c <= '9')
				ft_putstr(a,b,c);
			c = b+1;
		}
		b=a+1;
		c=b+1;
	}
}

int main(void)
{
	ft_print_comb();
	return(0);
}
