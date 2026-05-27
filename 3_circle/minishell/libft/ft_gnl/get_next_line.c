/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbelfki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 11:14:24 by zbelfki           #+#    #+#             */
/*   Updated: 2026/05/26 11:14:30 by zbelfki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*buf_join(char *stock, char *buf)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	while (stock != NULL && stock[i] != '\0')
		i++;
	while (buf[j] != '\0')
		j++;
	new = malloc(sizeof(char) * (i + j + 1));
	if (!new)
		return (ft_memdel(stock));
	i = 0;
	j = 0;
	while (stock != NULL && stock[i] != '\0')
		new[i++] = stock[j++];
	j = 0;
	while (buf[j] != '\0')
		new[i++] = buf[j++];
	new[i] = '\0';
	if (stock != NULL)
		ft_memdel(stock);
	return (new);
}

char	*stock_trim(char *stock)
{
	int		i;
	int		j;
	char	*trimmed;

	i = 0;
	j = 0;
	while (stock[i] != '\n' && stock[i] != '\0')
		i++;
	while (stock[i++] != '\0')
		j++;
	trimmed = malloc(sizeof(char) * j + 1);
	if (!trimmed)
		return (ft_memdel(stock));
	i = 0;
	j = 0;
	while (stock[i] != '\n' && stock[i] != '\0')
		i++;
	if (stock[i] == '\0')
		i--;
	i++;
	while (stock[i] != '\0')
		trimmed[j++] = stock[i++];
	trimmed[j] = '\0';
	ft_memdel(stock);
	return (trimmed);
}

char	*get_line(char *stock)
{
	int		i;
	char	*line;

	i = 0;
	while (stock[i] != '\n' && stock[i] != '\0')
		i++;
	line = malloc(sizeof(char) * i + 1);
	if (!line)
		return (ft_memdel(stock));
	i = 0;
	while (stock[i] != '\n' && stock[i] != '\0')
	{
		line[i] = stock[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static int	read_loop(int fd, char **stock, char *buf)
{
	int	r;

	r = 1;
	while (*stock == NULL || !ft_strchr(*stock, '\n'))
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
			return (-1);
		buf[r] = '\0';
		if (r == 0 || buf[r - 1] != '\n')
			ft_printf("  \b\b");
		*stock = buf_join(*stock, buf);
		if (!*stock)
			return (-1);
		if (r == 0)
			break ;
	}
	return (r);
}

int	get_next_line(int fd, char **line)
{
	int			r;
	char		buf[BUFFER_SIZE + 1];
	static char	*stock = NULL;

	if (!line || fd < 0 || BUFFER_SIZE < 1 || read(fd, buf, 0) < 0)
		return (-1);
	r = read_loop(fd, &stock, buf);
	if (r == -1)
		return (-1);
	if (r == 0 && stock && stock[0] == '\0')
	{
		*line = stock;
		return (-2);
	}
	*line = get_line(stock);
	if (!*line)
		return (-1);
	stock = stock_trim(stock);
	if (stock)
		return (-1);
	if (r != 0)
		return (1);
	return (0);
}
