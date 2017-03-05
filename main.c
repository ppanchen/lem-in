/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 16:31:48 by ppanchen          #+#    #+#             */
/*   Updated: 2017/02/20 16:31:49 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

//TODO seg with empty file;

int		main(int ac, char **av)
{
	int		i;
	char 	**input;
//	char 	*str = "3\n"
//			"2 5 0\n"
//			"##start0 1 2\n"
//			"##end1 9 2\n"
//			"3 5 4\n"
//			"0-2\n"
//			"0-3\n"
//			"2-1\n"
//			"3-1\n"
//			"2-3";
	t_room	*rooms;

	input = read_from_stdin();
//	input = ft_strsplit(str, '\n');
	rooms = parse_input(input);
	if (!rooms)
		return (3);
	if (valid_struct(rooms))
		lem_in(rooms);
//	free_struct(&rooms);
//		solution(rooms)
//	i = -1;
//	while (input[++i])
//		ft_printf("|%s|\n", input[i]);
	while (1);
	return (0);
}
