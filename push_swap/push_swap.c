/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyild <mehmyild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 22:05:34 by mehmyild          #+#    #+#             */
/*   Updated: 2023/10/27 02:20:17 by mehmyild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

void	push_swap(t_stack *stack)
{
	int	i;
	int	num;

	i = -1;
	while (++i < stack->str_count)
	{
		if (isnumeric(stack->data[i]))
		{
			if (stack->split_count)
				ft_no_malloc(stack->data, 0);
			return (write(2, "Error\n", 6), exit(1));
		}
	}
	while (--i > -1)
	{
		num = ft_atol(stack, stack->data[i], 1, 0);
		if (ft_duplicate(stack->a, num))
			return (write(2, "Error\n", 6), ft_error(stack, 1));
		lstpush(&stack->a, num);
	}
	if (stack->str_count)
		ft_sort(stack, stack->str_count);
}

char	**add_to_list(int ac, char **av, t_stack *stack)
{
	char	**list;

	if (ac == 2)
	{
		list = ft_split(av[1], ' ');
		stack->split_count = 1;
		stack->str_count = ft_strcount(av[1], 32);
	}
	else
	{
		list = av + 1;
		stack->str_count = ac - 1;
	}
	return (list);
}

int	main(int ac, char **av)
{
	t_stack	stack;

	stack.a = NULL;
	stack.b = NULL;
	stack.split_count = 0;
	if (ac < 2)
		return (0);
	else if (ac >= 2)
	{
		stack.data = add_to_list(ac, av, &stack);
		if (!stack.data)
			return (write(2, "Error\n", 6), 1);
	}
	return (push_swap(&stack), ft_error(&stack, 0), 0);
}
