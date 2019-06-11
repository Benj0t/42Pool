#include <unistd.h>
#include <stdio.h>

void ft_ft(int *nbr)
{
	*nbr=42;
}

int main()
{
	int nbr;
	nbr=0;
	ft_ft(&nbr);
	printf("%d", nbr);
	return (0);
}
