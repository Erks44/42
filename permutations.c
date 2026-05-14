#include <unistd.h>

void	ft_swap(char *a, char *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_reverse(char *str, int start, int end)
{
	while(start < end)
	{
		ft_swap(&str[start++], &str[end--]);
	}
}

void	ft_sort(char *str)
{
	int i = 0;
	int j, result;

	while(str[i])
	{
		j = i;
		result = j;
		while(str[j])
		{
			if(str[j] < str[result])
				result = j;
			j++;
		}
		ft_swap(&str[i], &str[result]);
		i++;
	}
}

int next_permutation(char *str, int n)
{
	int i = n - 2;
	while(i >= 0 && str[i] >= str[i + 1])
		i--;
	if(i < 0)
		return(0);
	int j = n - 1;
	while(str[i] >= str[j])
		j--;
	ft_swap(&str[i], &str[j]);
	ft_reverse(str, i + 1, n - 1);
	return(1);
}

int main(int ac, char **av)
{
	if(ac != 2 && av[1][0] == '\0')
		return(1);
	ft_sort(av[1]);
	int i = 0;
	while(av[1][i])
		i++;
	do {
		write(1, av[1], i);
		write(1, "\n", 1);
	} while(next_permutation(av[1], i));
	return(0);
}
