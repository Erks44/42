#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int ac, char **av)
{
	if (ac == 4)
	{
		int result;
		if (av[2][0] == '+')
		{
			printf("%d",atoi(av[1]) + atoi(av[3]));
		}
		else if (av[2][0] == '-')
		{
			printf("%d",atoi(av[1]) - atoi(av[3]));
		}
		else if (av[2][0] == '*')
		{
			printf("%d",atoi(av[1]) * atoi(av[3]));
		}
		else if (av[2][0] == '/')
		{
			printf("%d",atoi(av[1]) / atoi(av[3]));
		}
		else
			return(printf("0\n"));
	}
	printf("\n");
}
