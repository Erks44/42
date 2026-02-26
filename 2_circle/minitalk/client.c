/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egjika <egjika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:38:27 by egjika            #+#    #+#             */
/*   Updated: 2026/01/28 16:46:58 by egjika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_char(int pid, unsigned char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(150);
		i--;
	}
}

int	main(int ac, char **av)
{
	int		pid;
	char	*msg;

	if (ac != 3)
	{
		ft_printf("Usage: %s <PID> <message>\n", av[0]);
		return (1);
	}
	pid = ft_atoi(av[1]);
	msg = av[2];
	while (*msg)
	{
		send_char(pid, (unsigned char)*msg);
		msg++;
	}
	send_char(pid, '\0');
	return (0);
}
