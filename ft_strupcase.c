#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *str)
{
	int i;
	i=0;
	while (str[i++]){}
	return(i);
}

char *ft_strupcase(char *str)
{
	int i;
	i=-1;
	while (str[++i])
	{
		if (97 <= str[i] && 122 >= str[i])
			str[i] = str[i]-32;
	}
	return(str);
}

int main()
{
	char str[]="caca pipi";
	printf("%s", ft_strupcase(str));
	return(0);
}
