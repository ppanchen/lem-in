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

char 	**take_path(t_room *room, int **map)
{
	int 	i;
	int 	j;
	char 	**path;
	char 	*str;
	t_room	*f;
	t_room	*f1;


	i = -1;
	while (map[++i] && (j = -1))
	{
		while (map[i][++j])
		{
			if (map[i][j] == 1)
			{
				f = find_num(room, i);
				f1 = find_num(room, j);
				str = ft_strjoin_multy(4, f->name, "-", f1->name, " ");
//				map[j][i] = -1;
				ft_printf("%s\n", str);
			}
		}
	}
	return (0);
}

int 	lem_in(t_room *room)
{
	int		**map;
	int 	i;
	int 	j;
	char 	**path;

	map = creat_map(room);
	map = paste_neighbors(room, map);
	path = take_path(room, map);

	//	i = -1;
	//	while (map[++i])
	//	{
	//		j = -1;
	//		while (map[i][++j])
	//			ft_printf("|%2d|", map[i][j]);
	//		ft_printf("\n");
	//	}
	return (1);
}
