/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 15:46:46 by ppanchen          #+#    #+#             */
/*   Updated: 2017/02/24 15:46:48 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int 	is_room(char *room)
{
	int i;
	char **str;
	int k;
	int r;

	i = -1;
	while (room[++i])
		if (room[i] == ' ')
			i++;
	if (i != 2)
		return (0);
	str = ft_strsplit(room, ' ');
	if (!ft_isdigit(str[1][0]) && str[1][0] != '+' && str[1][0] != '-')
		k  = ft_atoi(str[1]);
	r = str[1][0] == '+' ? ft_numlen(k) + 1 - ft_strlen(str[1]);
	if (r != 0)
		return (0);
	if (!ft_isdigit(str[2][0]) && str[2][0] != '+' && str[2][0] != '-')
		k  = ft_atoi(str[2]);
	r = str[2][0] == '+' ? ft_numlen(k) + 1 - ft_strlen(str[2]);
	if (r != 0)
		return (0);
	return (1);
}

t_room	*parse_input(char	**input)
{
	int		i;
	t_room	*room;
	t_room	*ret;
	char 	*cpy;

	if ((g_ant = ft_atoi(input[0])) == 0)
		return (0);
	i = 0;
	room = (t_room *)malloc(sizeof(t_room));
	ret = room;
	while (input[++i] && is_room(input[i]))
	{
		cpy = input[i];
		if (cpy[0] == '#')
		{
			room->role = (ft_strcmp(cpy, "##start") == 0) ? 1 : 2;
			continue ;
		}
		room->name = ft_strsub(cpy, 0, ft_strchr(cpy, ' ') - cpy);
		cpy = ft_strchr(cpy, ' ') + 1;
		room->x = ft_atoi(cpy);
		cpy += cpy[0] == '+' ? ft_numlen(room->x) + 2 : ft_numlen(room->x) + 1;
		room->y = ft_atoi(cpy);
		room->next = (t_room *)malloc(sizeof(t_room));
		room = room->next;
	}
	return (ret);
}
