/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyild <mehmyild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:59:45 by mehmyild          #+#    #+#             */
/*   Updated: 2023/10/27 01:17:28 by mehmyild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

typedef struct s_lst
{
	long			nbr;
	struct s_lst	*n;
}			t_lst;

typedef struct s_stack
{
	char	**data;
	t_lst	*a;
	t_lst	*b;
	int		split_count;
	int		str_count;
}			t_stack;

char	**add_to_list(int ac, char **av, t_stack *stack);
char	*get_next_line(int fd);
void	ft_error(t_stack *stack, size_t flag);
void	push_swap(t_stack *stack);
void	lstpush(t_lst **list, int number);
void	lstclear(t_lst **lst);
int		ft_atol(t_stack *stack, const char *str, int sign, long res);
int		ft_duplicate(t_lst *stack, int nbr);
int		isnumeric(char *str);
int		stacksize(t_lst *a);

// Operators
int		ft_quicksort_a(t_stack *stack, int len, int count);
int		ft_quicksort_b(t_stack *stack, int len, int count);
int		ft_push(t_lst **a, t_lst **b, int len, int operation);
int		ft_get_middle(int *pivot, t_lst *list, int size);
int		ft_sort_small_b(t_stack *stack, int len);
int		is_sorted(t_lst *list, char c, int len);
int		ft_sort(t_stack *stack, int size);
void	ft_sort_int_tmp(int *tmp_stack, int size);
void	ft_quicksort_3a(t_stack *stack, int len);
void	ft_sort_three(t_stack *stack);
void	pa(t_lst **a, t_lst **b, int print);
void	pb(t_lst **b, t_lst **a, int print);
void	rr(t_lst **a, t_lst **b, int print);
void	rrr(t_lst **a, t_lst **b, int print);
void	rotate(t_lst **stack);
void	ra(t_lst **a, int print);
void	rb(t_lst **b, int print);
void	reverse_rotate(t_lst **stack);
void	rra(t_lst **a, int print);
void	rrb(t_lst **b, int print);
void	swap(t_lst **stack);
void	sa(t_lst **a, int print);
void	sb(t_lst **b, int print);
void	ss(t_lst **a, t_lst **b, int print);

#endif
