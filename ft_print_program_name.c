#include <unistd.h>


void ft_putchar(char c)
{
	write(1,&c,1);
}

void ft_putstr(char *str)
{
	int i;
	i=0;
	while (str[i++])
		ft_putchar(str[i-1]);
}

int main(int argc,char **argv)
{
	(void)argc;
	ft_putstr(argv[0]);
	return(0);
}
