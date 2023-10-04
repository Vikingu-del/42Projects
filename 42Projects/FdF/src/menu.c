/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:12:01 by eseferi           #+#    #+#             */
/*   Updated: 2023/10/04 23:38:29 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"
#include "../inc/utils.h"

#define CONTROL_BOX			650
#define DRAWINFO_BOX		40
#define MAPINFO_BOX			280
#define COLORSCHEME_BOX		480
#define LINE_SIZE			30
#define MENU_TAB			30

static void	draw_colorscheme(t_data *data)
{
	int		line;

	line = COLORSCHEME_BOX;
	print_str(data, MENU_TAB, line, "//// COLORSCHEME ////");
	line += LINE_SIZE;
	print_str(data, MENU_TAB, line, "0: DEFAULT");
	line += LINE_SIZE;
	print_str(data, MENU_TAB, line, "1: TERRAIN");
	line += LINE_SIZE;
	print_str(data, MENU_TAB, line, "2: BLACK & WHITE");
	line += LINE_SIZE;
	print_str(data, MENU_TAB, line, "3: WHITE & BLACK");
	line += LINE_SIZE;
}

static void	draw_mapinfo(t_data *data)
{
	int		line;

	line = MAPINFO_BOX;
	print_str(data, MENU_TAB, line, "//// MAP INFO ////");
	line += LINE_SIZE;
	print_str(data, MENU_TAB, line, "Size:");
	print_nbr(data, MENU_TAB + 80, line, data->map.len);
	line += LINE_SIZE;
	print_str(data, MENU_TAB, line, "Xmax:");
	print_nbr(data, MENU_TAB + 80, line, data->map.limits.coordinates[X]);
	line += LINE_SIZE;
	print_str(data, MENU_TAB, line, "Ymax:");
	print_nbr(data, MENU_TAB + 80, line, data->map.limits.coordinates[Y]);
	line += LINE_SIZE;
	print_str(data, MENU_TAB, line, "Zmax:");
	print_nbr(data, MENU_TAB + 80, line, data->map.limits.coordinates[Z]);
	line += LINE_SIZE;
	print_str(data, MENU_TAB, line, "Zmin:");
	print_nbr(data, MENU_TAB + 80, line, data->map.zmin);
	line += LINE_SIZE;
}

static void	draw_controls(t_data *data)
{
	int		line;

	line = CONTROL_BOX;
	print_str(data, MENU_TAB, line, "//// CONTROLS ////");
	line += LINE_SIZE;
	print_str(data, MENU_TAB, line, "Scroll: Zom In/Out");
	line += LINE_SIZE;
	print_str(data, MENU_TAB, line, "Left Click: Rotate X/Y coordinates");
	line += LINE_SIZE;
	print_str(data, MENU_TAB, line, "Right Click: Move");
	line += LINE_SIZE;
	print_str(data, MENU_TAB, line, "Arrows: Rotate X/Y coordinates");
	line += LINE_SIZE;
	print_str(data, MENU_TAB, line, "Q/W: Rotate Z coordinates");
	line += LINE_SIZE;
	print_str(data, MENU_TAB, line, "+/-: Z Divisor");
	line += LINE_SIZE;
	print_str(data, MENU_TAB, line, "B/Ctr + B: Blending");
	line += LINE_SIZE;
	print_str(data, MENU_TAB, line, "P/I Parralell/Isometric Views");
	line += LINE_SIZE;
	print_str(data, MENU_TAB, line, "F/C Fit/Center");
	line += LINE_SIZE;
}

static void	draw_info(t_data *data)
{
	int		line;

	line = DRAWINFO_BOX;
	print_str(data, MENU_TAB, line, "//// DRAW INFO ////");
	line += LINE_SIZE;
	print_str(data, MENU_TAB, line, "Reenders:");
	print_nbr(data, MENU_TAB + 100, line, data->map.renders);
	line += LINE_SIZE;
	print_str(data, MENU_TAB, line, "Performance(ms):");
	print_nbr(data, MENU_TAB + 170, line, data->map.performance * 1000);
	line += LINE_SIZE;
	print_str(data, MENU_TAB, line, "X, Y, Z: [   ] [   ] [   ]");
	print_nbr(data, MENU_TAB + 100, line, data->map.ang[X]);
	print_nbr(data, MENU_TAB + 160, line, data->map.ang[Y]);
	print_nbr(data, MENU_TAB + 220, line, data->map.ang[Z]);
	line += LINE_SIZE;
	print_str(data, MENU_TAB, line, "Zoom:");
	print_nbr(data, MENU_TAB + 80, line, data->map.scale);
	line += LINE_SIZE;
	print_str(data, MENU_TAB, line, "Z Divisor:");
	print_nbr(data, MENU_TAB + 110, line, data->map.z_scale);
	line += LINE_SIZE;
	print_str(data, MENU_TAB, line, "Blending:");
	print_nbr(data, MENU_TAB + 100, line, data->map.curve_range * 10000);
}

void	draw_menu(t_data *data)
{
	draw_controls(data);
	draw_info(data);
	draw_mapinfo(data);
	draw_colorscheme(data);
}