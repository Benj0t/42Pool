#include <unistd.h>

int ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int i;
	i=0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] == s2[i])
			i++;
		else
			return(s1[i]-s2[i]);
	}
	return(0);
}

int main()
{
	unsigned int n;
	n=4;
	if(ft_strncmp("coua","couc",n) < 0)
		write(1,"normal",6);
	else
		write(1,"panormal",8);
	return(0);
}
