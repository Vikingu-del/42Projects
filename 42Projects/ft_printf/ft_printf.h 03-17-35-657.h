/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 01:46:12 by eseferi           #+#    #+#             */
/*   Updated: 2023/06/20 00:24:11 by eseferi          ###   ########.fr       */
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
int		ft_cornercase_precision(long nbr, t_flags *flags);
int		ft_rigth_justify_nbr(long nbr, t_flags *flags);
int		ft_left_justify_nbr(long nbr, t_flags *flags);

//*** Format helpers ***
int		ft_pad_char(char c, int bytes, long nbr);
int		ft_handle_plus_space(long nbr, int bytes, t_flags *flags);

//*** Handle the percent specifier ***
int		ft_percent_format(char c, t_flags *flags);

int		ft_max(int a, int b);
long	ft_abs(long n);

//*** Handle the combination of flags ***
int		ft_firstcombo_check(t_flags *flags, int count);
int		ft_secondcombo_check(long nbr, t_flags *flags, int count);
int		ft_rightnbr_first_combos(long nbr, t_flags *flags, int count);
int		ft_rightnbr_sec_combos(long nbr, t_flags *flags, int count);
int		ft_rightnbr_full_combos(long nbr, t_flags *flags, int count);
int		ft_left_fir_combos(long nbr, t_flags *flags, int nbr_len);
int		ft_left_sec_combos(long nbr, t_flags *flags, int nbr_len);
int		ft_lhex_first_combos(unsigned long hex_value, int len, t_flags *flags);
int		ft_lhex_sec_combos(unsigned long hex_value, int len, t_flags *flags);
int		ft_rhex_fcom(unsigned long hex, t_flags *flags, int len, int count);
int		ft_rhex_scom(unsigned long hex, t_flags *flags, int len, int count);
int		ft_check_hash(t_flags *flags);
int		ft_puthex_com(t_flags *flags, unsigned long hex);

#endif