#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char *ft_strdup(char *src)
{
	int i;
	int j;
	j=0;
	i=0;
	char *str;
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
	str="Coucou Elias Aachach";
	printf("%s",ft_strdup(str));
	return(0);
}
