/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbelfki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 11:14:24 by zbelfki           #+#    #+#             */
/*   Updated: 2026/05/26 11:14:30 by zbelfki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		count++;
		while (s[i] != c && s[i] != '\0')
			i++;
		while (s[i] == c)
			i++;
	}
	return (count);
}

static int	letter_count(char const *s, char c, int index)
{
	int		count;

	count = 0;
	while (s[index] != c && s[index] != '\0')
	{
		count++;
		index++;
	}
	return (count);
}

static void	fill_word(char *word, char const *s, int *k, char c)
{
	int	j;

	j = 0;
	while (s[*k] != c && s[*k] != '\0')
		word[j++] = s[(*k)++];
	word[j] = '\0';
	while (s[*k] == c)
		(*k)++;
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!s || !c)
		return (NULL);
	tab = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!tab)
		return (NULL);
	while (s[k] == c)
		k++;
	while (s[k] != '\0')
	{
		tab[i] = malloc(sizeof(char) * letter_count(s, c, k) + 1);
		if (!tab[i])
			return (NULL);
		fill_word(tab[i], s, &k, c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
