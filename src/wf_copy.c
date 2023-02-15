/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wf_copy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:04:10 by graux             #+#    #+#             */
/*   Updated: 2023/02/15 16:09:53 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/_wf.h"
#include "../includes/_vec.h"

void	wf_copy(t_wf *dest, t_wf *src)
{
	int		i;
	int		j;
	t_wf_	*d;
	t_wf_	*s;

	d = dest;
	s = src;
	i = -1;
	while (++i < s->height)
	{
		j = -1;
		while (++j < s->width)
		{
			((t_vec_ *)d->points[i][j])->x = ((t_vec_ *) s->points[i][j])->x;
			((t_vec_ *)d->points[i][j])->y = ((t_vec_ *) s->points[i][j])->y;
			((t_vec_ *)d->points[i][j])->z = ((t_vec_ *) s->points[i][j])->z;
		}
	}
}
