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
			"frer 4 5\n"
			"##startfree 5 7\n"
			"##endend 6 4\n"
			"en 6 7\n"
			"en-end\n"
			"frer-end";
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
