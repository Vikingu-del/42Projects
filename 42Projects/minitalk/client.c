/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 22:54:03 by eseferi           #+#    #+#             */
/*   Updated: 2023/10/11 00:39:30 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#define ERROR -1

void	handle_server_signal(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("\t%s%s%s\n", GREEN, "Message delivered", END);
	else if (sig == SIGUSR2)
		ft_printf("\t%s%s%s\n", RED, "Message was not delivered", END);
}

void	send_char(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(50);
	}
}

void	send_chars(int pid, char *buf, int len)
{
	int	i;

	i = 0;
	while (i < len)
		send_char(pid, buf[i++]);
}

int	modified_atoi(const char *str)
{
	int	sign;
	int	value;

	sign = 1;
	value = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
		sign = 44 - *str++;
	while (ft_isdigit(*str))
		value = value * 10 + (*str++ - '0');
	if (*str != ft_isdigit(*str))
	{
		ft_printf("\t%s%s%s\n", RED, "Error: PID incorrect", END);
		exit(1);
	}
	return (sign * value);
}

int	main(int argc, char **argv)
{
	int					pid;
	int					i;
	struct sigaction	act;

	if (argc != 3)
	{
		ft_printf("\t%s%s%s\n", RED, "Usage: ./client \
		[server pid] [string]", END);
		return (0);
	}
	act.sa_handler = handle_server_signal;
	act.sa_flags = 0;
	sigemptyset(&act.sa_mask);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	if (sigaction(SIGUSR1, &act, NULL) == -1)
		ft_printf("\t%s%s%s\n", RED, "Error: SIGUSR1 failed", END);
	pid = modified_atoi(argv[1]);
	send_chars(pid, argv[2], ft_strlen(argv[2]));
	send_chars(pid, "\0", 1);
	return (0);
}
