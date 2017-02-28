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

	i = -1;
	if (room[0] == '#')
		return (1);
	k = 0;
	while (room[++i])
		if (room[i] == ' ')
			k++;
	if (k != 2)
		return (0);
	str = ft_strsplit(room, ' ');
	if (ft_isdigit(str[1][0]) || str[1][0] == '+' || str[1][0] == '-')
		k  = ft_atoi(str[1]);
	if ((str[1][0] == '+' ? ft_numlen(k) + 1 - ft_strlen(str[1]) :\
	ft_numlen(k) - ft_strlen(str[1])) != 0)
		return (0);
	if (ft_isdigit(str[2][0]) || str[2][0] == '+' || str[2][0] == '-')
		k  = ft_atoi(str[2]);
	if ((str[2][0] == '+' ? ft_numlen(k) + 1 - ft_strlen(str[2]) :\
	ft_numlen(k) - ft_strlen(str[2])) != 0)
		return (0);
	i = -1;
	while (str[++i])
		ft_strdel(&str[i]);
	free(str);
	return (1);
}

t_room 	*is_connection(char *str, t_room *room)
{
	int		i;
	char 	**rooms;

	rooms = ft_strsplit(str, '-');
	i = 0;
	while (rooms[i])
		i++;
	if (i != 2)
		free_struct(room);
	else if (!find_item(room, rooms[0]))
		free_struct(room);
	else if (!find_item(room, rooms[1]))
		free_struct(room);
	else
		i = -3;
	if (i != -3)
		ft_memdel(&room);
	i = -1;
	while (rooms[++i])
		ft_strdel(&rooms[i]);
	free(rooms);
	return (room);
}

t_room	*parse_input(char	**input)
{
	int		i;
	t_room	*room;
	t_room	*ret;
	char 	*cpy;
	char 	*name;

	if ((g_ant = ft_atoi(input[0])) == 0)
		return (0);
	i = 0;
	room = (t_room *)malloc(sizeof(t_room));
	ret = room;
	cpy = input[++i];
	if (cpy[0] == '#')
	{
		room->role = (ft_strcmp(cpy, "##start") == 0) ? 1 : 2;
		cpy = input[++i];
	}
	else
		room->role = 0;
	room->name = ft_strsub(cpy, 0, ft_strchr(cpy, ' ') - cpy);
	cpy = ft_strchr(cpy, ' ') + 1;
	room->x = ft_atoi(cpy);
	cpy += cpy[0] == '+' ? ft_numlen(room->x) + 2 : ft_numlen(room->x) + 1;
	room->y = ft_atoi(cpy);
	room->neighbors = ft_strdup("");
	room->next = 0;
	while (input[++i] && is_room(input[i]))
	{
		cpy = input[i];
		room->next = (t_room *)malloc(sizeof(t_room));
		room = room->next;
		if (cpy[0] == '#')
		{
			room->role = (ft_strcmp(cpy, "##start") == 0) ? 1 : 2;
			cpy = input[++i];
		}
		else
			room->role = 0;
		room->name = ft_strsub(cpy, 0, ft_strchr(cpy, ' ') - cpy);
		cpy = ft_strchr(cpy, ' ') + 1;
		room->x = ft_atoi(cpy);
		cpy += cpy[0] == '+' ? ft_numlen(room->x) + 2 : ft_numlen(room->x) + 1;
		room->y = ft_atoi(cpy);
		room->neighbors = ft_strdup("");
		room->next = 0;
	}
	i--;
	while (input[++i] && (ret = is_connection(input[i], ret)))
	{
		cpy = input[i];
		name = ft_strsub(cpy, 0, ft_strchr(cpy, '-') - cpy);
		cpy = ft_strdup(ft_strchr(cpy, '-') + 1);
		room = find_item(ret, name);
		room->neighbors = ft_strjoin_free(&room->neighbors, &cpy);
		cpy = ft_strdup(" ");
		room->neighbors = ft_strjoin_free(&room->neighbors, &cpy);
	}
	return (ret);
}
