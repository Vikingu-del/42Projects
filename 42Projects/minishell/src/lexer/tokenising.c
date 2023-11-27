/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenising.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:27:42 by eseferi           #+#    #+#             */
/*   Updated: 2023/11/27 13:50:01 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_tokens(t_data *data)
{
	t_token	*tmp;

	tmp = data->token_list;
	while (tmp)
	{
		printf("\nword:%s:type:%d\n", tmp->word, tmp->type);
		tmp = tmp->next;
	}
}

t_token	*create_token(t_data *data, int i)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!new)
		exit_shell("Error: malloc failed\n", 1, data);
	new->word = ft_substr(data->input_line, i - data->count, data->count);
	new->type = T_WORD;
	data->count = 0;
	return (new);
}

t_token	*create_arg_token(t_data *data, char *word, enum e_token_type type)
{
	t_token	*new;

	new = ft_calloc(1, sizeof(t_token));
	if (!new)
		exit_shell("Error: malloc failed\n", 1, data);
	new->word = ft_strdup(word);
	new->type = type;
	return (new);
}

void	clean_space_tokens(t_token **head)
{
	t_token	*current;
	t_token	*tmp;

	current = *head;
	while (current != NULL)
	{
		tmp = current;
		if (tmp->type == T_SPACE)
		{
			if (tmp->prev != NULL)
				tmp->prev->next = tmp->next;
			else
				*head = tmp->next;
			if (tmp->next != NULL)
				tmp->next->prev = tmp->prev;
			current = tmp->next;
			ft_strdel(&tmp->word);
			free(tmp);
		}
		else
			current = current->next;
	}
}

void	fix_tokens_tree(t_token **head)
{
	find_ortokens(head);
	find_andtokens(head);
	find_inout(head);
	find_threeout(head);
	find_threein(head);
}
