#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
	write(1,&c,1);
}

void ft_putstr(char *str)
{
	int i;
	i=0;
	while (str[i])
	{
		ft_putchar(str[i++]);
	}
	ft_putchar('\n');
}

void ft_swap(char **s1,char **s2)
{
	char *c;
	c=*s1;
	*s1=*s2;
	*s2=c;
}

int ft_cmp(char *str, char *str2)
{
	int i;
	i=0;
	while (str[i] || str2[i])
	{
		if (str[i] != str2[i])
		{
			return(str[i]-str2[i]);
			
		}
		else
			i++;
	}
	return(0);
}


int main(int argc, char** argv)
{
	int j;
	j=1;
	if (argc == 2)
	{
		ft_putstr(argv[1]);
		return(0);
	}
	while (j < argc-1)
	{
		if (ft_cmp(argv[j], argv[j+1]) > 0)
		{
			ft_swap(&argv[j],&argv[j+1]);
			j=1;
		}
		else
			j++;
	}
	j=0;
	while (argc > ++j)
		ft_putstr(argv[j]);
	return(0);
}
