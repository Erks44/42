#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			ft_putchar('2');
			nb = 147483648;
		}
		else
		{
			nb = -nb;
		}
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
	}
	ft_putchar((nb % 10) + '0');
}


int	ft_atoi(char *str)
{
	int i = 0;
	int sign = 1;
	int result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 12))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while(str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	is_number(char *str)
{
	int i = 0;
	while(str[i] <= '9' && str[i] >= '0')
		i++;
	if (str[i] == '\0')
		return(1);
	else
		return (0);
}

int	ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return(i);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int i = 0;
		int c = ft_atoi(av[1]);
		write(1, "1 x ", 4);
		while(av[1][i])
		{
			write(1, &av[1][i], 1);
			i++;
		}
		write(1, " = ", 3);
		ft_putnbr(1 * c);
		write(1, "\n", 1);
		i = 0;
		write(1, "2 x ", 4);
		while(av[1][i])
		{
			write(1, &av[1][i], 1);
			i++;
		}
		write(1, " = ", 3);
		ft_putnbr(2 * c);
		write(1, "\n", 1);
		i = 0;
		write(1, "3 x ", 4);
		while(av[1][i])
		{
			write(1, &av[1][i], 1);
			i++;
		}
		write(1, " = ", 3);
		ft_putnbr(3 * c);
		write(1, "\n", 1);
		i = 0;
		write(1, "4 x ", 4);
		while(av[1][i])
		{
			write(1, &av[1][i], 1);
			i++;
		}
		write(1, " = ", 3);
		ft_putnbr(4 * c);
		write(1, "\n", 1);
		i = 0;
		write(1, "5 x ", 4);
		while(av[1][i])
		{
			write(1, &av[1][i], 1);
			i++;
		}
		write(1, " = ", 3);
		ft_putnbr(5 * c);
		write(1, "\n", 1);
		i = 0;
		write(1, "6 x ", 4);
		while(av[1][i])
		{
			write(1, &av[1][i], 1);
			i++;
		}
		write(1, " = ", 3);
		ft_putnbr(6 * c);
		write(1, "\n", 1);
		i = 0;
		write(1, "7 x ", 4);
		while(av[1][i])
		{
			write(1, &av[1][i], 1);
			i++;
		}
		write(1, " = ", 3);
		ft_putnbr(7 * c);
		write(1, "\n", 1);
		i = 0;
		write(1, "8 x ", 4);
		while(av[1][i])
		{
			write(1, &av[1][i], 1);
			i++;
		}
		write(1, " = ", 3);
		ft_putnbr(8 * c);
		write(1, "\n", 1);
		i = 0;
		write(1, "9 x ", 4);
		while(av[1][i])
		{
			write(1, &av[1][i], 1);
			i++;
		}
		write(1, " = ", 3);
		ft_putnbr(9 * c);
	}
	write(1, "\n", 1);
	return(0);
}
