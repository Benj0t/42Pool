#include <unistd.h>
char *ft_strupcase(char *str)
{
	int i;
	i=-1;
	while (str[i++] != '\0')
	{
		if ('A' <= str[i] <= 'Z')
			str[i] += 32;
	}
	return(str);
}

int main()
{
	char *str;
	str="caca PIPI \n popo";
	str = ft_strupcase(str);
	write(1,str,16);
	return(0);
}
