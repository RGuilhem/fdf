/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_draw_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:42:02 by graux             #+#    #+#             */
/*   Updated: 2023/02/14 16:44:22 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	gui_draw_all(void *data)
{
	t_gui	*gui;
	t_map	*map;

	gui = ((t_data *) data)->gui;
	map = ((t_data *) data)->map;
	gui_draw_map(gui, map);
	gui_draw_settings(gui);
	return (0);
}
