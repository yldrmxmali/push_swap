/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyild <mehmyild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:01:47 by mehmyild          #+#    #+#             */
/*   Updated: 2023/10/27 02:21:08 by mehmyild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	lstpush(t_lst **list, int number)
{
	t_lst	*new;

	new = (t_lst *)malloc(sizeof(t_lst));
	if (!list || !new)
		return ;
	new->nbr = number;
	new -> n = *list;
	*list = new;
}

int	stacksize(t_lst *a)
{
	int	i;

	if (!a)
		return (0);
	i = 0;
	while (a->n != NULL)
	{
		a = a->n;
		i++;
	}
	return (i + 1);
}

void	lstclear(t_lst **lst)
{
	t_lst	*nbrs;

	if (!lst)
		return ;
	while (*lst)
	{
		nbrs = (*lst);
		*lst = (*lst)->n;
		free(nbrs);
	}
}
