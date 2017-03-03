/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:36:44 by ppanchen          #+#    #+#             */
/*   Updated: 2017/03/03 16:36:49 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int 	**creat_map(t_room	*room)
{
	int		**map;
	int 	i;
	int 	j;
	int 	k;
	t_room	*cpy;

	cpy = room;
	k = 0;
	while (cpy && ++k)
		cpy = cpy->next;
	map = (int **)malloc(sizeof(int *) * (k + 1));
	map[k] = 0;
	j = -1;
	while (++j < k)
		map[j] = (int *)malloc(sizeof(int) * (k + 1));
	i = -1;
	while (map[++i] && (j = -1))
	{
		while(++j < k)
			map[i][j] = -1;
		map[i][j] = 0;
	}
	return (map);
}

int 	**paste_neighbors(t_room *room, int **map)
{
	t_room	*tmp;
	t_room	*tmp1;
	char 	**neighbors;
	int 	i;

	tmp = room;
	while (tmp && (i = -1))
	{
		neighbors = ft_strsplit(tmp->neighbors, ' ');
		while(neighbors[++i])
		{
			tmp1 = find_name(room, neighbors[i]);
			map[tmp->num][tmp1->num] = 1;
			map[tmp1->num][tmp->num] = 1;
		}
		i = -1;
		while (neighbors[++i])
			ft_strdel(&neighbors[i]);
		free(neighbors);
		tmp = tmp->next;
	}
	return (map);
}
