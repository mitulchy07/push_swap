/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructionCalculateNCopy.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: hchowdhu <hchowdhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2025/01/29 19:49:24 by hchowdhu          #+#    #+#             */
/*   updated: 2025/02/27 20:20:08 by hchowdhu         ###   ########.fr       */
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

int	count_moves_in_stack_a(t_list *stackA, int nb, int size)
{
	t_list	*tmp;
	int		i;

	tmp = stackA;
	i = get_max_or_min_value(stackA, nb, size);
	if (i != size + 1)
		return (count_moves_in_stack_b(i, size));
	while (tmp->next != NULL)
		tmp = tmp->next;
	if (nb < stackA->number && nb > tmp->number)
		return (0);
	i = 1;
	while (!(nb > stackA->number && nb < (stackA->next)->number))
	{
		stackA = stackA->next;
		i++;
	}
	return (count_moves_in_stack_b(i, size));
}

int	*copy_stack_number_values(t_list *stackA, int size)
{
	int	*arr;
	int	i;

	i = 0;
	arr = (int *) malloc (sizeof(int) * size + 1);
	if (!arr)
		write_error();
	while (stackA != NULL)
	{
		arr[i++] = (stackA)->number;
		stackA = (stackA)->next;
	}
	return (arr);
}

int	*copy_integer_array(int	*arr, int size)
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
