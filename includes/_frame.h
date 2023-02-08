/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _frame.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:04:35 by graux             #+#    #+#             */
/*   Updated: 2023/02/07 15:06:41 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FRAME_H
# define _FRAME_H

typedef struct s_priv_frame
{
	void	*img;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_priv_frame;

#endif
