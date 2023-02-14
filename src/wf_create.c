/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wf_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:56:03 by graux             #+#    #+#             */
/*   Updated: 2023/02/14 15:03:23 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/_wf.h"
#include <stdlib.h>

t_wf	*wf_create(int width, int height)
{
	t_wf_	*wf;
	int		i;

	wf = malloc(sizeof(t_wf_));
	if (!wf)
		return (NULL);
	wf->height = height;
	wf->width = width;
	wf->points = malloc(sizeof(t_vec *) * height);
	if (!wf->points)
		return (NULL);
	i = -1;
	while (++i < height)
	{
		wf->points[i] = malloc(sizeof(t_vec *) * width);
		if (!wf->points[i])
			return (NULL);
	}
	return (wf);
}
