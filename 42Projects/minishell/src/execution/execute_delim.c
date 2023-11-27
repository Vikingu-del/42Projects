/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_delim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 02:29:39 by eseferi           #+#    #+#             */
/*   Updated: 2023/11/26 07:58:41 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_temp_filename(t_heredoc_info *info)
{
	char	*counter_str;

	counter_str = ft_itoa(info->heredoc_count);
	info->filename = ft_strjoin_double_free(info->filename, counter_str);
}

int	handle_heredoc_input(t_heredoc_info *info, int fd, char **old_filename)
{
	char	*buf;

	while (42)
	{
		buf = readline("> ");
		if (!buf || !ft_strcmp(info->limiter, buf) || g_child_pid == 44)
		{
			ft_strdel(old_filename);
			ft_strdel(&buf);
			close(fd);
			return (0);
		}
		write(fd, buf, ft_strlen(buf));
		write(fd, "\n", 1);
		ft_strdel(&buf);
	}
	return (0);
}

int	process_heredoc(t_heredoc_info *info, t_data *data)
{
	int		fd;

	create_temp_filename(info);
	fd = open(info->filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		return (printf("minishell: %s\n", strerror(errno)), 1);
	add_heredoc_file(data, info->filename, fd);
	g_child_pid = 42;
	if (handle_heredoc_input(info, fd, &info->limiter))
		return (1);
	info->heredoc_count++;
	ft_strdel(&info->token);
	info->token = ft_strdup(info->filename);
	return (g_child_pid = 0, close(fd), 0);
}

int	handle_heredoc(t_data *data, t_token *current, t_heredoc_info *info)
{
	t_token	*temp;

	if (current->next->type == T_SPACE)
		temp = current->next->next;
	else
		temp = current->next;
	info->token = ft_strdup(temp->word);
	info->limiter = ft_strdup(temp->word);
	info->filename = ft_strdup(temp->word);
	if (process_heredoc(info, data))
		return (free_heredoc_info(info), 1);
	ft_strdel(&temp->word);
	temp->word = ft_strdup(info->token);
	free_heredoc_info(info);
	return (0);
}

int	execute_delim(t_token **head, t_data *data)
{
	t_heredoc_info	info;
	t_token			*current;

	info.heredoc_count = 0;
	current = *head;
	while (current && current->type != T_NEWLINE)
	{
		if (current->type == T_DELIM)
			if (handle_heredoc(data, current, &info))
				return (1);
		current = current->next;
	}
	return (0);
}
