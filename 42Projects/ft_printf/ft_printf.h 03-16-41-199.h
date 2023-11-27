/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 01:46:12 by eseferi           #+#    #+#             */
/*   Updated: 2023/06/13 01:46:15 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

//*** Struct Flags ***
typedef struct s_flags
{
	int	zero_left_pad_sentinel;
	int	left_justified;
	int	plus_sign;
	int	space;
	int	hash;
	int	width;
	int	is_upper;
	int	precision_point;
	int	precision_value;
	int	is_unsigned;
	int	specifier;
}				t_flags;

void	ft_refresh_flags(t_flags *flags);
int		ft_parse_flags(const char *format_str, int i, t_flags *flags);

//*** Printf ***
int		ft_printf(const char *format_str, ...);

//*** Chars ***
int		ft_putchar_format(char c, t_flags *flags);
int		ft_putchar(char c);

//*** Strings ***
int		ft_putstr_format(char *str, t_flags *flags);

//*** Nbr ***
int		ft_putnbr_format(long nbr, t_flags *flags);
int		ft_putunsigned_format(unsigned int nbr, t_flags *flags);

//*** Hex ***
int		ft_puthex_format(long hex_value, t_flags *flags);
int		ft_hex_len(unsigned long hex_value);
int		ft_puthex(unsigned long hex_value, t_flags *flags);

//*** Ptr ***
int		ft_putptr_format(void *ptr, t_flags *flags);

/*** Long utils ***
* i use long so i can trick the overflow
* and i can use same functions
* for signed and unsigned
*/
int		ft_nbr_len(long nbr);
int		ft_putnbr_long_precision(long nbr, int bytes);

//*** Format helpers ***
int		ft_pad_char(char c, int bytes);
int		ft_handle_plus_space(long nbr, int bytes, t_flags *flags);

#endif