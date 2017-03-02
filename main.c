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
			"##startqwerty 8 9\n"
			"##endger 7 5\n"
			"ger-qwerty\n"
			"qwerty-ger\n"
			"qwert-g";
	t_room	*rooms;

//	input = read_from_stdin();
	input = ft_strsplit(str, '\n');
	rooms = parse_input(input);
//	if (!rooms)
//		return (3);
	i = -1;
	while (input[++i])
		ft_printf("|%s|\n", input[i]);
	while (1);
	return (0);
}
