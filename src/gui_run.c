/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:24:49 by graux             #+#    #+#             */
/*   Updated: 2023/02/28 13:10:14 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/_gui.h"
#include "../includes/_vec.h"
#include "../includes/mlx.h"
#include <stdlib.h>

static void	gui_reset(t_gui_ *gui)
{
	t_vec_	*zoom;
	t_vec_	*offset;

	zoom = gui->zoom;
	offset = gui->offset;
	gui->x_angle = DEFAULT_X_ANGLE;
	gui->y_angle = DEFAULT_Y_ANGLE;
	gui->z_angle = DEFAULT_Z_ANGLE;
	gui->proj = ORTHOGRAPHIC;
	zoom->x = DEFAULT_ZOOM;
	zoom->y = DEFAULT_ZOOM;
	zoom->z = DEFAULT_ZOOM;
	offset->x = WIN_WIDTH / 2;
	offset->y = WIN_HEIGHT / 2;
	offset->z = 0;
}

static void	hook_angle(int code, t_gui *gui)
{
	t_gui_	*g;

	g = gui;
	if (code == KEY_W)
		g->x_angle += ANGLE_INC;
	if (code == KEY_S)
		g->x_angle -= ANGLE_INC;
	if (code == KEY_A)
		g->y_angle += ANGLE_INC;
	if (code == KEY_D)
		g->y_angle -= ANGLE_INC;
	if (code == KEY_Q)
		g->z_angle += ANGLE_INC;
	if (code == KEY_E)
		g->z_angle -= ANGLE_INC;
	if (code == KEY_RESET)
		gui_reset(g);
	if (code == KEY_P)
		g->proj = (g->proj + 1) % 2;
}

static void	handle_zoom(int code, t_gui *gui)
{
	t_gui_	*g;
	t_vec_	*zoom;

	g = gui;
	zoom = g->zoom;
	if (code == KEY_PLUS)
	{
		zoom->x += ZOOM_INC;
		zoom->y += ZOOM_INC;
		zoom->z += ZOOM_INC;
	}
	if (code == KEY_MINUS && zoom->x - ZOOM_INC > 0)
	{
		zoom->x -= ZOOM_INC;
		zoom->y -= ZOOM_INC;
		zoom->z -= ZOOM_INC;
	}
	if (code == KEY_Z_ZOOM_P)
		zoom->z += ZOOM_INC;
	if (code == KEY_Z_ZOOM_M)
		zoom->z -= ZOOM_INC;
}

static int	hook_handler(int code, t_data *data)
{
	t_gui_	*g;
	t_vec_	*offset;

	g = data->gui;
	offset = g->offset;
	if (code == KEY_H)
		offset->x += OFFSET_INC;
	if (code == KEY_L)
		offset->x -= OFFSET_INC;
	if (code == KEY_J)
		offset->y -= OFFSET_INC;
	if (code == KEY_K)
		offset->y += OFFSET_INC;
	if (code == 53)
		quit_program(data);
	if (code == KEY_ROT)
	{
		g->x_angle += ANGLE_INC / 3;
		g->y_angle -= ANGLE_INC / 3;
		g->z_angle += ANGLE_INC / 3;
	}
	hook_angle(code, data->gui);
	handle_zoom(code, data->gui);
	return (0);
}

void	gui_run(t_gui *gui, t_map *map)
{
	t_data	*data;
	t_gui_	*g;

	data = malloc(sizeof(t_data));
	if (!data)
		return ;
	data->gui = gui;
	data->map = map;
	g = gui;
	mlx_string_put(g->mlx, g->mlx_win, 350, 8, 0xFF, HELP_TEXT_ROT
		HELP_TEXT_TRA HELP_TEXT_ZOOM HELP_TEXT_Z HELP_TEXT_RES);
	mlx_hook(((t_gui_ *) gui)->mlx_win, 2, 0, hook_handler, data);
	mlx_hook(((t_gui_ *) gui)->mlx_win, 17, 0, quit_program, data);
	mlx_loop_hook(((t_gui_ *) gui)->mlx, gui_draw_all, data);
	mlx_loop(((t_gui_ *) gui)->mlx);
}
