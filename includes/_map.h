/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _map.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:08:53 by graux             #+#    #+#             */
/*   Updated: 2023/02/07 15:54:05 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MAP_H
# define _MAP_H

# include "fdf.h"

typedef struct s_map_
{
	int		height;
	int		width;
	t_wf	*original_wf;
	t_wf	*projected_wf;
}				t_map_;

#endif
