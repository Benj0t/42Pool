#include <unistd.h>
#include <stdio.h>
void ft_putchar(char c)
{
	write(1,&c,1);
}

void ft_putnbr(int n)
{
	if (n >= 10)
	{
		ft_putnbr(n/10);
		ft_putnbr(n%10);
	}
	if (n <10)
	{
		ft_putchar(n%10 + 48);
	}
}

void ft_caca(char **argv)
{
	int i;
	int j;
	i=0;
	j=0;
	while (argv[1][i] != '\0')
	{
		j=(j*10)+(argv[1][i]-'0');
		i++;
	}
	ft_putnbr(j);
}

int main(int argc,char ** argv)
{
	(void)argc;
	ft_caca(argv);
	return (0);
}
