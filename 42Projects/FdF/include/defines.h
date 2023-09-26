/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:39:54 by eseferi           #+#    #+#             */
/*   Updated: 2023/09/26 18:31:08 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include <stdbool.h>

# define WIN_WIDTH	1920
# define WIN_HEIGHT	1080

# define X	0
# define Y	1
# define Z	2

# define	LATITUDE 0
# define	LONGITUDE 1

# define RED		0xc1272d
# define GREEN		0x33cc55
# define Fuchsia	0xff255c
# define BLUE		0x1B8EFA
# define SUPER_BLUE	0x0000FF
# define CARBON		0x151515
# define WHITE		0xBBBBBB
# define DISCO		0x9A1F6A
# define BRICK		0xC2294E 
# define FLAMINGO	0xEC4B27
# define TERRACOTTA	0xEF8633
# define SAFFRON	0xF3AF3D

# define DEFAULT_COLOR	TERRACOTTA
# define BOTTOM_COLOR	BLUE
# define TOP_COLOR		BRICK
# define GROUND_COLOR	SAFFRON
# define BACK_COLOR		0x151515
# define MENU_COLOR		0x202020
# define TEXT_COLOR		0xEAEAEA
# define NUMBER_COLOR	0xF3AF3D

# define MENU_WIDTH		300
# define FIT_MARGIN		50

# define FIT 1
# define FREE 0

// Structure for the points of the map and the limits of the map (min and max)
typedef struct s_point
{
	float	axis[3];
	int		color;
	int		hex_color;
	bool	paint;
	float	polar[2];
}	t_point;

// Structure for the colors of the map (top, bottom, ground, back, menu, text, number)
typedef struct m_colors {
	int topcolor;
	int bottomcolor;
	int groundcolor;
	int backcolor;
	int menucolor;
	int textcolor;
	int numbercolor;
}	t_colors;

// Structure for the image (img, addr, bits per pixel, line length, endian)
typedef struct s_bitmap	{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		lines;
	int		endian;
}	t_bitmap;

// Structure for the window (mlx, win)
typedef struct s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

// Structure for the keys (mouse left, mouse right, key control, last click left, last click right)
typedef struct s_keys {
	bool	b_mouse_l;
	bool	b_mouse_r;
	bool	b_keyctrl;
	t_point	last_click_l;
	t_point	last_click_r;
}	t_keys;

// Structure for the map (points, limits, source, colors)
typedef struct m_map {
	t_point	*points;
	t_point *limits;
	t_point source;
	t_colors colors;
	char	*memory;
	char	**lines;
	int		zmin;
	float	ang[3];
	float 	zdivisor;
	float 	scale;
	int		len;
	float 	brange;
	int		renders;
	bool 	b_lines;
	bool 	b_dots;
	bool 	b_pluslines;
	bool 	b_geometry;
	bool 	b_color;
	bool 	b_shadow;
	double 	performance;
	float 	proportion;
	float 	radius;
}	t_map;

typedef	struct s_meta {
	t_vars		vars;
	t_bitmap	bitmap;
	t_keys		keys;
	t_map		map;
}	t_meta;


// Colors for the terminal
// "\033" is the escape character for the terminal
// "m" is the end of the escape sequence for the terminal
// "0" is the default color for the terminal
// "nr after ;" is the color code for the terminal
// "nr after :" is the background color code for the terminal
# define DEF_COLOR	"\033[0;39m"
# define SH_GRAY	"\033[0;90m"
# define SH_RED		"\033[0;91m"
# define SH_GREEN	"\033[0;92m"
# define SH_YELLOW	"\033[0;93m"
# define SH_BLUE	"\033[0;94m"
# define SH_MAGENTA	"\033[0;95m"
# define SH_CYAN	"\033[0;96m"
# define SH_WHITE	"\033[0;97m"
# define SH_KNR		"\033[0m"
# define SH_KRED	"\033[31m"
# define SH_KGRN	"\033[32m"
# define SH_KYEL	"\033[33m"
# define SH_KBLU	"\033[34m"
# define SH_KMAG	"\033[35m"
# define SH_KCYN	"\033[36m"
# define SH_KWHT	"\033[37m"
# define U_ORANGE	"\033[48:5:208m"
# define U_WHITE	"\033[37;7:208m"
# define U_YELLOW	"\033[33;7:208m"
# define U_BLUE		"\033[34;7:208m"

#endif