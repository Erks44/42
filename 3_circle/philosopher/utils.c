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

#include <stdio.h>

int main()
{
	char *str = "-42";
	printf("%d\n", ft_atoi(str));
	return 0;
}
