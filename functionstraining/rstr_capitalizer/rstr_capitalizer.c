#include <unistd.h>

int main(int ac, char **av)
{
	if (ac > 1)
	{
		int a = 1;;
		while (a < ac)
		{
			int i = 0;
			while(av[a][i])
			{
				char c;
				if((av[a][i + 1] == ' ' || av[a][i + 1] == '\t' || av[a][i + 1] == '\0') && !(av[a][i - 1] == ' ' || av[a][i - 1] == '\t') && (av[a][i] >= 'a' && av[a][i] <= 'z'))
					c = av[a][i] - 32;
				else if ((av[a][i + 1] == ' ' || av[a][i + 1] == '\t') && (av[a][i - 1] == ' ' || av[a][i - 1] == '\t' || i == 0) && (av[a][i] >= 'a' && av[a][i] <= 'z'))
					c = av[a][i] - 32;
				else if((av[a][i] >= 'A' && av[a][i] <= 'Z') && (av[a][i + 1] != ' ' && av[a][i + 1] != '\t') && av[a][i + 1] != '\0')
					c = av[a][i] + 32;
				else
					c = av[a][i];
				write(1, &c, 1);
				i++;
			}
			a++;
			write(1, "\n", 1);
		}
		return(0);
	}
	write(1, "\n", 1);
}
