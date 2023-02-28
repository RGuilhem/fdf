/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:16:16 by graux             #+#    #+#             */
/*   Updated: 2023/02/28 10:47:34 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/_vec.h"
#include "../includes/error.h"
#include <stdlib.h>

t_vec	*vec_create(float x, float y, float z)
{
	t_vec_	*new_vec;

	new_vec = malloc(sizeof(t_vec_));
	if (!new_vec)
		return (NULL);
	new_vec->x = x;
	new_vec->y = y;
	new_vec->z = z;
	return (new_vec);
}
