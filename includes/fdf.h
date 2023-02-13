/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:53:08 by graux             #+#    #+#             */
/*   Updated: 2023/02/13 15:13:26 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// headers prefixed with _ should only be include if you know what you are
// doing. Stick to the API defined here pls

//TODO projections
//TODO user inputs

# define WIN_HEIGHT 1080
# define WIN_WIDTH 1920
# define SETTINGS_WIDTH 400
# define DEFAULT_ZOOM 10
# define DEFAULT_X_ANGLE 0.78539816
# define DEFAULT_Y_ANGLE 0.78539816
# define DEFAULT_Z_ANGLE 0

typedef void	t_map;
typedef void	t_wf;

typedef void	t_vec;
typedef void	t_matrix;

typedef void	t_gui;
typedef void	t_frame;

// files reading
char			**read_lines(const char *path);

// Map
t_map			*map_create(const char **map_lines);
void			map_destroy(t_map *map);

// Wireframe (wf)
t_wf			*wf_create(int point_width, int point_height);
void			wf_destroy(t_wf *wf);
void			wf_scale(t_wf *wf, float scale_factor);
void			wf_translate(t_wf *wf, t_vec *direction);
void			wf_transform(t_wf *wf, t_matrix *transform);

// Vectors
t_vec			*vec_create(float x, float y, float z);
void			vec_destroy(t_vec *vec);
/*
 * Add a and b and store the result in a
 */
void			vec_add(t_vec *a, t_vec *b);
void			vec_multiply(t_vec *vec, t_matrix *matrix);

// Matrixes
t_matrix		*matrix_rotx_create(float angle);
t_matrix		*matrix_roty_create(float angle);
t_matrix		*matrix_rotz_create(float angle);
t_matrix		*matrix_scale_create(float scale_factor);
void			matrix_destroy(t_matrix *matrix);
//t_matrix		*matrix_multiply(t_matrix *a, t_matrix *b); TODO: not needed?

// mlx helpers
void			put_pixel(t_frame *frame, int x, int y, int color);
t_gui			*gui_create(int width, int height);
void			gui_destroy(t_gui *gui);

#endif
