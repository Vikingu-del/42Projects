/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsievier <hsievier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:32:54 by eseferi           #+#    #+#             */
/*   Updated: 2023/02/12 17:42:52 by hsievier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int		ft_atoi(const char *str);
char	*ft_strdup(char *src);
void	ft_putstr(char *str);
char	*ft_getnb(int fd);
char	*ft_getval(int fd, char *c);
int		getdec(int nb);
int		getmult(int nb);

typedef struct s_list
{
	int		nb;
	char	*val;
}	t_list;
t_list	*process(char *file);
void	ft_print(int n, t_list *tab, int *first);

#endif
