/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:55:29 by graux             #+#    #+#             */
/*   Updated: 2023/02/14 16:12:34 by graux            ###   ########.fr       */
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
	int		i;

	if (argc == 2)
	{
		read_lines(argv[1], &lines);
		i = -1;
		while (lines[++i])
			printf("%s", lines[i]);
		map = map_create(lines);
		gui = gui_create();
	}
	printf("here\n");
	return (0);
}
