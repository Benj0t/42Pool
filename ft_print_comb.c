/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <unistd.h>

void ft_print_comb(void)
{
	int a;
	int b;
	int c;
	a='0';
	b='1';
	c='2';
	while (a<='7')
	{
		while (b<='8')
		{
			while (c<='9')
			{
                write(1,&a,1);
                write(1,&b,1);
                write(1,&c,1);
                if (a<'7')
                    write(1,",",1);
		            write(1," ",1);
				c++;
			}
			b++;
			c=b+1;
		}
		a++;
		b=a+1;
		c=b+1;
		
	}
}
int main()
{
    int i;
    i=0;
	ft_print_comb();
	return(0);
}
