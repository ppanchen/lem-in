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

int			is_room(char *room)
{
	int		i;
	char	**str;
	int		k;

	if (count_chars(room, ' ') != 2)
		return (0);
	if (room[0] == '#')
		room += ft_strstr(room, "##start") == 0 ? 5 : 7;
	str = ft_strsplit(room, ' ');
	i = 0;
	while (++i != 3)
	{
		if (ft_isdigit(str[i][0]) || str[i][0] == '+' || str[i][0] == '-')
			k = ft_atoi(str[1]);											//here can be a bug!!
		if ((str[i][0] == '+' ? ft_numlen(k) + 1 - ft_strlen(str[i]) :
				ft_numlen(k) - ft_strlen(str[i])) != 0)
			return (0);
	}
	i = -1;
	while (str[++i])
		ft_strdel(&str[i]);
	free(str);
	return (1);
}

int			is_connection(char *str, t_room *room)
{
	int		i;
	char	**rooms;
	int		ret;

	rooms = ft_strsplit(str, '-');
	i = 0;
	ret = 1;
	while (rooms[i])
		i++;
	if (i != 2)
		ret = 0;
	else if (!find_item(room, rooms[0]))
		ret = 0;
	else if (!find_item(room, rooms[1]))
		ret = 0;
	i = -1;
	while (rooms[++i])
		ft_strdel(&rooms[i]);
	free(rooms);
	return (ret);
}

void		fill_struct(t_room **room, char *input, int ant, int i)
{
	*room = (t_room *)malloc(sizeof(t_room));
	if (input[0] == '#')
	{
		(*room)->role = (ft_strstr(input, "##end") == 0) ? 1 : 2;
		input += (*room)->role == 1 ? 7 : 5;
	}
	else
		(*room)->role = 0;
	(*room)->name = ft_strsub(input, 0, ft_strchr(input, ' ') - input);
	input = ft_strchr(input, ' ') + 1;
	(*room)->x = ft_atoi(input);
	input += input[0] == '+' ? ft_numlen((*room)->x) + 2 :
								ft_numlen((*room)->x) + 1;
	(*room)->y = ft_atoi(input);
	(*room)->neighbors = ft_strdup("");
	(*room)->ants = (*room)->role == 1 ? ant : 0;
	(*room)->error = 0;
	(*room)->num = i;
	(*room)->next = 0;
}

void		fill_neighbor(t_room *ret, char *input)
{
	char	*name;
	t_room	*room;

	name = ft_strsub(input, 0, ft_strchr(input, '-') - input);
	input = ft_strdup(ft_strchr(input, '-') + 1);
	room = find_item(ret, name);
	room->neighbors = ft_strjoin_free(&room->neighbors, &input);
	input = ft_strdup(" ");
	room->neighbors = ft_strjoin_free(&room->neighbors, &input);
	ft_strdel(&name);
}

t_room		*parse_input(char **input)
{
	int		i;
	int		ant;
	t_room	*room;
	t_room	*ret;

	if ((ant = ft_atoi(input[0])) == 0)
		return (0);
	i = 1;
	if (is_room(input[i]))
		fill_struct(&ret, input[i], ant, i - 1);
	else
		return (0);
	room = ret;
	while (input[++i] && is_room(input[i]))
	{
		fill_struct(&(room->next), input[i], ant, i - 1);
		room = room->next;
	}
	i--;
	while (input[++i] && (is_connection(input[i], ret)))
		fill_neighbor(ret, input[i]);
	if (input[i])
		free_struct(&ret);
	return (ret);
}
