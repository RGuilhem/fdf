/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:24:49 by graux             #+#    #+#             */
/*   Updated: 2023/02/20 11:55:53 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/_gui.h"
#include "../includes/_vec.h"
#include "../includes/mlx.h"
#include <stdlib.h>
#include <stdio.h> //TODO remove

static void	hook_angle(int code, t_gui *gui)
{
	t_gui_	*g;

	g = gui;
	if (code == KEY_W)
		g->x_angle += ANGLE_INC;
	else if (code == KEY_S)
		g->x_angle -= ANGLE_INC;
	else if (code == KEY_A)
		g->y_angle += ANGLE_INC;
	else if (code == KEY_D)
		g->y_angle -= ANGLE_INC;
	else if (code == KEY_Q)
		g->z_angle += ANGLE_INC;
	else if (code == KEY_E)
		g->z_angle -= ANGLE_INC;
}

static int	hook_handler(int code, t_gui *gui)
{
	t_gui_	*g;
	t_vec_	*offset;

	g = gui;
	offset = g->offset;
	if (code == KEY_PLUS)
		g->zoom += ZOOM_INC;
	else if (code == KEY_MINUS)
		g->zoom -= ZOOM_INC;
	else if (code == KEY_H)
		offset->x += OFFSET_INC;
	else if (code == KEY_L)
		offset->x -= OFFSET_INC;
	else if (code == KEY_J)
		offset->y -= OFFSET_INC;
	else if (code == KEY_K)
		offset->y += OFFSET_INC;
	else if (code == 53)
		exit(1);
	hook_angle(code, gui);
	return (0);
}

void	gui_run(t_gui *gui, t_map *map)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return ;
	data->gui = gui;
	data->map = map;
	mlx_key_hook(((t_gui_ *) gui)->mlx_win, hook_handler, gui);
	mlx_loop_hook(((t_gui_ *) gui)->mlx, gui_draw_all, data);
	mlx_loop(((t_gui_ *) gui)->mlx);
}
