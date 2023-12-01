/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:25:17 by eseferi           #+#    #+#             */
/*   Updated: 2023/12/01 13:46:51 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
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
	return (sign * value);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}


void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putstr_fd("8", fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else
	{
		if (n > 9)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}


int	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return (1);
	write(fd, s, ft_strlen(s));
	return (0);
}

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

int	ft_is_all_digits(char *str)
{
	while(*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}