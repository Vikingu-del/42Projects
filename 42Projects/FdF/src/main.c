#include "../lib/mlx/mlx.h"
#include "../inc/defines.h"
#include "../inc/map.h"
#include "../inc/control_keys.h"
#include "../inc/control_mouse.h"
#include "../inc/control_utils.h"
#include "../inc/errors.h"
#include <stdlib.h>

void	system_init(t_data *data)
{
	data->map.renders = 0;
	data->map.proportion = data->map.limits.coordinates[Z] / data->map.limits.coordinates[X];
	if (data->map.proportion > 0.5)
		data->map.zdivisor = data->map.proportion * 30;
	data->keys.b_keyctrl = 0;
	data->keys.b_mouse_l = 0;
	data->keys.b_mouse_r = 0;
	data->vars.mlx = mlx_init();
	data->vars.win = mlx_new_window(data->vars.mlx, WINX, WINY, \
	"FDF - ailopez-");
	data->picture.img = mlx_new_image(data->vars.mlx, WINX, WINY);
	data->picture.buffer = mlx_get_data_addr(data->picture.img, \
		&data->picture.bitxpixel, &data->picture.lines, &data->picture.endian);
}

int	main(int argv, char **argc)
{
	t_data	data;

	if (argv != 2)
		exit_with_error(ERR_ARGS);
	load_map(&data.map, argc[1]);
	system_init(&data);
	if (draw_map(&data, FIT) < 0)
		exit_with_error(ERR_MAP);
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