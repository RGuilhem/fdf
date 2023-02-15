/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_project.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:56:50 by graux             #+#    #+#             */
/*   Updated: 2023/02/15 17:04:30 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/_map.h"
#include "../includes/_gui.h"
#include "../includes/_wf.h"

void	map_project(t_map *m, t_gui *g)
{
	t_map_	*map;
	t_gui_	*gui;

	gui = g;
	map = m;
	wf_copy(map->projected_wf, map->original_wf);
	wf_scale(map->projected_wf, gui->zoom);
	wf_transform(map->projected_wf, matrix_rotz_create(gui->z_angle));
	wf_transform(map->projected_wf, matrix_roty_create(gui->y_angle));
	wf_transform(map->projected_wf, matrix_rotx_create(gui->x_angle));
	wf_translate(map->projected_wf, gui->offset);
	//TODO project;
}
