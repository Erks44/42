/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egjika <egjika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:47:10 by egjika            #+#    #+#             */
/*   Updated: 2026/01/05 19:22:59 by egjika           ###   ########.fr       */
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

#endif