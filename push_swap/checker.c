/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyild <mehmyild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 06:36:19 by mehmyild          #+#    #+#             */
/*   Updated: 2023/10/27 18:32:11 by mehmyild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		++i;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static int	first_part(t_stack *stack, char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		sa(&stack->a, 0);
	else if (!ft_strcmp(line, "sb\n"))
		sb(&stack->b, 0);
	else if (!ft_strcmp(line, "ss\n"))
		ss(&stack->a, &stack->b, 0);
	else if (!ft_strcmp(line, "pa\n"))
		pa(&stack->a, &stack->b, 0);
	else if (!ft_strcmp(line, "pb\n"))
		pb(&stack->b, &stack->a, 0);
	else if (!ft_strcmp(line, "ra\n"))
		ra(&stack->a, 0);
	else if (!ft_strcmp(line, "rb\n"))
		rb(&stack->b, 0);
	else if (!ft_strcmp(line, "rr\n"))
		rr(&stack->a, &stack->b, 0);
	else if (!ft_strcmp(line, "rra\n"))
		rra(&stack->a, 0);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb(&stack->b, 0);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(&stack->a, &stack->b, 0);
	else
		return (0);
	return (1);
}

static int	checker_control(t_stack *stack)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (first_part(stack, line))
			;
		else
		{
			write(2, "Error\n", 6);
			return (free(line), ft_error(stack, 1), 1);
		}
		free(line);
		line = get_next_line(0);
	}
	if (!is_sorted(stack->a, 'a', stack->str_count) || stacksize(stack->b))
		return (0);
	return (1);
}

static void	checker(t_stack *stack)
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
	if (checker_control(stack))
		return (ft_printf("OK\n"), ft_error(stack, 1));
	return (write(2, "KO\n", 3), ft_error(stack, 1));
}

int	main(int ac, char **av)
{
	t_stack	stack;

	stack.a = (void *)0;
	stack.b = (void *)0;
	stack.split_count = 0;
	if (ac == 1)
		return (0);
	if (ac == 2)
	{
		stack.data = ft_split(av[1], 32);
		if (!stack.data)
			return (write(2, "Error\n", 6), ft_error(&stack, 1), 1);
		stack.split_count = 1;
		stack.str_count = ft_strcount(av[1], 32);
		if (stack.str_count == 0)
			return (write(2, "Error\n", 6), ft_no_malloc(stack.data, 0), 0);
	}
	else
	{
		stack.data = av + 1;
		stack.str_count = ac - 1;
	}
	return (checker(&stack), 0);
}
