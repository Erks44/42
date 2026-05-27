/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbelfki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 11:14:24 by zbelfki           #+#    #+#             */
/*   Updated: 2026/05/26 11:14:30 by zbelfki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_error(char **args)
{
	ft_putstr_fd("cd: ", 2);
	if (args[2])
		ft_putstr_fd("string not in pwd: ", 2);
	else
	{
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putendl_fd(args[1], 2);
}

static char	*get_env_path(t_env *env, const char *var, size_t len)
{
	char	*oldpwd;

	while (env && env->next != NULL)
	{
		if (ft_strncmp(env->value, var, len) == 0)
		{
			oldpwd = ft_strdup(env->value + len + 1);
			return (oldpwd);
		}
		env = env->next;
	}
	return (NULL);
}

static char	*get_path_by_option(int option, t_env *env)
{
	char	*env_path;

	env_path = NULL;
	if (option == 0)
	{
		update_oldpwd(env);
		env_path = get_env_path(env, "HOME", 4);
		if (!env_path)
			ft_putendl_fd("minishell : cd: HOME not set", STDERR);
	}
	else if (option == 1)
	{
		env_path = get_env_path(env, "OLDPWD", 6);
		if (!env_path)
			ft_putendl_fd("minishell : cd: OLDPWD not set", STDERR);
		else
			update_oldpwd(env);
	}
	return (env_path);
}

static int	go_to_path(int option, t_env *env)
{
	int		ret;
	char	*env_path;

	env_path = get_path_by_option(option, env);
	if (!env_path)
		return (ERROR);
	ret = chdir(env_path);
	if (ret == 0)
		update_pwd(env);
	ft_memdel(env_path);
	return (ret);
}

int	ft_cd(char **args, t_env *env)
{
	int		cd_ret;

	if (!args[1])
		return (go_to_path(0, env));
	if (ft_strcmp(args[1], "-") == 0)
		cd_ret = go_to_path(1, env);
	else
	{
		update_oldpwd(env);
		cd_ret = chdir(args[1]);
		if (cd_ret < 0)
			cd_ret *= -1;
		if (cd_ret != 0)
			print_error(args);
		else
			update_pwd(env);
	}
	return (cd_ret);
}
