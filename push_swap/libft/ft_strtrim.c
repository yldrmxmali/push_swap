/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyild <mehmyild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:24:42 by mehmyild          #+#    #+#             */
/*   Updated: 2023/10/27 02:52:17 by mehmyild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		index;
	char	*ret;

	start = 0;
	if (!s1 || !set)
		return ((void *)0);
	end = ft_strlen(s1);
	while (s1[start] != '\0' && ft_strchr(set, s1[start]))
		start++;
	if (start == end)
		return (ft_strdup(""));
	while (end > 0 && ft_strchr(set, s1[end - 1]))
		end--;
	ret = malloc(sizeof(char) * (end - start + 1));
	if (!ret)
		return ((void *)0);
	index = 0;
	while (start < end)
	{
		ret[index++] = s1[start++];
	}
	ret[index] = '\0';
	return (ret);
}
