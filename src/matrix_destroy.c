/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:53:39 by graux             #+#    #+#             */
/*   Updated: 2023/02/13 14:56:11 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/_matrix.h"
#include <stdlib.h>

void	matrix_destroy(t_matrix *matrix)
{
	t_matrix_	*mat;

	mat = matrix;
	vec_destroy(mat->row0);
	vec_destroy(mat->row1);
	vec_destroy(mat->row2);
	free(mat);
}
