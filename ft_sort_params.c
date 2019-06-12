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

void ft_swap(char **s1,char **s2)
{
	char *c;
	c=*s1;
	*s1=*s2;
	*s2=c;
}

int ft_strcmp(char *s1, char *s2)
{
	int i;
	i=0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return(s1[i]-s2[i]);
		else
			i++;
	}
	return(0);
}

int main(int argc, char **argv)
{
	int i;
	i=0;
	if (argc == 2)
	{
		ft_putstr(argv[1]);
		return(0);
	}
	while (++i < argc-1)
	{
		if (ft_strcmp(argv[i],argv[i+1]) > 0 )
		{
			ft_swap(&argv[i],&argv[i+1]);
			i=0;
		}
	}
	i=0;
	while (i++ < argc-1)
		ft_putstr(argv[i]);
}
