/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _gui.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:52:30 by graux             #+#    #+#             */
/*   Updated: 2023/02/24 13:25:24 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GUI_H
# define _GUI_H

# include "fdf.h"

typedef struct s_gui_
{
	void	*mlx;
	void	*mlx_win;
	float	x_angle;
	float	y_angle;
	float	z_angle;
	int		proj;
	t_vec	*zoom;
	t_vec	*offset;
	t_frame	*frame_buffer[2];
}				t_gui_;

#endif
