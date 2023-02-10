/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:36:26 by graux             #+#    #+#             */
/*   Updated: 2023/02/10 12:50:17 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/mlx.h"
#include "../includes/_frame.h"

void	put_pixel(t_frame *frame, int x, int y, int color)
{
	char			*pix;
	t_priv_frame	*fra;

	fra = (t_priv_frame *) frame;
	pix = fra->address + (y * fra->line_length + x * (fra->bits_per_pixel / 8));
	*(unsigned int *) pix = color;
}
