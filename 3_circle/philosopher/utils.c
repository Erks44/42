#include "philosopher.h"

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

long get_time(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return(tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
