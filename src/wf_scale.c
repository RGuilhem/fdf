/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wf_scale.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:11:27 by graux             #+#    #+#             */
/*   Updated: 2023/02/21 15:16:20 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/_wf.h"
#include "../includes/_vec.h"

void	wf_scale(t_wf *wireframe, t_vec *scale_factor)
{
	int		i;
	int		j;
	t_wf_	*wf;
	t_vec_	*scale;

	wf = wireframe;
	scale = scale_factor;
	i = -1;
	while (++i < wf->height)
	{
		j = -1;
		while (++j < wf->width)
		{
			((t_vec_ *)wf->points[i][j])->x *= scale->x;
			((t_vec_ *)wf->points[i][j])->y *= scale->y;
			((t_vec_ *)wf->points[i][j])->z *= scale->z;
		}
	}
}
