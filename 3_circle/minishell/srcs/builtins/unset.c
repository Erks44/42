/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbelfki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 11:14:24 by zbelfki           #+#    #+#             */
/*   Updated: 2026/05/26 11:14:30 by zbelfki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_in_env(t_env *env, char *args)
{
	char	var_name[BUFF_SIZE];
	char	env_name[BUFF_SIZE];

	get_env_name(var_name, args);
	while (env && env->next)
	{
		get_env_name(env_name, env->value);
		if (ft_strcmp(var_name, env_name) == 0)
		{
			ft_memdel(env->value);
			env->value = ft_strdup(args);
			return (1);
		}
		env = env->next;
	}
	return (SUCCESS);
}

static void	unset_var(const char *name, t_env **env_ptr)
{
	t_env	*env;
	t_env	*prev;
	size_t	len;

	env = *env_ptr;
	prev = NULL;
	len = ft_strlen(name);
	while (env && env->value)
	{
		if (ft_strncmp(name, env->value, len) == 0
			&& (env->value[len] == '=' || env->value[len] == '\0'))
		{
			if (!prev && !env->next)
			{
				ft_memdel(env->value);
				env->value = NULL;
				return ;
			}
			if (prev)
				prev->next = env->next;
			else
				*env_ptr = env->next;
			ft_memdel(env->value);
			ft_memdel(env);
			return ;
		}
		prev = env;
		env = env->next;
	}
}

int	ft_unset(char **a, t_mini *mini)
{
	int	i;

	i = 1;
	while (a[i])
	{
		unset_var(a[i], &mini->env);
		unset_var(a[i], &mini->secret_env);
		i++;
	}
	return (SUCCESS);
}
