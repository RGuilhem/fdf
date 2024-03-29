/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:07:49 by graux             #+#    #+#             */
/*   Updated: 2023/02/28 13:30:07 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/mlx.h"
#include "../includes/_gui.h"
#include "../includes/_frame.h"
#include <stdlib.h>

static int	gui_init_frames(t_gui_ *gui)
{
	t_frame_	*curr;

	gui->frame_buffer[0] = malloc(sizeof(t_frame_));
	gui->frame_buffer[1] = malloc(sizeof(t_frame_));
	if (!gui->frame_buffer[0] || !gui->frame_buffer[1])
		return (0);
	curr = gui->frame_buffer[0];
	curr->img = mlx_new_image(gui->mlx, WIN_WIDTH, WIN_HEIGHT);
	curr->address = mlx_get_data_addr(curr->img, &curr->bits_per_pixel,
			&curr->line_length, &curr->endian);
	curr = gui->frame_buffer[1];
	curr->img = mlx_new_image(gui->mlx, WIN_WIDTH, WIN_HEIGHT);
	curr->address = mlx_get_data_addr(curr->img, &curr->bits_per_pixel,
			&curr->line_length, &curr->endian);
	return (1);
}

t_gui	*gui_create(void)
{
	t_gui_	*gui;

	gui = malloc(sizeof(t_gui_));
	if (!gui)
		return (NULL);
	gui->mlx = mlx_init();
	gui->mlx_win = mlx_new_window(gui->mlx, WIN_WIDTH,
			WIN_HEIGHT + 40, "fdf");
	gui->proj = ORTHOGRAPHIC;
	gui->zoom = vec_create(DEFAULT_ZOOM, DEFAULT_ZOOM, DEFAULT_ZOOM);
	gui->x_angle = DEFAULT_X_ANGLE;
	gui->y_angle = DEFAULT_Y_ANGLE;
	gui->z_angle = DEFAULT_Z_ANGLE;
	gui->offset = vec_create(WIN_WIDTH / 2, WIN_HEIGHT / 2, 0);
	if (!gui_init_frames(gui))
	{
		gui_destroy(gui);
		return (NULL);
	}
	return (gui);
}
