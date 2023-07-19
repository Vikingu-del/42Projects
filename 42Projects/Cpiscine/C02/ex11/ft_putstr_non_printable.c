/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:08:24 by eseferi           #+#    #+#             */
/*   Updated: 2023/02/09 13:00:36 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
// #include<stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_hexa(char c)
{
	int		negative_char;
	char	hex_digit1;
	char	hex_digit2;

	ft_putchar('\\');
	if (c < 0)
	{
		negative_char = (-128 - (c)) * -1 + 128;
		hex_digit1 = negative_char / 16;
		hex_digit2 = negative_char % 16;
	}
	else
	{
		hex_digit1 = c / 16;
		hex_digit2 = c % 16;
	}
	if (hex_digit1 < 10)
		ft_putchar(hex_digit1 + '0');
	else
		ft_putchar(hex_digit1 + 87);
	if (hex_digit2 < 10)
		ft_putchar(hex_digit2 + '0');
	else
		ft_putchar(hex_digit2 + 87);
}

void	ft_putstr_non_printable(char *str)
{
	int		index;

	index = 0;
	while (str[index])
	{
		if (str[index] >= 32 && str[index] <= 126)
			ft_putchar(str[index]);
		else
		{
			ft_print_hexa(str[index]);
		}
		index++;
	}
}

int	main(void)
{
	char	str[] = {125, 126, 127, 128, 129};
	ft_putstr_non_printable(&str[0]);
	return (0);
}
// \a	07	Alert (Beep, Bell) (added in C89)[1]
// \b	08	Backspace
// \enote 1	1B	Escape character
// \f	0C	Formfeed Page Break
// \n	0A	Newline (Line Feed); see notes below
// \r	0D	Carriage Return
// \t	09	Horizontal Tab
// \v	0B	Vertical Tab
// \\	5C	Backslash
// \'	27	Apostrophe or single quotation mark
// \"	22	Double quotation mark
// \?	3F	Question mark (used to avoid trigraphs)