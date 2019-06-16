#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void ft_putchar(char c)
{
	write(1,&c,1);
}

void	ft_putstr(char *str)
{
	int i;
	i=-1;
	while (str[++i])
		ft_putchar(str[i]);
}
char *ft_strdup(char *src)
{
	char *str;
	int i;
	int j;
	
	j=0;
	i=0;
	while (i < src[i])
		i++;
	if (!(str = (char*)malloc(sizeof(*str) * (i))))
		return(0);
	while (j<i)
	{
		str[j] = src[j];
		j++;
	}
	return(str);
}

int main()
{
	char *str;
	char *str2;
	str="Coucou Elias Aachach";
	str2=ft_strdup(str);
	ft_putstr(str2);
	free(str2);
	return(0);
}
