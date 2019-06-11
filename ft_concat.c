#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char *ft_strlen(int argc,char **argv)
{
	int i;
	int j;
	char *str;
	int len;
	len=0;
	str="";
	i=0;
	j=1;
	while (j<argc)
	{
		while (argv[j][i] != '\0')
		{
			len++;
			i++;
		}
		i=0;
		j++;
	}

	if (!(str = (char *)malloc(sizeof(*str)*(len))))
		return (NULL);
	return (str);
}
char *ft_concat_params(int argc, char **argv)
{
	int j;
	int m;
	char *str;
	int i;
	i=0;
	m =0;
	j=0;
	str=ft_strlen(argc,argv);
	while (j++<argc-1)
	{
		while (argv[j][i] != '\0')
		{
			str[m++]=argv[j][i];
			i++;
		}
		i=0;
	}
	str[m]='\0';
	return(str);
}
int main(int argc, char **argv)
{
	printf("%s", ft_concat_params(argc,argv));
	return(0);
}
