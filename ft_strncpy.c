#include <stdio.h>
#include <unistd.h>

int ft_strlen(char *str)
{
	int i;
	i=0;
	while (str[i++]){}
	return(i);
}


char *ft_strncpy(char *dest,char* src, unsigned int n)
{
	unsigned int i;
	i=0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i]='\0';
	return(dest);
}

int main()
{
	char *src;
	char *dest[500];
	unsigned int limit;
	limit=5;
	src="Je t'encule Therèse, je te prends, je te return contre le mur, je te baise par tous les trous je te défonce, je te mets Thérèse, je te mets";
	dest[500]=ft_strncpy(dest[500],src,limit);
	write(1,dest[500],limit);
	return(0);
}
