/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wf_transform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:14:47 by graux             #+#    #+#             */
/*   Updated: 2023/02/15 16:16:27 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/_wf.h"
#include "../includes/_vec.h"

void	wf_transform(t_wf *wireframe, t_matrix *transform)
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
			vec_multiply(wf->points[i][j], transform);
	}
}
