/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:32:36 by eseferi           #+#    #+#             */
/*   Updated: 2023/09/26 23:04:25 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define ERR_ARGS		"❌Incorrect number of arguments, expected 1"
# define ERR_OPEN		"❌Error opening the file"
# define ERR_READ		"❌Error reading the file"
# define ERR_SPLIT		"❌Error splitting the line"
# define ERR_LINE		"\n❌Error: nº of elements is different for each line"
# define ERR_EMPTY		"❌Error: the file is empty or wrongly formatted"
# define ERR_MEM		"❌Memory error"
# define ERR_MAP		"❌Map Error"

void	exit_with_error(char *s);
#endif