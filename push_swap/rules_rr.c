/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyild <mehmyild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:45:46 by mehmyild          #+#    #+#             */
/*   Updated: 2023/10/27 12:50:38 by mehmyild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_lst **stack)
{
	t_lst	*second_last;
	t_lst	*last;

	if (!(*stack) || !(*stack)->n)
		return ;
	second_last = *stack;
	last = *stack;
	while (last->n != (void *)0)
	{
		second_last = last;
		last = last->n;
	}
	last->n = *stack;
	*stack = last;
	second_last->n = (void *)0;
}

void	rra(t_lst **a, int print)
{
	reverse_rotate(a);
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_lst **b, int print)
{
	reverse_rotate(b);
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_lst **a, t_lst **b, int print)
{
	rra(a, 0);
	rrb(b, 0);
	if (print)
		ft_printf("rrr\n");
}
