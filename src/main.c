/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:55:29 by graux             #+#    #+#             */
/*   Updated: 2023/02/28 13:27:52 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdlib.h>

static void	free_lines(char **lines)
{
	int	i;

	i = -1;
	if (lines)
	{
		while (lines[++i])
			free(lines[i]);
		free(lines);
	}
}

int	main(int argc, char *argv[])
{
	t_gui	*gui;
	t_map	*map;
	t_data	data;
	char	**lines;

	if (argc == 2)
	{
		read_lines(argv[1], &lines);
		map = map_create(lines);
		free_lines(lines);
		gui = gui_create();
		data.gui = gui;
		data.map = map;
		if (!gui || !map)
			quit_program(&data);
		gui_run(gui, map);
	}
	return (0);
}
