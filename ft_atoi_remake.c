#include<stdio.h>

int ft_atoi(char *str)
{
    int nb;
    int neg;
    int i;

    nb = 0;
	i = 0;
    while(str[i] == ' ' || str[i]== '\n' || str[i] == '\t'|| str[i] == '\v' || 
			str[i] == '\f' || str[i] == '\r')
        i++;
    neg = (str[i] == '-' ? 1 : 0);
    if (str[i] == '+' || str[i] == '-')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
        nb = nb * 10 + (str[i++] - '0');
    return(neg == 1 ? -nb : nb);     
}

int main(int argc, char **argv)
{
    if (argc == 2)
        printf("Return de atoi : %d",ft_atoi(argv[1]));    
    return(0);
}  