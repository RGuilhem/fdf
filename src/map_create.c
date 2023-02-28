/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:43:40 by graux             #+#    #+#             */
/*   Updated: 2023/02/28 11:23:36 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libft/includes/libft.h"
#include "../includes/_wf.h"
#include "../includes/_map.h"

static void	free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

static int	count_words(char *line)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (line[i])
	{
		while (line[i] && line[i] == ' ')
			i++;
		count++;
		while (line[i] && line[i] != ' ')
			i++;
	}
	return (count);
}

static int	map_init_size(char **map_lines, t_map_ *map)
{
	int		i;
	int		spaces;

	if (!map_lines)
		return (0);
	map->height = 0;
	i = -1;
	while (map_lines[++i])
	{
		map->height += 1;
		spaces = count_words(map_lines[i]);
		if (i != 0)
		{
			if (spaces != map->width)
				return (0);
		}
		else
			map->width = spaces;
	}
	ft_printf("size initialized: %d %d\n", map->width, map->height);
	return (1);
}

static void	map_fill(t_map_ *map, char **map_lines)
{
	int		i;
	int		j;
	char	**line_split;
	t_wf_	*original_wf;
	t_wf_	*projected_wf;

	ft_printf("filling map\n");
	i = -1;
	original_wf = map->original_wf;
	projected_wf = map->projected_wf;
	while (++i < map->height)
	{
		j = -1;
		line_split = ft_split(map_lines[i], ' ');
		while (++j < map->width)
		{
			original_wf->points[i][j] = vec_create(j, i,
					ft_atoi(line_split[j]));
			projected_wf->points[i][j] = vec_create(0, 0, 0);
		}
		free_split(line_split);
	}
}

t_map	*map_create(char **map_lines)
{
	t_map_	*map;

	map = malloc(sizeof(t_map_));
	map_init_size(map_lines, map);
	map->original_wf = wf_create(map->width, map->height);
	map->projected_wf = wf_create(map->width, map->height);
	map_fill(map, map_lines);
	ft_printf("Map created successfuly\n");
	return (map);
}
