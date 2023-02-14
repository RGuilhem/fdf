/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:55:29 by graux             #+#    #+#             */
/*   Updated: 2023/02/14 13:42:26 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>            //TODO remove
#include <math.h>

int	main(int argc, char *argv[])
{
	t_gui	*gui;
	t_map	*map;
	char	**lines;

	if (argc == 2)
	{
		lines = read_lines(argv[1]);
		map = map_create(lines);
		gui = gui_create();
	}
	return (0);
}
