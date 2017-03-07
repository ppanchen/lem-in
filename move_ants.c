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

void	give_name(t_path **path_s)
{
	int i;
	int j;
	int k;

	j = 0;
	i = 1;
	while (path_s[j])
	{
		path_s[j]->ants_name = (int *)malloc(sizeof(int) *\
		(path_s[j]->ants + 1));
		k = -1;
		while (++k < path_s[j]->ants)
			path_s[j]->ants_name[k] = i++;
		path_s[j]->ants_name[k] = 0;
		j++;
	}
}

t_path	**fill_paths(char **path, int ant)
{
	t_path	**path_s;
	int		i;
	int		j;

	i = count_items(path);
	path_s = (t_path **)malloc(sizeof(t_path *) * (i + 1));
	j = -1;
	while (++j < i)
	{
		path_s[j] = (t_path *)malloc(sizeof(t_path));
		path_s[j]->name = path[j];
		path_s[j]->ants = 0;
		path_s[j]->len = count_chars(path[j], '-') + 1;
	}
	path_s[j] = 0;
	j = ant;
	while (j != 0)
	{
		i = find_shortest(path_s);
		path_s[i]->ants++;
		j--;
	}
	give_name(path_s);
	return (path_s);
}

int		find_free_ant(t_path *path)
{
	int i;
	int res;

	i = -1;
	res = 0;
	while (path->ants_name[++i])
	{
		if (path->ants_name[i] != -1)
		{
			res = path->ants_name[i];
			path->ants_name[i] = -1;
			path->ants--;
			return (res);
		}
	}
	return (res);
}

void	move_ants_throught_path(t_room *room, t_path *path, int j)
{
	char	**rooms_name;
	t_room	*current;
	t_room	*next;
	t_room	*start;
	t_room	*end;

	start = find_role(room, 1);
	end = find_role(room, 2);
	rooms_name = ft_strsplit(path->name, '-');
	while (--j > 0)
	{
		current = find_name(room, rooms_name[j - 1]);
		next = find_name(room, rooms_name[j]);
		if ((current->ants != 0 || (current == start && path->ants != 0))
			&& (next->ants == 0 || next == end))
		{
			if (current == start && next == end)
				start_end(next, path);
			else
			{
				fill_next_ant(next, current, room, path);
				print_step(current, next, start);
			}
		}
	}
}

void	move_ants(t_room *room, char **path)
{
	int		i;
	int		j;
	t_path	**path_s;

	path_s = fill_paths(path, find_role(room, 1)->ants);
	while (find_role(room, 1)->ants != find_role(room, 2)->ants && (i = -1))
	{
		while (path_s[++i] && (j = count_chars(path_s[i]->name, '-') + 1))
		{
			move_ants_throught_path(room, path_s[i], j);
		}
		ft_printf("\n");
	}
}
