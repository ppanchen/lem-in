/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_solution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 18:59:56 by ppanchen          #+#    #+#             */
/*   Updated: 2017/03/03 18:59:57 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		cat_path1(t_room *room, t_c *loc, char *str, char **res)
{
	char	*tmp;
	char	*path;

	if (ft_strstr(str, find_num(room, loc->j)->name) != 0)
		return (1);
	path = ft_strjoin_multy(4, " ", str, "-", find_num(room, loc->j)->name);
	loc->d = 1;
	tmp = add_paths(loc->map, room, path, *loc);
	*res = ft_strjoin_free_multy(3, res, &path, &tmp);
	return (1);
}

int		cat_path2(t_room *room, t_c *loc, char *str, char **res)
{
	char	*tmp;
	char	*path;

	if (ft_strstr(str, find_num(room, loc->i)->name) != 0)
		return (1);
	path = ft_strjoin_multy(4, " ", str, "-", find_num(room, loc->i)->name);
	loc->d = 2;
	tmp = add_paths(loc->map, room, path, *loc);
	*res = ft_strjoin_free_multy(3, res, &path, &tmp);
	return (1);
}

char	*add_paths(int **map, t_room *room, char *str, t_c c)
{
	t_c		loc;
	char 	*res;

	loc.i = c.i;
	loc.j = c.j;
	loc.map = map;
	res = ft_strdup(" ");
	if (c.d != 1 && (loc.j = -1))
	{
		while (map[c.i][++loc.j])
			if (map[c.i][loc.j] == 1 && loc.j != c.j)
				cat_path1(room, &loc, str, &res);
	}
	if (c.d != 2 && (loc.i = -1))
	{
		while (map[++loc.i])
			if (map[loc.i][c.j] == 1 && loc.i != c.i)
				cat_path2(room, &loc, str, &res);
	}
	return (res);
}

char 	*take_path(t_room *room, int **map)
{
	t_c		c;
	char 	*res;
	char 	*path;
	char 	*tmp;


	c.i = -1;
	res = ft_strdup("");
	while (map[++c.i] && (c.j = -1))
	{
		while (map[c.i][++c.j])
		{
			if (map[c.i][c.j] == 1)
			{
//				path = c.i < c.j ?	ft_strjoin_multy(3,\
//				find_num(room, c.i)->name, "-", find_num(room, c.j)->name) :
//					   ft_strjoin_multy(3, find_num(room, c.j)->name,\
//					   "-", find_num(room, c.i)->name);
				path = ft_strjoin_multy(3, find_num(room, c.i)->name, "-", find_num(room, c.j)->name);
//				c.d = c.i < c.j ? 1 : 2;
				c.d = 1;
				tmp =  add_paths(map, room, path, c);
				path = ft_strjoin_free(&path, &tmp);
				res = ft_strjoin_free_multy(2, &res, &path);
			}
		}
	}
	return (res);
}

char 	**choose_paths(t_room *room, char **path)
{
	char	**tmp;
	char 	**ret;
	int 	i;

	i = -1;
	tmp = ft_strsplit((*path), ' ');
	free((*path));
	*path = ft_strdup("");
	while (tmp[++i])
		checkroom(room, tmp[i], path);
	ft_arrdel(&tmp);
	ret = ft_strsplit(*path, ' ');
	ft_strdel(path);
	return (ret);
}

int 	lem_in(t_room *room)
{
	int		**map;
	int 	i;
	int 	j;
	char 	*path;
	char 	**paths;

	map = creat_map(room);
	map = paste_neighbors(room, map);
	paste_map(room, map);
	path = take_path(room, map);
	paths = choose_paths(room, &path);

	i = -1;
	while (paths[++i])
		ft_printf("%s\n", paths[i]);
	ft_arrdel(&paths);
	ft_arrmemdel((void ***)&map);


	return (1);
}
