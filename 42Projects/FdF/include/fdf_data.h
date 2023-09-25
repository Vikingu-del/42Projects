#ifndef FDF_DATA_H
# define FDF_DATA_H

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define WIN_TITLE "FdF"
# define WIN_BG_COLOR 0x000000
# define WIN_FG_COLOR 0xFFFFFF
# define WIN_FPS 60
# define TRUE 1
# define FALSE 0
# define X 0
# define Y 1
# define Z 2
# define W 3

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libft.h"
# include "mlx.h"
# include "get_next_line.h"
# include "ft_printf.h"

/*FOR PROCESS INPUT MAP*/
typedef struct	s_map
{
    int			**map;
    int			width;
    int			height;
    int			min;
    int			max;
}				t_map;

typedef struct	s_img
{
    void		*img;
    char		*data;
    int			bpp;
    int			size_line;
    int			endian;
}				t_img;

typedef struct	s_win
{
    void		*mlx;
    void		*win;
    t_img		*img;
}				t_win;

typedef struct	s_fdf
{
    t_map		*map;
    t_win		*win;
    int			projection;
    int			zoom;
    int			color;
    int			shift_x;
    int			shift_y;
    float		alpha;
    float		beta;
    float		gamma;
}				t_fdf;

/*FOR DRAWING*/
typedef struct	s_point
{
    int			x;
    int			y;
    int			z;
    int			w;
    int			color;
}				t_point;

typedef struct	s_line
{
    t_point		*start;
    t_point		*end;
    int			dx;
    int			dy;
    int			sx;
    int			sy;
    int			err;
    int			e2;
}				t_line;

/*FOR PROCESSING*/
typedef struct	s_matrix
{
    int			rows;
    int			cols;
    float		**matrix;
}				t_matrix;

typedef struct	s_vector
{
    int			dim;
    float		*vector;
}				t_vector;

typedef struct	s_matrix_vector
{
    t_matrix	*matrix;
    t_vector	*vector;
}				t_matrix_vector;

typedef struct	s_matrix_matrix
{
    t_matrix	*matrix1;
    t_matrix	*matrix2;
}				t_matrix_matrix;

#endif