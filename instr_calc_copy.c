/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_calc_copy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchowdhu <hchowdhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:49:47 by hchowdhu          #+#    #+#             */
/*   Updated: 2025/03/04 14:08:34 by hchowdhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

int	count_total_moves(int min, int len, int size)
{
	int	i;

	if (min > (size / 2))
		min = min - size;
	if (len > (size / 2))
		len = len - size;
	i = min_number_in_stack(len, min);
	return (i);
}

int	count_moves_in_stack_b(int len, int size)
{
	if (len > (size / 2))
		len = len - size;
	return (len);
}

int	count_moves_in_stack_a(t_list *stack_a, int nb, int size)
{
	t_list	*tmp;
	int		i;

	tmp = stack_a;
	i = get_max_or_min_value(stack_a, nb, size);
	if (i != size + 1)
		return (count_moves_in_stack_b(i, size));
	while (tmp->next != NULL)
		tmp = tmp->next;
	if (nb < stack_a->number && nb > tmp->number)
		return (0);
	i = 1;
	while (!(nb > stack_a->number && nb < (stack_a->next)->number))
	{
		stack_a = stack_a->next;
		i++;
	}
	return (count_moves_in_stack_b(i, size));
}

int	*copy_stack_number_values(t_list *stack_a, int size)
{
	int	*arr;
	int	i;

	i = 0;
	arr = (int *) malloc (sizeof(int) * size + 1);
	if (!arr)
		write_error();
	while (stack_a != NULL)
	{
		arr[i++] = (stack_a)->number;
		stack_a = (stack_a)->next;
	}
	return (arr);
}

int	*copy_integer_arr_ay(int	*arr, int size)
{
	int	i;
	int	*copy;

	i = 0;
	copy = (int *) malloc (sizeof(int) * size);
	if (!arr || !copy)
		write_error();
	while (i < size)
	{
		copy[i] = arr[i];
		i++;
	}
	return (copy);
}
