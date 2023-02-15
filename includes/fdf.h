/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:53:08 by graux             #+#    #+#             */
/*   Updated: 2023/02/15 15:48:59 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "_vec.h"

// headers prefixed with _ should only be include if you know what you are
// doing. Stick to the API defined here pls

//TODO projections
//TODO user inputs

# define WIN_HEIGHT 1080
# define WIN_WIDTH 1920
# define SETTINGS_WIDTH 400
# define DEFAULT_ZOOM 10
# define DEFAULT_X_ANGLE 0.61547291
# define DEFAULT_Y_ANGLE 0
# define DEFAULT_Z_ANGLE 0.78539816

// KEYS VALUE
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_Q 12
# define KEY_E 14

# define KEY_H 4
# define KEY_J 38
# define KEY_K 40
# define KEY_L 37

# define KEY_P 35
# define KEY_PLUS 69
# define KEY_MINUS 78

# define ZOOM_INC 0.5
# define ANGLE_INC 0.03
# define OFFSET_INC 5

typedef void	t_map;
typedef void	t_wf;

typedef void	t_vec;
typedef void	t_matrix;

typedef void	t_gui;
typedef void	t_frame;

typedef struct s_data
{
	t_gui	*gui;
	t_map	*map;
}				t_data;

// files reading
void			read_lines(const char *path, char ***lines);

// Map
t_map			*map_create(char **map_lines);
void			map_destroy(t_map *map);
void			map_project(t_map *map, t_gui *gui);

// Wireframe (wf)
t_wf			*wf_create(int point_width, int point_height);
void			wf_destroy(t_wf *wf);
void			wf_scale(t_wf *wf, float scale_factor);
void			wf_translate(t_wf *wf, t_vec *direction);
void			wf_transform(t_wf *wf, t_matrix *transform);
void			wf_copy(t_wf *dest, t_wf *src);

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
t_gui			*gui_create(void);
void			gui_run(t_gui *gui, t_map *map);
void			gui_draw_map(t_gui *gui, t_map *map);
void			gui_draw_settings(t_gui *gui);
int				gui_draw_all(void *data);
void			gui_destroy(t_gui *gui);

// draw_line
void			draw_line(t_frame *frame, t_vec_ *a, t_vec_ *b);

#endif
