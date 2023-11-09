/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyild <mehmyild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 00:23:09 by mehmyild          #+#    #+#             */
/*   Updated: 2023/10/26 00:02:58 by mehmyild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort_small_b(t_stack *stack, int len)
{
	if (len == 1)
		pa(&stack->a, &stack->b, 1);
	else if (len == 2)
	{
		if (stack->b->nbr < stack->b->n->nbr)
			sb(&stack->b, 1);
		while (len--)
			pa(&stack->a, &stack->b, 1);
	}
	else if (len == 3)
	{
		while (len || !(stack->a->nbr < stack->a->n->nbr
				&& stack->a->n->nbr < stack->a->n->n->nbr))
		{
			if (len == 1 && stack->a->nbr > stack->a->n->nbr)
				sa(&stack->a, 1);
			else if (len == 1 || (len >= 2 && stack->b->nbr > stack->b->n->nbr)
				|| (len == 3 && stack->b->nbr > stack->b->n->n->nbr))
				len = ft_push(&stack->a, &stack->b, len, 1);
			else
				sb(&stack->b, 1);
		}
	}
	return (0);
}
