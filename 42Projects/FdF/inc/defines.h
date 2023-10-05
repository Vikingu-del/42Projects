/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:39:54 by eseferi           #+#    #+#             */
/*   Updated: 2023/10/05 14:48:07 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include <stdbool.h>

# define WINX 1920	
# define WINY 1080

# define X 0
# define Y 1
# define Z 2

# define LAT 0
# define LONG 1

# define RED			0xc1272d
# define GREEN			0x33cc55
# define FUCHSIA		0xff255c
# define BLUE			0x1B8EFA
# define LIGHT_BLUE		0x0000FF
# define BLACK			0x151515
# define GRAY			0xBBBBBB
# define PURPLE			0x9A1F6A
# define DARK_RED		0xC2294E
# define ORANGE			0xEC4B27
# define YELLOW_ORANGE	0xEF8633
# define YELLOW			0xF3AF3D

# define DEFAULT_COLOR		YELLOW_ORANGE
# define BOTTOM_COLOR		BLUE
# define TOP_COLOR			DARK_RED
# define GROUND_COLOR		YELLOW
# define BACK_COLOR			BLACK
# define MENU_COLOR			0x202020
# define TEXT_COLOR			0xEAEAEA	
# define NUMBER_COLOR		YELLOW

# define MENU_WIDTH			370
# define FIT_MARGIN			50

# define FIT				1
# define FREE				0

// A structure to manipulate the points.
typedef struct	s_point {
	float	coordinates[3]; // coordinatess of the point
	int		color; // color of the point
	int		hex_color; // hexadecimal color of the point
	bool	paint; // boolean to check if the point has been painted
	float	polar[2]; // the distance from the origin and the angle from the x axis to the point in radians (0 to 2pi)
}	t_point;

// A structure to manipulate the colors.
typedef struct m_palette {
	int	topcolor;	// top color of a point
	int	groundcolor; // ground color of a point
	int	bottomcolor; // bottom color of a point
	int	backcolor; // background color of a point
	int	menucolor; // menu color of a point
}	t_palette;

// A structure to translate the picture to bitmap format.
typedef struct s_picture {
	void	*img; // image pointer to manipulate the image functions and variables
	char	*buffer;  // memory address of every pixel in the image
	int		bitxpixel; // the number of bits used to represent a color pixel in the image (32 bits)
	int		lines; // the number of lines in the image
	int		endian; // the endian of the image (little endian)
}	t_picture;

// A structure to manipulate the variables.
typedef struct s_vars {
	void	*mlx; // mlx pointer to manipulate the mlx functions and variables
	void	*win; // windows pointer to manipulate the windows functions and variables
}	t_vars;

// A structure to manipulate the keys.
typedef struct s_keys {
	bool			b_mouse_l; // boolean to check if the left mouse button is pressed
	bool			b_mouse_r; // boolean to check if the right mouse button is pressed
	bool			b_keyctrl; // boolean to check if the ctrl key is pressed
	t_point			last_click_l; // informations of the last click of the left mouse button
	t_point			last_click_r; // informations of the last click of the right mouse button
}	t_keys;

// A structure to manipulate the map.
typedef struct m_map {
	t_point			*points; // an array with points of the map
	t_point			limits; // limits of the map
	t_point			source; // source of the map
	t_palette		colors; // colors of the map
	char			*content; // map file
	char			**lines; // lines of the map
	int				zmin; // minimum zet value
	float			ang[3]; // representing the rotation angles
	float			z_scale; // scales the z coordinates of each point in the map when rendering the map
	float			scale; // scale factor for the map
	int				len; // size of the map
	float			curve_range; // curving range of the map
	int				renders; // number of times the map has been rendered
	bool			wires; // boolean to draw lines
	bool			dots; // boolean to draw dots
	bool			pluslines; // boolean to draw plus lines
	bool			sphere; // boolean to spherize the map
	bool			stars; // boolean to draw stars
	bool			shadows; // boolean to draw shadows
	double			performance; // performance of the map
	float			ratio; // ratio of the map zmax / number of points
	float			radius; // radius of the map
}	t_map;

// All data in one structure.
typedef struct s_data {
	t_vars		vars;
	t_picture	picture;
	t_map		map;
	t_keys		keys;
}	t_data;

# define DEF_COLOR	"\033[0;39m"
# define SH_GRAY	"\033[0;90m"
# define SH_RED		"\033[0;91m"
# define SH_GREEN	"\033[0;92m"
# define SH_YELLOW	"\033[0;93m"
# define SH_BLUE	"\033[0;94m"
# define SH_MAGENTA	"\033[0;95m"
# define SH_CYAN	"\033[0;96m"
# define SH_WHITE	"\033[0;97m"
# define SH_KNR		"\x1B[0m"
# define SH_KRED	"\x1B[31m"
# define SH_KGRN	"\x1B[32m"
# define SH_KYEL	"\x1B[33m"
# define SH_KBLU	"\x1B[34m"
# define SH_KMAG	"\x1B[35m"
# define SH_KCYN	"\x1B[36m"
# define SH_KWHT	"\x1B[37m"
# define U_ORANGE	"\033[48:5:208m"
# define U_WHITE	"\033[37;7:208m"
# define U_YELLOW	"\033[33;7:208m"
# define U_BLUE		"\033[34;7:208m"

#endif