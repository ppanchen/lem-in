/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_choose.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 16:27:08 by ppanchen          #+#    #+#             */
/*   Updated: 2017/03/06 16:27:09 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*make_paths_str(char **paths)
{
	int		i;
	char	*rooms;
	char	*tmp;

	i = -1;
	rooms = ft_strdup("");
	while (paths[++i])
	{
		tmp = ft_strsub(paths[i], ft_strchr(paths[i], '-') - paths[i],\
		ft_strrchr(paths[i], '-') - paths[i]);
		rooms = ft_strjoin_free(&rooms, &tmp);
	}
	return (rooms);
}

int		check_rooms(char *ch_path, char *path)
{
	char	**room;
	char	**paths;
	char	*rooms;
	char	*tmp;
	int		i;

	room = ft_strsplit(path, '-');
	paths = ft_strsplit(ch_path, ' ');
	rooms = make_paths_str(paths);
	ft_arrdel(&paths);
	i = -1;
	while (room[++i] && (tmp = ft_strjoin_multy(3, "-", room[i], "-")))
	{
		if (ft_strstr(rooms, tmp) != 0)
		{
			ft_arrdel(&room);
			ft_strdel(&rooms);
			ft_strdel(&tmp);
			return (0);
		}
		ft_strdel(&tmp);
	}
	ft_arrdel(&room);
	ft_strdel(&rooms);
	return (1);
}

void	sort_arr(char **arr, int size)
{
	int		i;
	int		j;
	int		*k;
	int		t;
	char	*tmp;

	k = (int *)malloc(sizeof(int) * size);
	i = -1;
	while (arr[++i])
		k[i] = count_chars(arr[i], '-');
	i = -1;
	while (++i < size && (j = -1))
		while (++j < size - i - 1)
			if (k[j] > k[j + 1])
			{
				t = k[j];
				k[j] = k[j + 1];
				k[j + 1] = t;
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
	ft_memdel((void **)&k);
}

void	sort_choose(char **paths)
{
	char	**arr;
	char	*tmp;
	int		i;

	i = -1;
	arr = ft_strsplit(*paths, ' ');
	sort_arr(arr, count_rooms(arr));
	ft_strdel(paths);
	*paths = ft_strdup("");
	while (arr[++i])
		if (check_rooms(*paths, arr[i]))
		{
			tmp = *paths;
			*paths = ft_strjoin_multy(3, *paths, arr[i], " ");
			ft_strdel(&tmp);
		}
	ft_arrdel(&arr);
}
