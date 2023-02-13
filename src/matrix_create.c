/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:56:54 by graux             #+#    #+#             */
/*   Updated: 2023/02/13 13:08:03 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/_matrix.h"
#include <math.h>
#include <stdlib.h>

t_matrix	*matrix_rotx_create(float a)
{
	t_matrix_	*matrix;

	matrix = malloc(sizeof(t_matrix_));
	matrix->row0 = vec_create(1, 0, 0);
	matrix->row1 = vec_create(0, cos(a), -sin(a));
	matrix->row2 = vec_create(0, sin(a), cos(a));
	return (matrix);
}

t_matrix	*matrix_roty_create(float a)
{
	t_matrix_	*matrix;

	matrix = malloc(sizeof(t_matrix_));
	matrix->row0 = vec_create(cos(a), 0, sin(a));
	matrix->row1 = vec_create(0, 1, 0);
	matrix->row2 = vec_create(-sin(a), 0, cos(a));
	return (matrix);
}

t_matrix	*matrix_rotz_create(float a)
{
	t_matrix_	*matrix;

	matrix = malloc(sizeof(t_matrix_));
	matrix->row0 = vec_create(cos(a), -sin(a), 0);
	matrix->row1 = vec_create(sin(a), cos(a), 0);
	matrix->row2 = vec_create(0, 0, 1);
	return (matrix);
}
