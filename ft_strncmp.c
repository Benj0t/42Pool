#include <unistd.h>

int ft_strcmp(char *s1, char *s2)
{
	int i;
	i=0;
	while (s1[i] || s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			return(s1[i]-s2[i]);
	}
}

int main()
{
	if(ft_strcmp("coucou","J'adore le zbobu") < 0)
		write(1,"normal",6);
	else
		write(1,"panormal",8);
	return(0);
}
