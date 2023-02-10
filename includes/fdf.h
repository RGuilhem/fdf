/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:53:08 by graux             #+#    #+#             */
/*   Updated: 2023/02/10 13:40:09 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// headers prefixed with _ should only be include if you know what you are
// doing. Stick to the API defined here pls

//TODO projections
//TODO user inputs

typedef void	t_map;
typedef void	t_wf;

typedef void	t_vec;

typedef void	t_gui;
typedef void	t_frame;

typedef void	t_matrtix;

// files reading
char			**read_lines(const char *path);

// Map
t_map			*map_create(const char **map_lines);
void			map_destroy(t_map *map);

// Wireframe (wf)
t_wf			*wf_create(int point_width, int point_height);
void			wf_destroy(t_wf *wf);

// Vectors
t_vec			*vec_create(int x, int y, int z);
void			vec_destroy(t_vec *vec);

// mlx helpers
void			put_pixel(t_frame *frame, int x, int y, int color);
t_gui			*gui_create(int width, int height);
void			gui_destroy(t_gui *gui);

#endif
