/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egjika <egjika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 02:44:20 by egjika            #+#    #+#             */
/*   Updated: 2025/10/15 17:21:28 by egjika           ###   ########.fr       */
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
			return (free(buf), NULL);
		buf[nread] = '\0';
		tmp = ft_strjoin(stash, buf);
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
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_to_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	stash = stash_remainder(stash);
	return (line);
}
