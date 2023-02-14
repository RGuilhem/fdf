/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _wf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:29:53 by graux             #+#    #+#             */
/*   Updated: 2023/02/14 14:59:29 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _WF_H
# define _WF_H

# include "../includes/fdf.h"

typedef struct s_wf_
{
	int		height;
	int		width;
	t_vec	***points;	
}				t_wf_;

#endif
