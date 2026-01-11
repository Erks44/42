#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac < 2)
		return (0);
	a.v = NULL;
	a.size = 0;
	a.cap = 0;
	b.v = NULL;
	b.size = 0;
	b.cap = 0;
	ps_parse(&a, ac, av);
	if (ps_is_sorted(&a))
	{
		free(a.v);
		return (0);
	}
	if (a.size <= 5)
		sort_small(&a, &b);
	else
		sort_large(&a, &b);
	free(a.v);
	return (0);
}
