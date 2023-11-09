/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyild <mehmyild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 00:21:05 by mehmyild          #+#    #+#             */
/*   Updated: 2023/10/26 22:15:41 by mehmyild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_lst **stack)
{
	t_lst	*first;
	t_lst	*second;

	if (!(*stack) || !(*stack)->n)
		return ;
	first = *stack;
	second = (*stack)->n;
	first->n = second->n;
	second->n = first;
	*stack = second;
}

void	sa(t_lst **a, int print)
{
	if (stacksize(*a) > 1)
	{
		swap(a);
		if (print)
			ft_printf("sa\n");
	}
}

void	sb(t_lst **b, int print)
{
	if (stacksize(*b) > 1)
	{
		swap(b);
		if (print)
			ft_printf("sb\n");
	}
}

void	ss(t_lst **a, t_lst **b, int print)
{
	sa(a, 0);
	sb(b, 0);
	if (print)
		ft_printf("ss\n");
}
