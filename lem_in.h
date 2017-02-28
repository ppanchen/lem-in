/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 16:48:54 by ppanchen          #+#    #+#             */
/*   Updated: 2017/02/20 16:48:56 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
#include "libft/libft.h"

int 				g_ant;
typedef struct		s_room
{
	char			*name;
	char			*neighbors;
	int				role;
	int 			x;
	int 			y;
	int 			error;
	struct s_room	*next;
}					t_room;

/*
** role:	0 - none;
**			1 - start;
**			2 - end;
*/

char 	**read_from_stdin(void);
t_room	*parse_input(char	**cpy);
t_room	*find_item(t_room *start, char	*name);
int 	free_struct(t_room *start);
#endif

