/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_project.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:56:50 by graux             #+#    #+#             */
/*   Updated: 2023/02/20 11:38:49 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/_map.h"
#include "../includes/_gui.h"
#include "../includes/_wf.h"
#include "../includes/_vec.h"

static void	map_center(t_gui_ *gui, t_map_ *map)
{
	t_vec_	offset;

	offset.x = -(map->width * gui->zoom / 2);
	offset.y = -(map->height * gui->zoom / 2);
	offset.z = 0;
	wf_translate(map->projected_wf, &offset);
}

void	map_project(t_map *m, t_gui *g)
{
	t_map_		*map;
	t_gui_		*gui;
	t_matrix	*mat_x;
	t_matrix	*mat_y;
	t_matrix	*mat_z;

	gui = g;
	map = m;
	mat_x = matrix_rotx_create(gui->x_angle);
	mat_y = matrix_roty_create(gui->y_angle);
	mat_z = matrix_rotz_create(gui->z_angle);
	wf_copy(map->projected_wf, map->original_wf);
	wf_scale(map->projected_wf, gui->zoom);
	map_center(gui, map);
	wf_transform(map->projected_wf, mat_z);
	wf_transform(map->projected_wf, mat_y);
	wf_transform(map->projected_wf, mat_x);
	wf_translate(map->projected_wf, gui->offset);
	matrix_destroy(mat_x);
	matrix_destroy(mat_y);
	matrix_destroy(mat_z);
}
