/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 18:29:18 by ppanchen          #+#    #+#             */
/*   Updated: 2017/03/07 18:29:20 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	start_end(t_room *next, t_path *path)
{
	int num;

	if (num = find_free_ant(path))
	{
		next->ants++;
		ft_printf("L%i-%s ", num, next->name);
	}
}

void	print_step(t_room *current, t_room *next, t_room *start)
{
	if (next->ants == 0)
		return ;
	if (current != start)
	{
		ft_printf("L%i-%s ", current->ants, next->name);
		(current->ants = 0);
	}
	else
		ft_printf("L%i-%s ", next->ants, next->name);
}

void	fill_next_ant(t_room *next, t_room *current,\
							t_room *room, t_path *path)
{
	t_room *end;
	t_room *start;

	start = find_role(room, 1);
	end = find_role(room, 2);
	if (next != end)
	{
		if (current == start)
			next->ants += find_free_ant(path);
		else
			next->ants += current->ants;
	}
	else
		next->ants += 1;
}
