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

void	print_line(int l, char c)
{
	int i;

	i = -1;
	while (++i < l)
		ft_printf("%c", c);
	ft_printf("\n");
}

void	print_map(char *name, int *map)
{
	int j;

	ft_printf("|%-10s", name);
	j = -1;
	while (map[++j])
		if (map[j] == -1)
			ft_printf("|%-10c", ' ');
		else
		ft_printf("|%-10d", map[j]);
	ft_printf("|\n");
}

void	paste_map(t_room *room, int **map)
{
	int		i;
	t_room	*tmp;
	int 	l;

	tmp = room;
	l = 0;
	l += ft_printf("|%-10s", "");
	while (tmp)
	{
		l += ft_printf("|%-10s", tmp->name);
		tmp = tmp->next;
	}
	l += ft_printf("|\n") - 1;
	print_line(l, '-');
	i = -1;
	tmp = room;
	while (map[++i])
	{
		print_map(tmp->name, map[i]);
		print_line(l, '-');
		tmp = tmp->next;
	}
}
