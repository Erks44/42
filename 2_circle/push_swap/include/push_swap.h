/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylanamonrose <ylanamonrose@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:47:10 by egjika            #+#    #+#             */
/*   Updated: 2026/01/11 16:18:03 by ylanamonros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int	*v;
	int	size;
	int	cap;
}	t_stack;

void	ps_error(void);
void	ps_parse(t_stack *a, int argc, char **argv);
int	ps_atoi_safe(const char *s, int *out);
char	**ft_split(char const *s, char c);
void	ps_sa(t_stack *a);
void	ps_sb(t_stack *b);
void	ps_ss(t_stack *a, t_stack *b);
void	ps_pa(t_stack *a, t_stack *b);
void	ps_pb(t_stack *a, t_stack *b);
void	ps_ra(t_stack *a);
void	ps_rb(t_stack *b);
void	ps_rr(t_stack *a, t_stack *b);
void	ps_rra(t_stack *a);
void	ps_rrb(t_stack *b);
void	ps_rrr(t_stack *a, t_stack *b);
int		ps_is_sorted(t_stack *a);
void	sort_two(t_stack *a);
void	sort_three(t_stack *a);
void	sort_small(t_stack *a, t_stack *b);
void	sort_large(t_stack *a, t_stack *b);

#endif
