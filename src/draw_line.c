/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:35:57 by graux             #+#    #+#             */
/*   Updated: 2023/02/15 15:43:11 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/_vec.h"
#include <math.h>

static void	init_line(t_vec_ *dir, t_vec_ *a, t_vec_ *b, double *step)
{
	dir->x = b->x - a->x;
	dir->y = b->y - a->y;
	dir->z = b->z - a->z;
	if (fabs(dir->x) >= fabs(dir->y))
		*step = fabs(dir->x);
	else
		*step = fabs(dir->y);
	dir->x /= *step;
	dir->y /= *step;
	dir->z /= *step;
}

void	draw_line(t_frame *frame, t_vec_ *a, t_vec_ *b)
{
	t_vec_	dir;
	double	step;
	t_vec_	pos;
	int		i;

	init_line(&dir, a, b, &step);
	pos.x = a->x;
	pos.y = a->y;
	pos.z = a->z;
	i = 0;
	while (++i <= step)
	{
		if (pos.x >= 0 && pos.x < WIN_WIDTH && pos.y >= 0 && pos.y < WIN_HEIGHT)
			put_pixel(frame, pos.x, pos.y, 0x00FFFFFF);
		pos.x += dir.x;
		pos.y += dir.y;
		pos.z += dir.z;
	}
}
