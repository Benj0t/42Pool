#include <unistd.h>

void ft_putchar(char c)
{
	write(1,&c,1);
}

void ft_putstr(char *str)
{
	int i;
	i=0;
	while (str[i])
		ft_putchar(str[i++]);
	ft_putchar('\n');
}

int main(int argc,char **argv)
{
	while (argc > 1)
		ft_putstr(argv[--argc]);
}
