#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *str)
{
	int i;
	i=0;
	while (str[++i] != '\0'){}
	return(i);
}

int main(void)
{
	char *str;
	int i;
	str="coucou";
	i=ft_strlen(str);
	printf("%i", i);
	return(0);
}
