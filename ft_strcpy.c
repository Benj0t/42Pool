#include <stdio.h>
#include <unistd.h>

char *ft_strcpy(char *dest,char* src)
{
	int i;
	i=0;
	while (src[i])
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
	src="Je t'encule Therèse, je te prends, je te return contre le mur, je te baise par tous les trous je te défonce, je te mets Thérèse, je te mets";
	dest[500]=ft_strcpy(dest[500],src);
	write(1,dest[500],130);
	return(0);
}
