/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 16:32:39 by ppanchen          #+#    #+#             */
/*   Updated: 2017/03/05 16:32:41 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*make_str(char **rooms)
{
	char	*ret;
	char	*tmpstr;
	int		i;

	i = -1;
	ret = ft_strdup("");
	while (rooms[++i])
	{
		tmpstr = ret;
		ret = rooms[i + 1] != 0 ? ft_strjoin_multy(3, tmpstr, rooms[i], "-") :
			ft_strjoin_multy(3, tmpstr, rooms[i], " ");
		ft_strdel(&tmpstr);
	}
	return (ret);
}

void	checkroom(t_room *room, char *tmp, char **path)
{
	char	**rooms;
	int		j;
	char	*tmpcpy;

	j = 0;
	rooms = ft_strsplit(tmp, '-');
	while (rooms[j])
		j++;
	if ((ft_strcmp(rooms[0], find_role(room, 1)->name) == 0 &&
			ft_strcmp(rooms[j - 1], find_role(room, 2)->name) == 0) ||
		(ft_strcmp(rooms[j - 1], find_role(room, 1)->name) == 0 &&
				ft_strcmp(rooms[0], find_role(room, 2)->name) == 0))
	{
		if (ft_strcmp(rooms[0], find_role(room, 1)->name) != 0)
			rooms = ft_arrrev(rooms);
		tmpcpy = make_str(rooms);
		if (ft_strstr(*path, tmpcpy) == 0)
			*path = ft_strjoin_free(path, &tmpcpy);
		ft_strdel(&tmpcpy);
	}
	ft_arrdel(&rooms);
}

int		count_items(char **room)
{
	int		i;

	i = 0;
	while (room[i])
		i++;
	return (i);
}
