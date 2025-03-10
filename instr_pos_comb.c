/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_pos_comb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchowdhu <hchowdhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:49:47 by hchowdhu          #+#    #+#             */
/*   Updated: 2025/03/04 14:08:34 by hchowdhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

int	move_remaining_numbers_to_b(t_list *stack_a, int size, int *arr, int len)
{
	int	pos;
	int	i;

	pos = 0;
	i = 0;
	while (stack_a != NULL)
	{
		i = 0;
		while (stack_a->number != arr[i] && i < len)
		{
			if (i == len - 1)
				return (pos);
			i++;
		}
		stack_a = stack_a->next;
		pos++;
	}
	size = -1;
	return (size);
}

int	helper_find_best_combination(int *arr_a, int *arr_b, int *tmp, int size)
{
	int	i;
	int	pos;

	pos = 0;
	i = -1;
	while (++i < size)
	{
		if (tmp[i] < tmp[pos])
			pos = i;
	}
	free(arr_a);
	free(arr_b);
	free(tmp);
	return (pos);
}

int	find_best_combination_of_moves(int *arr_a, int *arr_b, int size)
{
	int	*tmp;
	int	i;

	i = -1;
	tmp = (int *) malloc (sizeof(int) * size);
	if (!tmp || !arr_a || !arr_b)
		write_error();
	while (++i < size)
	{
		if ((arr_a[i] > 0 && arr_b[i] > 0)
			|| (arr_a[i] < 0 && arr_b[i] < 0))
			tmp[i] = max_number_in_stack(arr_a[i], arr_b[i]);
		else
		{
			if (arr_a[i] < 0)
				arr_a[i] *= -1;
			if (arr_b[i] < 0)
				arr_b[i] *= -1;
			tmp[i] = arr_a[i] + arr_b[i];
		}
	}
	return (helper_find_best_combination(arr_a, arr_b, tmp, size));
}

int	push_minimum_to_top(int a, int b, t_list **stack_a, t_list **stack_b)
{
	while (a < 0 && b < 0)
	{
		reverse_rotate_both_stacks(stack_a, stack_b);
		a++;
		b++;
	}
	while (a > 0 && b > 0)
	{
		rotate_both_stacks(stack_a, stack_b);
		a--;
		b--;
	}
	if (a < 0)
		while (a++ < 0)
			reverse_rotate_stack_a(stack_a);
	else if (a > 0)
		while (a-- > 0)
			rotate_stack_a(stack_a);
	return (b);
}

int	find_best_position_b(t_list **stack_b, int size_b,
	t_list **stack_a, int size_a)
{
	int		*arr_b;
	int		*arr_a;
	t_list	*tmp_b;
	int		i;

	i = -1;
	tmp_b = *stack_b;
	arr_a = (int *) malloc (sizeof(int) * size_b);
	arr_b = (int *) malloc (sizeof(int) * size_b);
	if (!arr_b || !arr_a)
		write_error();
	while (++i < size_b)
		arr_b[i] = count_moves_in_stack_b(i, size_b);
	i = -1;
	while (++i < size_b && tmp_b != NULL)
	{
		arr_a[i] = count_moves_in_stack_a(*stack_a, tmp_b->number, size_a);
		tmp_b = tmp_b->next;
	}
	i = find_best_combination_of_moves(copy_integer_arr_ay(arr_a, size_b),
			copy_integer_arr_ay(arr_b, size_b), size_b);
	i = push_minimum_to_top(arr_a[i], arr_b[i], stack_a, stack_b);
	free(arr_a);
	free(arr_b);
	return (i);
}
