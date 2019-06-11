#include <unistd.h>
#include <stdio.h>
/*
int ft_dommage(char **dame, int i, int j)
{
	int a;
	int b;
	a=j;
	b=i;
	while (dame[a][b] != '1' && (a<= 8 || b<=8))
	{
		b++;
		a++;
		if (dame[a][b] == '1')
			return(1);
	}
	a=j;
	b=i;
	while (dame[a][b] != '1' && (0 <= a || 0 <= b))
	{
		b--;
		a--;
		if (dame[a][b]=='1')
			return(1);

	}
	a=j;
	b=i;
	while (dame[a][b] != '1' && (0<= a && a<= 8 || 0<=b && b<= 8))
	{
		a++;
		b--;
		if (dame[a][b] == '1')
			return(1);
	}
	while (dame[a][b] != '1' && (0<= a && a<= 8 || 0<=b && b<=8))
	{
		a--;
		b++;
		if (dame[a][b] == '1')
			return(1);
	}
	a=j;
	b=0;
	while (dame[a][b] != '1' && (b <= 8))
	{
		b++;
		if (dame[a][b] == '1')
			return(1);
	}
	a=0;
	b=i;
	while (dame[a][b] != '1' && (a <= 8))
	{
		a++;
		if (dame[a][b] == '1')
			return(1);
	}
	return(0);
}
*/
int ft_check(char dame[9][9],int i, int j, int a, int b)
{
	int c;
	c = 1;
	while (c <= 8)
	{
		while (i <= 8 && j <= 8 && i >= 0 && j >= 0)
		{
			if (c == 1 || c == 2 || c == 3)
				i++;
			if (c == 5 || c == 6 || c == 7)
				i--;
			if (c == 7 || c == 8 || c == 1)
				j++;
			if (c == 5 || c == 4 || c == 3)
				j--;
			if (dame[i][j] == '1')
				return (1);
		}
		c++;
		j = a;
		i = b;
	}
	return (0);
}


int ft_backtrack(char **dame, int i, int j)
{
	int c;
	c=0;
	while (dame[j] != '\0')
	{
		while (dame[j][i] != '\0')
		{
			if (ft_check(dame,i,j,i))
				i++;
			else
			{
				dame[j][i]=1;
				c++;
				i++;
			}
			if (c==8)
				return(1);
		}
		i=0
		j++;
	}
	if (c != 8)
	{
		if (i <=8)
			ft_backtrack(dame,i+1,j);
		else
			ft_backtrack(dame,0,j+1);
	}
	return(0)
}
void ft_dames()
{
	int i;
	int j;
	int nb;
	i = 0;
	j = 0;
	nb = 0;
	char dame[9][9] =	{{'0','0','0','0','0','0','0','0'},
						{'0','0','0','0','0','0','0','0'},
						{'0','0','0','0','0','0','0','0'},
						{'0','0','0','0','0','0','0','0'},
						{'0','0','0','0','0','0','0','0'},
						{'0','0','0','0','0','0','0','0'},
						{'0','0','0','0','0','0','0','0'},
						{'0','0','0','0','0','0','0','0'},
						{'\0'}};
	nb+=ft_baktrak(dame, i ,j);
}

int main()
{
	char dame[9][9] =	{{'0','0','0','0','0','0','0','0'},
						{'0','0','0','0','0','0','0','0'},
						{'0','0','1','0','0','0','0','0'},
						{'0','0','0','0','0','0','0','0'},
						{'0','0','0','0','0','0','0','0'},
						{'0','0','0','0','0','0','0','0'},
						{'0','0','0','0','0','0','0','0'},
						{'0','0','0','0','0','0','0','0'},
						{'\0'}};
	printf("%d",ft_check(dame,0,0,0,0));
	//ft_dames();
	return(0);
}
