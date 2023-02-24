/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:18:10 by graux             #+#    #+#             */
/*   Updated: 2023/02/24 13:27:29 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/_gui.h"
#include "../includes/_frame.h"
#include "../includes/mlx.h"
#include <stdlib.h>

void	gui_destroy(t_gui *gui)
{
	t_gui_	*g;

	g = gui;
	mlx_destroy_window(g->mlx, g->mlx_win);
	vec_destroy(g->zoom);
	vec_destroy(g->offset);
	mlx_destroy_image(g->mlx, ((t_frame_ *)g->frame_buffer[0])->img);
	mlx_destroy_image(g->mlx, ((t_frame_ *)g->frame_buffer[1])->img);
	free(g->frame_buffer[0]);
	free(g->frame_buffer[1]);
	free(g);
}
