#ifndef FDF_H
# define FDF_H
# include "fdf_data.h"

/*==========================INPUT MAP=========================*/
int		process_input_map(int fd, t_map *map);
int		get_map_width(char *line);
int		get_map_height(int fd);
int		**create_map(int width, int height);
int		**fill_map(int fd, t_map *map);
int		**get_map(int fd, t_map *map);
void	free_map(t_map *map);

/*==========================DRAWING=========================*/
void	draw(t_fdf *fdf);
void	draw_map(t_fdf *fdf);
void	draw_line(t_fdf *fdf, t_point *start, t_point *end);
void	draw_menu(t_fdf *fdf);

/*==========================UTILS=========================*/
int		get_color(t_point *current, t_point *start, t_point *end, t_point *delta);
void	set_color(t_point *current, t_point *start, t_point *end, t_point *delta);
void	set_default(t_fdf *fdf);
void	set_default_color(t_fdf *fdf);
void	set_default_shift(t_fdf *fdf);
void	set_default_zoom(t_fdf *fdf);
void	set_default_projection(t_fdf *fdf);
void	set_default_angle(t_fdf *fdf);
void	set_default_map(t_fdf *fdf);
void	set_default_win(t_fdf *fdf);
void	set_default_img(t_fdf *fdf);
void	set_default_line(t_line *line, t_point *start, t_point *end);
void	set_default_point(t_point *point, int x, int y, t_map *map);

/*===========================MATRIX===========================*/
void	rotate_x(t_point *point, float alpha);
void	rotate_y(t_point *point, float beta);
void	rotate_z(t_point *point, float gamma);
void	rotate_xyz(t_point *point, t_fdf *fdf);
void	iso(t_point *point);
void	projection(t_point *point, t_fdf *fdf);
void	transform(t_point *point, t_fdf *fdf);

/*==========================MATRIX_UTILS=========================*/
void	multiply_matrix(int *x, int *y, int *z, t_fdf *fdf);
void	multiply_matrix_xyz(int *x, int *y, int *z, t_fdf *fdf);
void	multiply_matrix_xyzw(int *x, int *y, int *z, int *w, t_fdf *fdf);
void	multiply_matrix_xyzw_color(int *x, int *y, int *z, int *w, int *color, t_fdf *fdf);
void	multiply_matrix_xyz_color(int *x, int *y, int *z, int *color, t_fdf *fdf);


/*====================linear transformation====================*/
void	shift(int *x, int *y, int shift_x, int shift_y);
void	zoom(int *x, int *y, int *z, int zoom);
void	zoom_xyz(int *x, int *y, int *z, int zoom);
void	zoom_xyzw(int *x, int *y, int *z, int *w, int zoom);
void	zoom_xyzw_color(int *x, int *y, int *z, int *w, int *color, int zoom);
void	zoom_xyz_color(int *x, int *y, int *z, int *color, int zoom);

/*=========================OUTPUT MAP=========================*/
void	print_map(t_map *map);

/*==========================MiniLibX==========================*/
/*Events*/
int		key_press(int key, t_fdf *fdf);
int		mouse_press(int button, int x, int y, t_fdf *fdf);
int		mouse_move(int x, int y, t_fdf *fdf);
int     keydown(int key, t_fdf *fdf);
int     destroy(t_fdf *fdf);
/*MLX*/


/*==========================ERRORS=========================*/
void	error(int error_code);

#endif