/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:50:43 by eseferi           #+#    #+#             */
/*   Updated: 2023/11/26 14:14:56 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

pid_t	g_child_pid = 0;

int	main(int argc, char **argv, char *envp[])
{
	t_data			*data;
	char			**env;

	(void)argc;
	(void)argv;
	data = NULL;
	env = NULL;
	printbanner();
	if (!*envp)
	{
		env = create_envp();
		init_data(&(data), env);
	}
	else
		init_data(&(data), envp);
	handle_signal();
	start_loop(data);
	if (env)
		free_2darray(env);
	free_data(data);
	return (0);
}

char	**create_envp(void)
{
	char	**envp;
	char	cwd[PATH_MAX];

	envp = malloc(sizeof(char *) * 4);
	if (!envp)
		exit(1);
	envp[0] = ft_strdup("SHLVL=1");
	envp[1] = ft_strdup("PATH=/bin/");
	if (getcwd(cwd, sizeof(cwd)))
		envp[2] = ft_strjoin("PWD=", cwd);
	else
	{
		ft_putstr_fd("getcwd() error\n", 2);
		free_2darray(envp);
		exit(1);
	}
	envp[3] = NULL;
	return (envp);
}

void	printbanner(void)
{
	printf("\n\t%s\
	███╗   ███╗██╗███╗   ██╗██╗ ██████╗██╗   ╔██╗╔████████╗██╗%s\n", \
	CYAN, END);
	printf("\t%s\
	██╔████╔██║██║██╔██╗ ██║██║██╔════╝██╝   ╚██╝║██══════╝██║%s \n", \
	BLUE, END);
	printf("\t%s\
	██║╚██╔╝██║██║██║╚██╗██║██║╚█████╗ █████████╗║████████╗██║%s \n", \
	GREEN, END);
	printf("\t%s\
	██║ ╚═╝ ██║██║██║  ╚███║██║ ╚═══██╗██╔═══╗██║║██╔═════╝██║%s\n", \
	BLUE, END);
	printf("\t%s\
	██║     ██║██║██║   ╚██╝██║██████╔╝██║   ║██║║████████╗████████╗%s\n", \
	CYAN, END);
	printf("\t%s\
	╚═╝     ╚═╝╚═╝╚═╝    ╚═╝═╝╚══════╝ ╚═╝	  ╚══╝╚═══════╝╚═══════╝%s\n", \
	CYAN, END);
	printf("%s\n\t\t\tBy: ipetrunin%s\t\t\t   %sBy: eseferi%s\n", BLUE, \
	END, GREEN, END);
	printf("\t\t  ────────────────────── {.⋅ ✯&&✯ ⋅.}───────────────────────\
	\n\n");
}
