#include <unistd.h>
void ft_putchar(char c)
{
	write(1,&c,1);
}

void	ft_print_all(int a, int b)
{
	ft_putchar(a/10 + '0');
	ft_putchar(a%10 + '0');
	ft_putchar(' ');
	ft_putchar(b/10 + '0');
	ft_putchar(b%10 + '0');
	if (!(a == 98 && b == 99))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}
void	ft_print_comb2(void)
{
	int a;
	int b;

	a=-1;
	b=-1;
	while (++a<= 98)
	{
		while (++b <= 99)
			ft_print_all(a,b);
		b=a+1;
	}
}

int main(void)
{
	ft_print_comb2();
	return(0);
}
