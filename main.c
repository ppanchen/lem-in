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

int		main(int ac, char **av)
{
	int		i;
	char 	**input;
	char 	*str = "8\n"
			"b 4 5\n"
			"##starta 5 7\n"
			"##endd 6 4\n"
			"c 1 0\n"
			"e 3 4\n"
			"f 2 2\n"
			"a-b\n"
			"a-c\n"
			"b-e\n"
			"b-f\n"
			"c-f\n"
			"e-d\n"
			"f-d\n"
			"a-d\n";
	t_room	*rooms;

//	input = read_from_stdin();
	input = ft_strsplit(str, '\n');
	rooms = parse_input(input);
	if (!rooms)
		return (3);
	if (valid_struct(rooms))
		lem_in(rooms);
//		solution(rooms)
//	i = -1;
//	while (input[++i])
//		ft_printf("|%s|\n", input[i]);
	while (1);
	return (0);
}
