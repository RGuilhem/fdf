/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:11:52 by graux             #+#    #+#             */
/*   Updated: 2023/02/24 13:14:37 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/_map.h"
#include <stdlib.h>

void	map_destroy(t_map *map)
{
	t_map_	*m;

	m = map;
	wf_destroy(m->original_wf);
	wf_destroy(m->projected_wf);
	free(m);
}
