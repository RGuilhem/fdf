/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wf_scale.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:11:27 by graux             #+#    #+#             */
/*   Updated: 2023/02/15 16:13:18 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/_wf.h"
#include "../includes/_vec.h"

void	wf_scale(t_wf *wireframe, float scale_factor)
{
	int		i;
	int		j;
	t_wf_	*wf;

	wf = wireframe;
	i = -1;
	while (++i < wf->height)
	{
		j = -1;
		while (++j < wf->width)
		{
			((t_vec_ *)wf->points[i][j])->x *= scale_factor;
			((t_vec_ *)wf->points[i][j])->y *= scale_factor;
			((t_vec_ *)wf->points[i][j])->z *= scale_factor;
		}
	}
}
