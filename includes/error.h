/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:19:52 by graux             #+#    #+#             */
/*   Updated: 2023/02/10 16:12:05 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

typedef struct s_err_ressource
{
	void	**ressource;
	void	(*dealloc_ress)(void *);
}			t_err_ressource;

typedef enum e_err_action
{
	ADD_RESS = 0,
	LIST,
	CRASH,
	QUIT,
}			t_err_action;

void	error_handler(t_err_action action, void **ress,
			void (*dealloc_ress)(void *));
void	add_ress(t_err_ressource ***ressources, void **ress,
			void (*dealloc_ress)(void *));
void	crash(t_err_ressource **ressources, int status);
void	list_ress(t_err_ressource **ressources);

#endif
