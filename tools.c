/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 19:02:34 by ppanchen          #+#    #+#             */
/*   Updated: 2017/02/24 19:02:35 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*find_item(t_room *start, char	*name)
{
	t_room	*tmp;

	tmp = start;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, name) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (0);
}

int 	free_struct(t_room *start)
{
	if (start)
	{
		ft_strdel(&start->name);
		ft_strdel(&start->neighbors);
		free_struct(start->next);
		ft_memdel(&start->next);
	}
	return (0);
}