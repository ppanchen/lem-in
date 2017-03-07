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

typedef struct		s_room
{
	char			*name;
	int 			num;
	int 			ants;
	char			*neighbors;
	int				role;
	int 			x;
	int 			y;
	int 			status;
	struct s_room	*next;
}					t_room;

typedef struct 		s_coord
{
	int 			i;
	int 			j;
	int 			d;
	int 			**map;
}					t_c;

typedef struct 		s_path
{
	char 			*name;
	int 			ants;
	int 			len;
	int 			*ants_name;
}					t_path;

/*
** role:	0 - none;
**			1 - start;
**			2 - end;
*/

char 	**read_from_stdin(void);
t_room	*parse_input(char	**cpy);
t_room	*find_name(t_room *start, char *name);
t_room	*find_role(t_room *start, int role);
t_room	*find_num(t_room *start, int num);
int 	valid_struct(t_room	*room);
int 	free_struct(t_room **start);
int 	**creat_map(t_room	*room);
int 	**paste_neighbors(t_room *room, int **map);
int 	lem_in(t_room *room);
char	*add_paths(int **map, t_room *room, char *str, t_c c);
void	checkroom(t_room *room, char *tmp, char **path);
void	paste_map(t_room *room, int **map);
void	move_ants(t_room *room, char **path);
void	sort_choose(char **paths);
int 	count_items(char **room);
int 	find_shortest(t_path **path);
void	start_end(t_room *next, t_path *path);
void	print_step(t_room *current, t_room *next, t_room *start);
int		find_free_ant(t_path *path);
void	fill_next_ant(t_room *next, t_room *current,\
							t_room *room, t_path *path);


#endif

