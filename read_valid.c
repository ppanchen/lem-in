/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 16:53:28 by ppanchen          #+#    #+#             */
/*   Updated: 2017/02/20 16:53:29 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char 	**read_from_stdin(void)
{
	char	*ret;
	char 	*str;
	char 	**arr;

	str = ft_strdup("");
	while (get_next_line(0, &ret) > 0)
	{
		if (ft_strcmp(ret, "") == 0)
		{
			ft_strdel(&str);
			str = ret;
			break;
		}
		if (ret[0] == '#' && ft_strcmp(ret, "##start") &&
				ft_strcmp(ret, "##end"))
			continue ;
		if (ret[0] == '#')
			str = ft_strjoin_free(&str, &ret);
		else
		{
			str = ft_strjoin_free(&str, &ret);
			ret = ft_strdup("\n");
			str = ft_strjoin_free(&str, &ret);
		}
	}
	arr = ft_strsplit(str, '\n');
	ft_strdel(&str);
	return (arr);
}
