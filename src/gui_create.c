/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:07:49 by graux             #+#    #+#             */
/*   Updated: 2023/02/13 15:21:36 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/mlx.h"
#include "../includes/_gui.h"
#include <stdlib.h>

t_gui	*gui_create(int width, int height)
{
	t_gui_	*gui;

	gui = malloc(sizeof(t_gui_));
	if (!gui)
		return (NULL);
	gui->mlx = mlx_init();
	gui->mlx_win = mlx_new_window(gui->mlx, WIN_WIDTH + SETTINGS_WIDTH,
			WIN_HEIGHT, "fdf");
	gui->zoom = DEFAULT_ZOOM;
	gui->x_angle = DEFAULT_X_ANGLE;
	gui->y_angle = DEFAULT_Y_ANGLE;
	gui->z_angle = DEFAULT_Z_ANGLE;
	return (gui);
}
