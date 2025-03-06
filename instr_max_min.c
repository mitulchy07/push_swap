/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructionMaxnmin.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: hchowdhu <hchowdhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2025/01/29 19:49:13 by hchowdhu          #+#    #+#             */
/*   updated: 2025/02/27 20:20:08 by hchowdhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

int	return_max_or_min_value(int nb, int *maxNMin, int size)
{
	if (nb > maxNMin[0])
		return (maxNMin[2]);
	if (nb < maxNMin[1])
		return (maxNMin[3]);
	return (size + 1);
}

int	get_max_or_min_value(t_list *stackA, int nb, int size)
{
	int	maxNMin[5];

	maxNMin[0] = stackA->number;
	maxNMin[1] = stackA->number;
	maxNMin[2] = 0;
	maxNMin[3] = 0;
	maxNMin[4] = 1;
	while (stackA != NULL)
	{
		if (stackA->number >= maxNMin[0])
		{
			maxNMin[0] = stackA->number;
			maxNMin[2] = maxNMin[4];
		}
		if (stackA->number < maxNMin[1])
		{
			maxNMin[1] = stackA->number;
			maxNMin[3] = maxNMin[4] - 1;
		}
		stackA = stackA->next;
		maxNMin[4]++;
	}
	return (return_max_or_min_value(nb, maxNMin, size));
}

int	min_number_in_stack(int a, int b)
{
	int	a1;
	int	b1;

	a1 = a;
	b1 = b;
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	if (a == b)
		return (a1);
	if (a < b)
		return (a1);
	return (b1);
}

int	max_number_in_stack(int a, int b)
{
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	if (a > b)
		return (a);
	if (b > a)
		return (b);
	else
		return (a);
}

void	find_minimum_in_stack(t_list **stackA, int size)
{
	int		pos;
	int		posMin;
	int		min;
	t_list	*tmp;

	posMin = 0;
	pos = 0;
	tmp = *stackA;
	min = tmp->number;
	while (pos < size)
	{
		if (min > tmp->number)
		{
			min = tmp->number;
			posMin = pos;
		}
		tmp = tmp->next;
		pos++;
	}
	tmp = NULL;
	pos = count_moves_in_stack_b(posMin, size);
	push_minimum_to_top(pos, 0, stackA, &tmp);
}
