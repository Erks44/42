int	ft_atoi_base(const char *str, int str_base)
{
	int i = 0;
	int sign = 1;
	int b;
	int result = 0;

	if(str[i] == '-')
	{
		sign = -sign;
		i++;
	}
	while(str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			b = str[i] - 'A' + 10;
		else if (str[i] >= 'a' && str[i] <= 'z')
			b = str[i] - 'a' + 10;
		else if(str[i] >= '0' && str[i] <= '9')
			b = str[i] - '0';
		else
			break;
		if (b >= str_base)
			break;
		result = result * str_base + b;
		i++;
	}
	return(result * sign);
}
/*#include <stdio.h>
int main(void)
{
	printf("%d\n", ft_atoi_base("-1E", 16));
	return(0);
}*/