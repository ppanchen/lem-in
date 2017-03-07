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
	char 	*str = "8\n"
			"##start1 23 3\n"
			"2 16 7\n"
			"3 16 3\n"
			"4 16 5\n"
			"5 9 3\n"
			"6 1 5\n"
			"7 4 8\n"
			"##end0 9 5\n"
			"0-4\n"
			"0-6\n"
			"1-3\n"
			"4-3\n"
			"5-2\n"
			"3-5\n"
			"4-2\n"
			"2-1\n"
			"7-6\n"
			"7-2\n"
			"7-4\n"
			"6-5\n"
			"1-0";
	t_room	*rooms;

//	input = read_from_stdin();
	input = ft_strsplit(str, '\n');
	rooms = parse_input(input);
	if (!rooms)
		return (3);
	if (valid_struct(rooms))
		lem_in(rooms);
	free_struct(&rooms);
//	i = -1;
//	while (input[++i])
//		ft_printf("|%s|\n", input[i]);
	while (1);
	return (0);
}
