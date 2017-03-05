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
//	char 	*str = "8\n"
//			"##starta 1 2\n"
//			"##endy 1 3\n"
//			"b 1 4\n"
//			"c 1 5\n"
//			"d 1 6\n"
//			"4 1 7\n"
//			"3 1 8\n"
//			"x 1 9\n"
//			"z 1 10\n"
//			"9 1 11\n"
//			"5 1 16\n"
//			"6 1 17\n"
//			"a-b\n"
//			"a-c\n"
//			"a-d\n"
//			"a-4\n"
//			"c-4\n"
//			"c-x\n"
//			"c-z\n"
//			"b-3\n"
//			"d-5\n"
//			"4-z\n"
//			"4-3\n"
//			"x-y\n"
//			"3-5\n"
//			"3-9\n"
//			"3-6";
	t_room	*rooms;

	input = read_from_stdin();
//	input = ft_strsplit(str, '\n');
	rooms = parse_input(input);
	if (!rooms)
		return (3);
	if (valid_struct(rooms))
		lem_in(rooms);
//		solution(rooms)
//	i = -1;
//	while (input[++i])
//		ft_printf("|%s|\n", input[i]);
//	while (1);
	return (0);
}
