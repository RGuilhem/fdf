/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wf_translate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:55:42 by graux             #+#    #+#             */
/*   Updated: 2023/02/15 16:57:26 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/_wf.h"
#include "../includes/_vec.h"

void	wf_translate(t_wf *wireframe, t_vec *direction)
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
			vec_add(wf->points[i][j], direction);
	}
}
