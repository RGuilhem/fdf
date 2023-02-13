/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _matrix.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:51:49 by graux             #+#    #+#             */
/*   Updated: 2023/02/13 10:53:58 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MATRIX_H
# define _MATRIX_H

# include "fdf.h"

typedef struct s_matrix_
{
	t_vec	*row0;
	t_vec	*row1;
	t_vec	*row2;
}				t_matrix_;

#endif
