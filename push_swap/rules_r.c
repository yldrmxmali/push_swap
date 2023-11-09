/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyild <mehmyild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 22:27:59 by mehmyild          #+#    #+#             */
/*   Updated: 2023/10/27 12:51:36 by mehmyild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_lst **stack)
{
	t_lst	*first;
	t_lst	*last;

	if (!(*stack) || !(*stack)->n)
		return ;
	first = *stack;
	last = *stack;
	while (last->n != (void *) 0)
		last = last->n;
	*stack = (*stack)->n;
	last->n = first;
	first->n = (void *)0;
}

void	ra(t_lst **a, int print)
{
	if (stacksize(*a) > 1)
	{
		rotate(a);
		if (print)
			ft_printf("ra\n");
	}
}

void	rb(t_lst **b, int print)
{
	if (stacksize(*b) > 1)
	{
		rotate(b);
		if (print)
			ft_printf("rb\n");
	}
}

void	rr(t_lst **a, t_lst **b, int print)
{
	ra(a, 0);
	rb(b, 0);
	if (print)
		ft_printf("rr\n");
}
