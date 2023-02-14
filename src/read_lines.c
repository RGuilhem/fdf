/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:54:21 by graux             #+#    #+#             */
/*   Updated: 2023/02/14 16:10:34 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/get_next_line.h"
#include "../includes/fdf.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

static char	**add_line(char **lines, char *added_line)
{
	char			**new_lines;
	static int		lines_number;
	int				i;

	new_lines = malloc(sizeof(char *) * (lines_number + 2));
	i = -1;
	while (++i < lines_number)
		new_lines[i] = lines[i];
	new_lines[i++] = added_line;
	new_lines[i] = NULL;
	if (lines_number != 0)
		free(lines);
	lines_number++;
	return (new_lines);
}

void	read_lines(const char *path, char ***lines)
{
	char	*read_line;
	int		fd;

	fd = open(path, O_RDONLY);
	read_line = get_next_line(fd);
	while (read_line)
	{
		*lines = add_line(*lines, read_line);
		read_line = get_next_line(fd);
	}
	close(fd);
}
