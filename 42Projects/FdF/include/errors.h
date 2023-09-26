/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:32:36 by eseferi           #+#    #+#             */
/*   Updated: 2023/09/26 19:38:42 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define ERR_ARGS   "❌Erro: Incorrect number of arguments, expected 1"
# define ERR_OPEN   "❌Erro: Could not open file"
# define ERR_READ   "❌Erro: Could not read file"
# define ERR_SPLIT  "❌Erro: Could not split line"
# define ERR_LINE   "\n❌Error: nº of elements in line is not constant"
# define ERR_EMPTY  "❌Error: empty file"
# define ERR_MEM    "❌Error: Memory problem"
# define ERR_MAP    "❌Error: Invalid map"

void    terminate(char *str);

#endif