#include "philosopher.h"

int	ft_atoi(char *str)
{
	int i = 0;
	int result = 0;
	int s = 1;
	while(str[i] == ' ' || str[i] == '\t')
		i++;
	if(str[i] == '+' || str[i] == '-')
	{
		if(str[i] == '-')
			s = -s;
		i++;
	}
	while(str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return(result * s);
}

int	is_number(char *str)
{
	int i = 0;

	while(str[i])
	{
		if(!(str[i] >= '0' && str[i] <= '9'))
			return(1);
		i++;
	}
	return(0);
}

int	check_args(int ac, char **av)
{
	int i = 1;
	if(!(ac <= 6 && ac >= 5))
		return(1);
	while(i < ac)
	{
		if(is_number(av[i]))
			return(1);
		i++;
	}
	return(0);
}

int main(int ac, char **av)
{
	t_simulation sim;

	if(check_args(ac, av) != 0)
		return(1);
	init_simulation(&sim, ac, av);
	if(init_forks(&sim))
		return(1);
	if(init_philosophers(&sim))
		return(1);
	return(0);
}
