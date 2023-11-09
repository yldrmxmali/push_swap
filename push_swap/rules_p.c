/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyild <mehmyild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 22:27:01 by mehmyild          #+#    #+#             */
/*   Updated: 2023/10/19 20:56:04 by mehmyild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_lst **a, t_lst **b, int print)
{
	t_lst	*first_b;
	t_lst	*second_b;

	if (!*b)
		return ;
	first_b = *b;
	second_b = (*b)->n;
	*b = second_b;
	first_b->n = *a;
	*a = first_b;
	if (print)
		ft_printf("pa\n");
}

void	pb(t_lst **b, t_lst **a, int print)
{
	t_lst	*first_a;
	t_lst	*second_a;

	if (!*a)
		return ;
	first_a = *a;
	second_a = (*a)->n;
	*a = second_a;
	first_a->n = *b;
	*b = first_a;
	if (print)
		ft_printf("pb\n");
}
