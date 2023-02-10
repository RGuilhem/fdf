/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <graux@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:40:18 by graux             #+#    #+#             */
/*   Updated: 2023/02/10 16:26:19 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/error.h"
#include <stdlib.h>

void	error_handler(t_err_action action, void **ress,
			void (*dealloc_ress)(void *))
{
	static t_err_ressource	**ressources;

	if (action == ADD_RESS)
		add_ress(&ressources, ress, dealloc_ress);
	else if (action == LIST)
		list_ress(ressources);
	else if (action == CRASH)
		crash(ressources, EXIT_FAILURE);
	else if (action == QUIT)
		crash(ressources, EXIT_SUCCESS);
}

static int	ress_len(t_err_ressource **ressources)
{
	int	len;

	if (!ressources)
		return (0);
	len = 0;
	while (ressources[len])
		len++;
	return (len);
}

void	add_ress(t_err_ressource ***ressources, void **ress,
			void (*dealloc_ress)(void *))
{
	int				len;
	int				i;
	t_err_ressource	**new_ress;

	len = ress_len(*ressources);
	new_ress = malloc(sizeof(t_err_ressource *) * (len + 2));
	if (!new_ress)
		crash(*ressources, EXIT_FAILURE);
	i = -1;
	while ((*ressources)[++i])
		new_ress[i] = (*ressources)[i];
	new_ress[i] = malloc(sizeof(t_err_ressource));
	if (!new_ress[i])
		crash(*ressources, EXIT_FAILURE);
	new_ress[i]->ressource = ress;
	new_ress[i++]->dealloc_ress = dealloc_ress;
	new_ress[i] = NULL;
	free(*ressources);
	*ressources = new_ress;
}

void	crash(t_err_ressource **ressources, int status)
{
	int	i;

	i = -1;
	if (!ressources)
		exit(EXIT_FAILURE);
	while (ressources[++i])
	{
		if (*(ressources[i]->ressource) != NULL)
			ressources[i]->dealloc_ress(*(ressources[i]->ressource));
	}
	exit(status);
}

void	list_ress(t_err_ressource **ressources)
{
	ft_printf("TODO: implement list_ress\n");
}
