#include <stdlib.h>
#include <stdio.h>

void	print_set(int *set, int size)
{
	int i = 0;
	if(i >= size)
	{
		printf("\n");
		return ;
	}
	printf("%d", set[i]);
	i++;
	while(i < size)
	{
		printf(" %d", set[i]);
		i++;
	}
	printf("\n");
	return ;
}

int calculate(int *set, int size)
{
	int i = 0;
	int result = 0;
	while(i < size)
	{
		result += set[i];
		i++;
	}
	return(result);
}

void	power_set(int n, int *set, int set_index, int *ret, int ret_index, int max_size)
{
	if(set_index == max_size)
	{
		if((calculate(ret, ret_index)) == n)
			print_set(ret, ret_index);
		return ;
	}
	power_set(n, set, set_index + 1, ret, ret_index, max_size);
	ret[ret_index] = set[set_index];
	power_set(n, set, set_index + 1, ret, ret_index + 1, max_size);
}

int main(int ac, char **av)
{
	int n;
	int *set;
	int *ret;
	int i;
	
	if(ac < 3)
		return(2);
	av[ac] = NULL;
	if(!(set = malloc(sizeof(int) * ac - 2)))
		return(1);
	if(!(ret = malloc(sizeof(int) * ac - 2)))
		return(1);
	n = atoi(av[1]);
	i = 0;
	while(i < ac - 2 && av[i + 2])
	{
		set[i] = atoi(av[i + 2]);
		ret[i] = 0;
		i++;
	}
	power_set(n, set, 0, ret, 0, ac - 2);
	return(0);
}