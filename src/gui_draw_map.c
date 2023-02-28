/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_draw_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:45:48 by graux             #+#    #+#             */
/*   Updated: 2023/02/27 20:17:19 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/_gui.h"
#include "../includes/_map.h"
#include "../includes/_wf.h"
#include "../includes/_frame.h"
#include "../includes/mlx.h"

static void	clear_frame(void *mlx, t_frame **frame)
{
	t_frame_	**fr;

	fr = (t_frame_ **) frame;
	mlx_destroy_image(mlx, (*fr)->img);
	(*fr)->img = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	(*fr)->address = mlx_get_data_addr((*fr)->img, &(*fr)->bits_per_pixel,
			&(*fr)->line_length, &(*fr)->endian);
}

static void	two_lines(t_vec_ i, t_wf_ *proj, t_frame_ *curr_fr)
{
	if (i.x + 1 < proj->width)
		draw_line(curr_fr, proj->points[(int) i.y][(int) i.x],
			proj->points[(int) i.y][(int) i.x + 1]);
	if (i.y + 1 < proj->height)
		draw_line(curr_fr, proj->points[(int) i.y][(int) i.x],
			proj->points[(int) i.y + 1][(int) i.x]);
}

void	gui_draw_map(t_gui *gui, t_map *map)
{
	static unsigned int	f_counter;
	t_gui_				*g;
	t_wf_				*proj;
	t_vec_				i;
	t_frame_			*curr_fr;

	g = gui;
	curr_fr = g->frame_buffer[f_counter % 2];
	proj = ((t_map_ *) map)->projected_wf;
	i.y = -1;
	while (++i.y < proj->height)
	{
		i.x = -1;
		while (++i.x < proj->width)
			two_lines(i, proj, curr_fr);
	}
	mlx_put_image_to_window(g->mlx, g->mlx_win, curr_fr->img, 0, 40);
	clear_frame(g->mlx, &g->frame_buffer[(f_counter + 1) % 2]);
	f_counter++;
}
