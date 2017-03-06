/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 13:02:38 by ppanchen          #+#    #+#             */
/*   Updated: 2017/03/06 13:02:40 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int 	count_rooms(char **room)
{
	int		i;

	i = 0;
	while (room[i])
		i++;
	return (i);
}

int		clr_status(t_room *start)
{
	t_room *tmp;

	tmp = start;
	while (tmp)
	{
		tmp->status = 0;
		tmp = tmp->next;
	}
	return (1);
}

void	move_ants(t_room *room, char **path)
{
	int		i;
	int		ants;
	char	**rooms_name;
	int 	j;
	t_room	*tmp;

	ants = find_role(room, 1)->ants;
	while (find_role(room, 2)->ants != ants && (i = -1))
	{
		while (path[++i] && (rooms_name = ft_strsplit(path[i], '-')))
		{
			j = count_rooms(rooms_name);
			while (rooms_name[--j] && j != 0)
			{
				if (find_name(room, rooms_name[j - 1])->ants != 0 &&
						(find_name(room, rooms_name[j]) ->ants == 0 ||
								(find_name(room, rooms_name[j]) == find_role(room, 2)))&&
						find_name(room, rooms_name[j - 1])->status != 1 &&
						find_name(room, rooms_name[j])->status != 1)
				{
					find_name(room, rooms_name[j - 1])->ants--;
					find_name(room, rooms_name[j])->ants++;
					if (find_name(room, rooms_name[j]) != find_role(room, 2))
						find_name(room, rooms_name[j])->status = 1;
					if (find_name(room, rooms_name[j - 1]) != find_role(room, 1))
						find_name(room, rooms_name[j - 1])->status = 1;
					break ;
				}
			}
			ft_arrdel(&rooms_name);
		}
		ft_printf("Step.\n");
		clr_status(room);
	}
}
