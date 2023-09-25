/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:41:44 by eseferi           #+#    #+#             */
/*   Updated: 2023/08/08 16:41:46 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_printformat(va_list *ap, char format);
int	ft_printchar(char c);
int	ft_printstr(char *str);
int	ft_printptr(void *ptr);
int	ft_printptr_addr(uintptr_t n, const char format);
int	ft_printint(int n);
int	ft_printunsigned(unsigned int n);
int	ft_printhex(unsigned int n, const char format);

#endif