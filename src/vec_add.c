/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:49:02 by graux             #+#    #+#             */
/*   Updated: 2023/02/10 16:51:10 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/_vec.h"

void	vec_add(t_vec *a, t_vec *b)
{
	t_vec_	*aa;
	t_vec_	*bb;

	aa = (t_vec_ *) a;
	bb = (t_vec_ *) b;
	aa->x += bb->x;
	aa->y += bb->y;
	aa->z += bb->z;
}
