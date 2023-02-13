/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_multiply.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:05:44 by graux             #+#    #+#             */
/*   Updated: 2023/02/13 12:08:12 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/_matrix.h"
#include "../includes/_vec.h"

void	vec_multiply(t_vec *vec, t_matrix *matrix)
{
	t_vec_	*row0;
	t_vec_	*row1;
	t_vec_	*row2;
	t_vec_	save;
	t_vec_	*v;

	row0 = (t_vec_ *)((t_matrix_ *) matrix)->row0;
	row1 = (t_vec_ *)((t_matrix_ *) matrix)->row1;
	row2 = (t_vec_ *)((t_matrix_ *) matrix)->row2;
	v = (t_vec_ *) vec;
	save.x = v->x;
	save.y = v->y;
	save.z = v->z;
	v->x = row0->x * save.x + row0->y * save.y + row0->z * save.z;
	v->y = row1->x * save.x + row1->y * save.y + row1->z * save.z;
	v->z = row2->x * save.x + row2->y * save.y + row2->z * save.z;
}
