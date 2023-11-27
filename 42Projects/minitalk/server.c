/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 22:52:26 by eseferi           #+#    #+#             */
/*   Updated: 2023/10/11 00:27:46 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// This function will print a banner saying MINITALK, the pid of the server, 
// and the number of clients connected to the server
void	printbanner(int pid)
{
	ft_printf("\n\t%s███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗\
	    ██╗██╗%s\n", CYAN, END);
	ft_printf("\t%s██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║\
	    █████╔╝%s \n", BLUE, END);
	ft_printf("\t%s██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║\
	    ██╔═██╗%s \n", GREEN, END);
	ft_printf("\t%s██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║\
	██╗%s\n", BLUE, END);
	ft_printf("\t%s╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝\
	╚═╝%s\n", CYAN, END);
	ft_printf("%s\n\t\tPID: %d%s\t\t\t%sBy: eseferi%s\n", BLUE, \
	pid, END, GREEN, END);
	ft_printf("\t ────────────────────── {.⋅ ✯ ⋅.}───────────────────────\
	\n\n");
}

// This function will print the message received from the client
void	printmessage(char *message)
{
	ft_printf("\t%s%s%s\n", GREEN, message, END);
}

// This function will handle the signals SIGUSR1 and SIGUSR2 received from 
// client and will print the message received from the client
void	handle_client_sig(int signo, siginfo_t *info, void *context)
{
	static int		pid = 0;
	static size_t	message = 0;
	static int		counter = 0;

	if (pid == 0)
	{
		pid = info->si_pid;
		ft_printf("\n\t%sClient connected with PID: %d%s\n", GREEN, pid, END);
	}
	if (signo == SIGUSR1)
		message |= (1 << counter);
	else if (signo == SIGUSR2)
		message |= (0 << counter);
	counter++;
	if (counter == 8)
	{
		bit_to_char(&message, &pid);
		counter = 0;
		message = 0;
	}
}

void	bit_to_char(size_t *message, int *pid)
{
	char	c;

	c = (char)*message;
	if (c == '\0')
	{
		kill(*pid, SIGUSR1);
		*pid = 0;
	}
	else
		ft_putchar_fd(c, 1);
}

int	main(void)
{
	struct sigaction	act;

	printbanner(getpid());
	act.sa_flags = SA_RESTART | SA_SIGINFO;
	act.sa_sigaction = handle_client_sig;
	sigemptyset(&act.sa_mask);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	if (sigaction(SIGUSR1, &act, NULL) == -1)
		ft_printf("\t%s%s%s\n", RED, "Error: SIGUSR1 failed", END);
	if (sigaction(SIGUSR2, &act, NULL) == -1)
		ft_printf("\t%s%s%s\n", RED, "Error: SIGUSR2 failed", END);
	while (1)
		pause();
	return (0);
}
