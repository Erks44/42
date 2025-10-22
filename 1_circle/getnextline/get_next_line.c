/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egjika <egjika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 02:44:20 by egjika            #+#    #+#             */
/*   Updated: 2025/10/22 18:32:29 by egjika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_to_stash(int fd, char *stash)
{
	char	*buf;
	char	*tmp;
	ssize_t	nread;

	if (!stash)
		stash = ft_strdup("");
	nread = 1;
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free(stash), NULL);
	while (!ft_strchr(stash, '\n') && nread > 0)
	{
		nread = read(fd, buf, BUFFER_SIZE);
		if (nread < 0)
			return (free(buf), free(stash), NULL);
		buf[nread] = '\0';
		tmp = ft_strjoin(stash, buf);
		if (!tmp)
			return (free(buf), free(stash), NULL);
		free(stash);
		stash = tmp;
	}
	free(buf);
	return (stash);
}

static char	*extract_line(char *stash)
{
	int		i;
	int		j;
	char	*line;

	if (!stash || !stash[0])
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		line = malloc(i + 2);
	else
		line = malloc(i + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = stash[j];
		j++;
	}
	if (stash[i] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

static char	*stash_remainder(char *stash)
{
	int		i;
	int		j;
	int		len;
	char	*rmn;

	if (!stash || stash[0] == '\0')
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\0')
		return (free(stash), NULL);
	j = i + 1;
	len = ft_strlen(stash + j);
	rmn = malloc(len + 1);
	if (!rmn)
		return (free(stash), NULL);
	while (stash[j])
	{
		rmn[j - i - 1] = stash[j];
		j++;
	}
	rmn[j - i - 1] = '\0';
	free(stash);
	return (rmn);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*g_stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	g_stash = read_to_stash(fd, g_stash);
	if (!g_stash)
		return (NULL);
	line = extract_line(g_stash);
	if (!line)
	{
		free(g_stash);
		g_stash = NULL;
		return (NULL);
	}
	g_stash = stash_remainder(g_stash);
	return (line);
}
