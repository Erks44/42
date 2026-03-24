#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return(i);
}

void    ft_swap(char *a, char *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void	sort(char *str)
{
	int i = 0;
	int j;
	int result = 0;
	while(str[i])
	{
		j = i;
		result = j;
		while(str[j])
		{
			if (str[j] <= str[result])
				result = j;
		j++;
		}
		ft_swap(&str[i], &str[result]);
		i++;

	}
}


void	ft_reverse(char *str, int start, int end)
{
	while(start < end)
		ft_swap(&str[start++], &str[end--]);
}

int	next_permutation(char *str, int n)
{
	int i = n - 2;
	while(i >= 0 && str[i] > str[i + 1])
		i--;
	if (i < 0)
		return 0;
	int j = n - 1;
	while(str[i] > str[j])
		j--;
	ft_swap(&str[i], &str[j]);
	ft_reverse(str, i + 1, n - 1);
	return 1;
}

#include <stdio.h>

int main(int ac, char **av)
{
	if(ac != 2 || av[1][0] == '\0')
		return(1);
	sort(av[1]);
	int n = ft_strlen(av[1]);

	write(1, av[1], n);
	write(1, "\n", 1);
	while(next_permutation(av[1], n))
	{
		write(1, av[1], n);
		write(1, "\n", 1);
	}
	return (0);
}
