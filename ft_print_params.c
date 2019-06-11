#include <unistd.h>

void ft_putchar(char c)
{
	write(1,&c,1);
}

void ft_print_params(char *str)
{
	int i;
	i=0;
	while(str[i]!='\0')
	{
		ft_putchar(str[i]);
		i+=1;
	}
}

int main(int argc, char **argv)
{
	int i;
	i=1;
	while (i<argc)
	{	
		ft_print_params(argv[i]);
		ft_putchar('\n');
		i++;
	}
	return(0);
}
