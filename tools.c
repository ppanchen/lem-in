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

t_room	*find_name(t_room *start, char *name)
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

t_room	*find_role(t_room *start, int role)
{
	t_room	*tmp;

	tmp = start;
	while (tmp)
	{
		if (tmp->role == role)
			return (tmp);
		tmp = tmp->next;
	}
	return (0);
}

t_room	*find_num(t_room *start, int num)
{
	t_room	*tmp;

	tmp = start;
	while (tmp)
	{
		if (tmp->num == num)
			return (tmp);
		tmp = tmp->next;
	}
	return (0);
}

int		free_struct(t_room **start)
{
	if (*start)
	{
		ft_strdel(&(*start)->name);
		ft_strdel(&(*start)->neighbors);
		free_struct(&(*start)->next);
		ft_memdel(start);
	}
	return (0);
}

int		find_shortest(t_path **path)
{
	int		i;
	int		sh;

	i = -1;
	sh = 0;
	while (path[++i])
	{
		if (path[i]->len + path[i]->ants <
			path[sh]->len + path[sh]->ants)
			sh = i;
	}
	return (sh);
}
