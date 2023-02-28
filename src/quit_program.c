/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:26:49 by graux             #+#    #+#             */
/*   Updated: 2023/02/28 13:10:55 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdlib.h>

int	quit_program(t_data *data)
{
	gui_destroy(data->gui);
	map_destroy(data->map);
	exit(EXIT_SUCCESS);
	return (0);
}
