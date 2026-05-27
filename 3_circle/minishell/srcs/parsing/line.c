/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbelfki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 11:14:24 by zbelfki           #+#    #+#             */
/*   Updated: 2026/05/26 11:14:30 by zbelfki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*space_alloc(char *line)
{
	char	*new;
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (line[i])
	{
		if (is_sep(line, i))
			count++;
		i++;
	}
	new = malloc(sizeof(char) * (i + 2 * count + 1));
	if (!new)
		return (NULL);
	return (new);
}

char	*space_line(char *line)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = space_alloc(line);
	while (new && line[i])
	{
		if (quotes(line, i) != 2 && line[i] == '$' && i && line[i - 1] != '\\')
			new[j++] = (char)(-line[i++]);
		else if (quotes(line, i) == 0 && is_sep(line, i))
		{
			new[j++] = ' ';
			new[j++] = line[i++];
			if (quotes(line, i) == 0 && (line[i] == '>' || line[i] == '<'))
				new[j++] = line[i++];
			new[j++] = ' ';
		}
		else
			new[j++] = line[i++];
	}
	new[j] = '\0';
	ft_memdel(line);
	return (new);
}

int	quote_check(t_mini *mini, char **line)
{
	if (quotes(*line, 2147483647))
	{
		ft_putendl_fd("minishell: syntax error with open quotes", STDERR);
		ft_memdel(*line);
		mini->ret = 2;
		mini->start = NULL;
		return (1);
	}
	return (0);
}

static void	type_tokens(t_mini *mini)
{
	t_token	*token;

	squish_args(mini);
	token = mini->start;
	while (token)
	{
		if (is_type(token, ARG))
			type_arg(token, 0);
		token = token->next;
	}
}

static char	*read_line(char *prompt)
{
	char	*line;

	if (isatty(STDIN_FILENO))
		return (readline(prompt));
	ft_putstr_fd(prompt, STDERR);
	line = NULL;
	if (get_next_line(STDIN_FILENO, &line) == -2)
		return (NULL);
	return (line);
}

void	parse(t_mini *mini)
{
	char	*line;
	char	*prompt;

	signal(SIGINT, &sig_int);
	signal(SIGQUIT, &sig_quit);
	if (mini->ret)
		prompt = "🤬 \033[0;36m\033[1mminishell ▸ \033[0m";
	else
		prompt = "😎 \033[0;36m\033[1mminishell ▸ \033[0m";
	line = read_line(prompt);
	if (!line)
	{
		mini->exit = 1;
		mini->start = NULL;
		ft_putendl_fd("exit", STDERR);
		return ;
	}
	if (g_sig.sigint == 1)
		mini->ret = g_sig.exit_status;
	if (isatty(STDIN_FILENO) && *line)
		add_history(line);
	if (quote_check(mini, &line))
		return ;
	line = space_line(line);
	if (line && line[0] == '$')
		line[0] = (char)(-line[0]);
	mini->start = get_tokens(line);
	ft_memdel(line);
	type_tokens(mini);
}
