/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:41:18 by eseferi           #+#    #+#             */
/*   Updated: 2023/08/08 16:41:20 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "stack.h"

// MAIN CHECKER
int			main(int argc, char *argv[]);
void		read_op(t_ps *data);
bool		test_sort(t_ps *data);

// CHECK SORT
void		error_read_op(t_ps *data, char *line);
int			get_next_line_ps(int fd, char *line);
enum e_op	string_to_op(const char *str);
void		call_op(t_ps *data, enum e_op op);

#endif