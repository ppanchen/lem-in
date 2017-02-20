/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 12:51:44 by ppanchen          #+#    #+#             */
/*   Updated: 2017/02/19 20:31:38 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		i;
	int		j;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	i = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	ret = (char *)malloc(i + 1);
	if (!ret)
		return (0);
	i = -1;
	while (s1[++i])
		ret[i] = s1[i];
	j = 0;
	while (s2[j])
	{
		ret[i] = s2[j];
		i++;
		j++;
	}
	ret[i] = 0;
	return (ret);
}

char	*ft_strjoin_free(char **s1, char **s2)
{
	char *str;

	str = ft_strjoin(*s1, *s2);
	ft_strdel(s1);
	ft_strdel(s2);
	return (str);
}
