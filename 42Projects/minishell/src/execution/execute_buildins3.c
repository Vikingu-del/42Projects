/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_buildins3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:03:54 by eseferi           #+#    #+#             */
/*   Updated: 2023/11/25 13:11:51 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	validate_and_change_directory(char *path)
{
	struct stat	path_stat;

	if (stat(path, &path_stat) != 0)
		return (printf("minishell: cd: %s: No such file or directory\n", \
		path), 1);
	if ((path_stat.st_mode & S_IFMT) != S_IFDIR)
		return (printf("minishell: cd: %s: Not a directory\n", path), 1);
	if (chdir(path) != 0)
		return (printf("minishell: cd: %s: No such file or directory\n", \
		path), 1);
	return (0);
}

static	int	update_pwd(t_data *data)
{
	char	*cwd;
	t_envir	*pwd_env;

	cwd = get_curr_dir();
	if (!cwd)
		return (printf("minishell: error getting current directory\n"), 1);
	pwd_env = find_envir_variable(data, "PWD", 3);
	if (!pwd_env)
		return (free(cwd), 0);
	ft_strdel(&pwd_env->var_value);
	pwd_env->var_value = ft_strdup(cwd);
	return (free(cwd), 0);
}

int	execute_cd(t_data *data, char *path)
{
	if (!path)
	{
		path = get_home_dir();
		if (!path)
			return (printf("minishell: cd: HOME not set\n"), 1);
	}
	if (validate_and_change_directory(path))
		return (1);
	return (update_pwd(data));
}

static int	validate_and_remove_env_var(t_data *data, char *arg)
{
	t_envir	*env_var;
	t_envir	*temp;

	if (ft_isdigit(arg[0]))
		return (printf("minishell: unset: `%s': not a valid identifier\n", \
		arg), 1);
	env_var = find_envir_variable(data, arg, ft_strlen(arg));
	if (env_var)
	{
		temp = env_var;
		if (env_var->prev)
			env_var->prev->next = env_var->next;
		if (env_var->next)
			env_var->next->prev = env_var->prev;
		ft_envdelone(temp, free);
	}
	else
		return (printf("minishell: unset: `%s': not a valid identifier\n", \
		arg), 1);
	return (0);
}

int	execute_unset(t_data *data, t_tree *tree)
{
	char	**args;
	int		i;

	i = 0;
	args = tree->args_array;
	while (args[++i])
	{
		if (validate_and_remove_env_var(data, args[i]))
			return (1);
	}
	return (0);
}
