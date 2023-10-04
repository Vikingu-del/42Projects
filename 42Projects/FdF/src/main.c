#include "../lib/mlx/mlx.h"
#include "../inc/defines.h"
#include "../inc/map.h"
#include "../inc/control_keys.h"
#include "../inc/control_mouse.h"
#include "../inc/control_utils.h"
#include "../inc/errors.h"
#include <stdlib.h>

void	init_data(t_data *data, char *file)
{
	load_map(&data->map, file);
	data->map.ratio = data->map.limits.coordinates[Z] / data->map.limits.coordinates[X];
	if (data->map.ratio > 0.5)
		data->map.z_scale = data->map.ratio * 30;
	data->keys.b_keyctrl = 0;
	data->keys.b_mouse_l = 0;
	data->keys.b_mouse_r = 0;
	data->vars.mlx = mlx_init();
	data->vars.win = mlx_new_window(data->vars.mlx, WINX, WINY, \
	"Amazing FDF of eseferi");
	data->picture.img = mlx_new_image(data->vars.mlx, WINX, WINY);
	data->picture.buffer = mlx_get_data_addr(data->picture.img, \
		&data->picture.bitxpixel, &data->picture.lines, &data->picture.endian);
	if (draw_map(data, FIT) < 0)
		exit_with_error(ERR_MAP);
}

int	main(int argv, char **argc)
{
	t_data	data;

	if (argv != 2)
		exit_with_error(ERR_ARGS);
	init_data(&data, argc[1]);
	mlx_hook(data.vars.win, 2, 0, key_press, &data);
	mlx_hook(data.vars.win, 3, 0, key_release, &data);
	mlx_hook(data.vars.win, 4, 0, mouse_press, &data);
	mlx_hook(data.vars.win, 5, 0, mouse_release, &data);
	mlx_hook(data.vars.win, 6, 0, mouse_move, &data);
	mlx_hook(data.vars.win, 17, 0, terminate_program, &data);
	mlx_loop(data.vars.mlx);
	free (data.map.points);
	free (data.map.content);
	return (0);
}