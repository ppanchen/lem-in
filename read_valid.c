/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 16:53:28 by ppanchen          #+#    #+#             */
/*   Updated: 2017/02/20 16:53:29 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char 	**read_from_stdin(void)
{
	char	*ret;
	char 	*str;
	char 	**arr;

	str = ft_strdup("");
	while (get_next_line(0, &ret) > 0)
	{
		if (ft_strcmp(ret, "") == 0)
		{
			ft_strdel(&str);
			str = ret;
			break ;
		}
		if (ret[0] == '#' && ft_strcmp(ret, "##start") &&
				ft_strcmp(ret, "##end"))
			continue ;
		if (ret[0] == '#')
			str = ft_strjoin_free(&str, &ret);
		else
		{
			str = ft_strjoin_free(&str, &ret);
			ret = ft_strdup("\n");
			str = ft_strjoin_free(&str, &ret);
		}
	}
	arr = ft_strsplit(str, '\n');
	ft_strdel(&str);
	return (arr);
}

int 	valid_struct(t_room *room)
{
	t_room	*tmp;
	t_room	*tmp1;

	tmp = room;
	while (tmp)
	{
		if (tmp->name[0] == 'L')
			return (0);
		tmp = tmp->next;
	}
	if (!find_role(room, 1) || !find_role(room, 2))
		return (0);
	tmp = room;
	while (tmp)
	{
		tmp1 = tmp->next;
		while (tmp1)
		{
			if ((tmp->x == tmp1->x && tmp->y == tmp1->y) ||
					!ft_strcmp(tmp->name, tmp1->name))
				return (0);
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
	}
	return (1);
}