/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_calculate_n_copy.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchowdhu <hchowdhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:49:24 by hchowdhu          #+#    #+#             */
/*   Updated: 2025/02/27 20:20:08 by hchowdhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

int	count_moves(int min, int len, int size)
{
	int	i;

	if (min > (size / 2))
		min = min - size;
	if (len > (size / 2))
		len = len - size;
	i = min_number(len, min);
	return (i);
}

int	count_moves_b(int len, int size)
{
	if (len > (size / 2))
		len = len - size;
	return (len);
}

int	count_moves_a(t_list *stack_a, int nb, int size)
{
	t_list	*tmp;
	int		i;

	tmp = stack_a;
	i = max_or_min(stack_a, nb, size);
	if (i != size + 1)
		return (count_moves_b(i, size));
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
	return (count_moves_b(i, size));
}

int	*copy_stack_number(t_list *stack_a, int size)
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

int	*copy_int_array(int	*arr, int size)
{
	int	i;
	int	*cpy;

	i = 0;
	cpy = (int *) malloc (sizeof(int) * size);
	if (!arr || !cpy)
		write_error();
	while (i < size)
	{
		cpy[i] = arr[i];
		i++;
	}
	return (cpy);
}
