/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyild <mehmyild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 23:30:00 by mehmyild          #+#    #+#             */
/*   Updated: 2023/10/27 02:20:44 by mehmyild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

int	isnumeric(char *str)
{
	if (*str == 43 || *str == 45)
		str++;
	if (!*str)
		return (1);
	while (*str)
		if (!('0' <= *str && *str++ <= '9'))
			return (1);
	return (0);
}

int	ft_duplicate(t_lst *stack, int nbr)
{
	if (!stack)
		return (0);
	if (stack->nbr == nbr)
		return (1);
	return (ft_duplicate(stack->n, nbr));
}

void	ft_error(t_stack *stack, size_t flag)
{
	if (stack->split_count)
		ft_no_malloc(stack->data, 0);
	lstclear(&stack->a);
	lstclear(&stack->b);
	if (flag == 1)
		exit (1);
}

int	ft_atol(t_stack *stack, const char *str, int sign, long res)
{
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	if (*str == 45)
		sign = -1;
	if (*str == 43 || *str == 45)
		str++;
	while (48 <= *str && *str <= 57)
		res = res * 10 + *str++ - 48;
	if (res * sign < -2147483648 || res * sign > 2147483647)
		return (write(2, "Error\n", 6), ft_error(stack, 1), 0);
	return (res * sign);
}
