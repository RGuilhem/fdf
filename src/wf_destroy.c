/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wf_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:05:52 by graux             #+#    #+#             */
/*   Updated: 2023/02/24 13:10:44 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/_wf.h"
#include <stdlib.h>

void	wf_destroy(t_wf *wireframe)
{
	t_wf_	*wf;
	int		i;
	int		j;

	wf = wireframe;
	i = -1;
	while (++i < wf->height)
	{
		j = -1;
		while (++j < wf->width)
			vec_destroy(wf->points[i][j]);
		free(wf->points[i]);
	}
	free(wf);
}
