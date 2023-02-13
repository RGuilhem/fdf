/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:55:29 by graux             #+#    #+#             */
/*   Updated: 2023/02/13 13:24:46 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/_vec.h" //TODO remove
#include "../includes/_matrix.h" //TODO remove
#include <stdio.h>            //TODO remove
#include <math.h>

int	main(int argc, char *argv[])
{
	t_vec		*vec;
	t_vec_		*real;
	t_matrix	*matrix;

	(void) argc;
	(void) argv;
	vec = vec_create(1, 0, 0);
	real = (t_vec_ *) vec;
	printf("before: (%f, %f, %f)\n", real->x, real->y, real->z);
	matrix = matrix_rotz_create(1.5708);
	vec_multiply(vec, matrix);
	printf("after:  (%f, %f, %f)\n", real->x, real->y, real->z);
	vec_multiply(vec, matrix);
	printf("two times:  (%f, %f, %f)\n", real->x, real->y, real->z);
	return (0);
}
