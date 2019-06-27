#include <unistd.h>
#include <stdio.h>
char *ft_strstr(char *str, char *to_find)
{
	int i;
	int j;
	i=-1;
	j=-1;
	while (str[++i])
	{
		if (to_find[++j] == str[i])
		{
			if (to_find[j])
				return(str);
		} 
		else
			j=-1;
	}
	return(NULL);
}

int main()
{
	if (ft_strstr("J adore le caca mais moins le pipi","caca") == NULL)
		write(1,"panormal",8);
	if (ft_strstr("J'adore le caca mais moins le pipi","pipi") != NULL)
		write(1,"normal",6);
	return(0);
}
