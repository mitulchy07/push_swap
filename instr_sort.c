/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchowdhu <hchowdhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:49:47 by hchowdhu          #+#    #+#             */
/*   Updated: 2025/03/04 14:08:34 by hchowdhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

void	sort_three_elements(t_list **stack_a)
{
	int		i;
	int		j;
	int		x;
	t_list	*tmp;

	tmp = NULL;
	i = 0;
	j = 0;
	x = 0;
	while (!(i < j && j < x && x > i))
	{
		tmp = *stack_a;
		i = tmp->number;
		tmp = tmp->next;
		j = tmp->number;
		tmp = tmp->next;
		x = tmp->number;
		if ((i > j && j < x && x > i)
			|| (i > j && j > x && x < i) || (i < j && j > x && x > i))
			swap_stack_a(stack_a);
		if (i > j && j < x && x < i)
			rotate_stack_a(stack_a);
		if (i < j && j > x && x < i)
			reverse_rotate_stack_a(stack_a);
	}
}

void	sort_five_elements(t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = 2;
	while (i-- > 0)
		push_to_stack_b(stack_a, stack_b);
	sort_three_elements(stack_a);
	move_to_stack_a(stack_a, stack_b);
	find_minimum_in_stack(stack_a, ft_lstsize(*stack_a));
}

void	move_to_stack_a(t_list **stack_a, t_list **stack_b)
{
	int	best_pos;
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	while (*stack_b != NULL)
	{
		best_pos = find_best_position_b(stack_b, size_b, stack_a, size_a);
		if (best_pos < 0)
		{
			while (best_pos++ < 0)
				reverse_rotate_stack_b(stack_b);
		}
		else if (best_pos > 0)
		{
			while (best_pos-- > 0)
				rotate_stack_b(stack_b);
		}
		push_to_stack_a(stack_b, stack_a);
		size_a++;
		size_b--;
	}
}

void	move_to_stack_b(t_list **stack_a, t_list **stack_b, int *arr, int len)
{
	int	i;
	int	size_a;

	size_a = ft_lstsize(*stack_a);
	i = move_remaining_numbers_to_b(*stack_a, size_a, arr, len);
	while (i != -1)
	{
		if (i > 0)
		{
			while (i > 0)
			{
				rotate_stack_a(stack_a);
				i--;
			}
		}
		push_to_stack_b(stack_a, stack_b);
		i = move_remaining_numbers_to_b(*stack_a, --size_a, arr, len);
	}
}

int	push_swap_strlen(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '9')
			j++;
		i++;
	}
	return (j);
}
