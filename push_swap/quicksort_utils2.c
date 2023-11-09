/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyild <mehmyild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:06:27 by mehmyild          #+#    #+#             */
/*   Updated: 2023/10/27 02:21:34 by mehmyild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	ft_push(t_lst **a, t_lst **b, int len, int operation)
{
	if (operation == 0)
		pb(b, a, 1);
	else
		pa(a, b, 1);
	len--;
	return (len);
}

static void	ft_sort_three2(t_stack *stack)
{
	if ((stack->a)->nbr < (stack->a)->n->nbr
		&& (stack->a)->nbr < (stack->a)->n->n->nbr
		&& (stack->a)->n->nbr > (stack->a)->n->n->nbr)
	{
		sa(&stack->a, 1);
		ra(&stack->a, 1);
	}
	if ((stack->a)->nbr < (stack->a)->n->nbr
		&& (stack->a)->nbr > (stack->a)->n->n->nbr
		&& (stack->a)->n->nbr > (stack->a)->n->n->nbr)
		rra(&stack->a, 1);
}

void	ft_sort_three(t_stack *stack)
{
	if ((stack->a)->nbr > (stack->a)->n->nbr
		&& (stack->a)->nbr < (stack->a)->n->n->nbr
		&& (stack->a)->n->nbr < (stack->a)->n->n->nbr)
		sa(&stack->a, 1);
	if ((stack->a)->nbr > (stack->a)->n->nbr
		&& (stack->a)->nbr > (stack->a)->n->n->nbr
		&& (stack->a)->n->nbr > (stack->a)->n->n->nbr)
	{
		sa(&stack->a, 1);
		rra(&stack->a, 1);
	}
	if ((stack->a)->nbr > (stack->a)->n->nbr
		&& (stack->a)->nbr > (stack->a)->n->n->nbr
		&& (stack->a)->n->nbr < (stack->a)->n->n->nbr)
		ra(&stack->a, 1);
	ft_sort_three2(stack);
}

void	ft_sort_int_tmp(int *tmp_stack, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tmp_stack[i] > tmp_stack[j])
			{
				tmp = tmp_stack[i];
				tmp_stack[i] = tmp_stack[j];
				tmp_stack[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	ft_get_middle(int *pivot, t_lst *list, int size)
{
	int	i;
	int	*tmp;

	tmp = (int *)malloc(sizeof(int) * size);
	if (!tmp)
		return (0);
	i = 0;
	while (i < size)
	{
		tmp[i] = list->nbr;
		list = list->n;
		i++;
	}
	ft_sort_int_tmp(tmp, size);
	*pivot = tmp[size / 2];
	free(tmp);
	return (1);
}
