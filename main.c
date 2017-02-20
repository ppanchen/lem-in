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

	input = read_from_stdin();
	if (!validation(input))
		return (ft_printf("ERROR"));
	i = -1;
	while (input[++i])
		ft_printf("|%s|\n", input[i]);
	return (0);
}
