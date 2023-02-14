/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:24:49 by graux             #+#    #+#             */
/*   Updated: 2023/02/14 16:52:17 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/_gui.h"
#include "../includes/mlx.h"
#include <stdlib.h>
#include <stdio.h> //TODO remove

static int	hook_handler(int code, t_gui *gui)
{
	printf("key: %d\n", code);
	(void) gui;
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
	//TODO add keyhooks
	mlx_key_hook(((t_gui_ *) gui)->mlx_win, hook_handler, gui);
	mlx_loop_hook(((t_gui_ *) gui)->mlx, gui_draw_all, data);
	mlx_loop(((t_gui_ *) gui)->mlx);
}
