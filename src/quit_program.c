/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:26:49 by graux             #+#    #+#             */
/*   Updated: 2023/02/28 11:30:10 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdlib.h>

void	quit_program(t_gui *gui, t_map *map)
{
	gui_destroy(gui);
	map_destroy(map);
	exit(EXIT_SUCCESS);
}
