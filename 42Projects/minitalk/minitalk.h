/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 23:35:22 by eseferi           #+#    #+#             */
/*   Updated: 2023/10/10 23:35:50 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "ft_printf/ft_printf.h"

// SERVER
void	printbanner(int pid);
void	printmessage(char *str);
void	handle_client_sig(int sig, siginfo_t *info, void *context);
void	bit_to_char(size_t *message, int *pid);

// CLIENT
void	handle_server_signal(int sig);
void	send_char(int pid, char c);
void	send_chars(int pid, char *buf, int len);

# define RED "\033[0;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[1;34m"
# define END "\033[0m"
# define CYAN "\033[1;36m"

#endif