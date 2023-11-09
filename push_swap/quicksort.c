/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyild <mehmyild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:34:59 by mehmyild          #+#    #+#             */
/*   Updated: 2023/10/27 17:55:30 by mehmyild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort(t_stack *stack, int size)
{
	if (is_sorted(stack->a, 'a', size) == 0)
	{
		if (size == 2)
			sa(&stack->a, 1);
		else if (size == 3)
			ft_sort_three(stack);
		else
			ft_quicksort_a(stack, stack->str_count, 0);
	}
	return (0);
}

int	is_sorted(t_lst *list, char c, int len)
{
	if (list == (void *)0)
		return (0);
	while (c == 'a' && --len)
	{
		if (list->nbr > list->n->nbr)
			return (0);
		list = list->n;
	}
	while (c == 'b' && --len)
	{
		if (list->nbr < list->n->nbr)
			return (0);
		list = list->n;
	}
	return (1);
}

void	ft_quicksort_3a(t_stack *stack, int len)
{
	if (len == 3 && stacksize(stack->a) == 3)
		ft_sort_three(stack);
	else if (len == 2)
	{
		if (stack->a->nbr > stack->a->n->nbr)
			sa(&stack->a, 1);
	}
	else if (len == 3)
	{
		while (len != 3 || !(stack->a->nbr < stack->a->n->nbr
				&& stack->a->n->nbr < stack->a->n->n->nbr))
		{
			if (len == 3 && stack->a->nbr > stack->a->n->nbr
				&& stack->a->n->n->nbr)
				sa(&stack->a, 1);
			else if (len == 3 && !(stack->a->n->n->nbr > stack->a->nbr
					&& stack->a->n->n->nbr > stack->a->n->nbr))
				len = ft_push(&stack->a, &stack->b, len, 0);
			else if (stack->a->nbr > stack->a->n->nbr)
				sa(&stack->a, 1);
			else if (len++)
				pa(&stack->a, &stack->b, 1);
		}
	}
}

int	ft_quicksort_a(t_stack *stack, int len, int count)
{
	int	pivot;
	int	items;

	if (is_sorted(stack->a, 'a', len) == 1)
		return (1);
	items = len;
	if (len <= 3)
	{
		ft_quicksort_3a(stack, len);
		return (1);
	}
	if (!ft_get_middle(&pivot, stack->a, len))
		return (0);
	while (len != items / 2 + items % 2)
	{
		if (stack->a->nbr < pivot && (len--))
			pb(&stack->b, &stack->a, 1);
		else if (++count)
			ra(&stack->a, 1);
	}
	while (items / 2 + items % 2 != stacksize(stack->a) && count--)
		rra(&stack->a, 1);
	return (ft_quicksort_a(stack, items / 2 + items % 2, 0)
		&& ft_quicksort_b(stack, items / 2, 0));
	return (1);
}

int	ft_quicksort_b(t_stack *stack, int len, int count)
{
	int	pivot;
	int	items;

	if (!count && is_sorted(stack->b, 'b', len) == 1)
		while (len--)
			pa(&stack->a, &stack->b, 1);
	if (len <= 3)
	{
		ft_sort_small_b(stack, len);
		return (1);
	}
	items = len;
	if (!ft_get_middle(&pivot, stack->b, len))
		return (0);
	while (len != items / 2)
	{
		if (stack->b->nbr >= pivot && (len--))
			pa(&stack->a, &stack->b, 1);
		else if (++count)
			rb(&stack->b, 1);
	}
	while (items / 2 != stacksize(stack->b) && count--)
		rrb(&stack->b, 1);
	return (ft_quicksort_a(stack, items / 2 + items % 2, 0)
		&& ft_quicksort_b(stack, items / 2, 0));
}
