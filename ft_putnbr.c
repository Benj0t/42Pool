void	ft_putchar(char c);

void	ft_putnbr(int nb)
{
	unsigned int n;
	if (nb < 0)
	{
		ft_putchar('-');
		n = nb * (-1);
	}
	else
	{
		n = nb;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	if (n <= 9)
	{
		ft_putchar((nb % 10) + 48);
	}
}
