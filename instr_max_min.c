/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_max_min.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchowdhu <hchowdhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:49:47 by hchowdhu          #+#    #+#             */
/*   Updated: 2025/03/04 14:08:34 by hchowdhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

int	return_max_or_min_value(int nb, int *max_n_min, int size)
{
	if (nb > max_n_min[0])
		return (max_n_min[2]);
	if (nb < max_n_min[1])
		return (max_n_min[3]);
	return (size + 1);
}

int	get_max_or_min_value(t_list *stack_a, int nb, int size)
{
	int	max_n_min[5];

	max_n_min[0] = stack_a->number;
	max_n_min[1] = stack_a->number;
	max_n_min[2] = 0;
	max_n_min[3] = 0;
	max_n_min[4] = 1;
	while (stack_a != NULL)
	{
		if (stack_a->number >= max_n_min[0])
		{
			max_n_min[0] = stack_a->number;
			max_n_min[2] = max_n_min[4];
		}
		if (stack_a->number < max_n_min[1])
		{
			max_n_min[1] = stack_a->number;
			max_n_min[3] = max_n_min[4] - 1;
		}
		stack_a = stack_a->next;
		max_n_min[4]++;
	}
	return (return_max_or_min_value(nb, max_n_min, size));
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

void	find_minimum_in_stack(t_list **stack_a, int size)
{
	int		pos;
	int		pos_min;
	int		min;
	t_list	*tmp;

	pos_min = 0;
	pos = 0;
	tmp = *stack_a;
	min = tmp->number;
	while (pos < size)
	{
		if (min > tmp->number)
		{
			min = tmp->number;
			pos_min = pos;
		}
		tmp = tmp->next;
		pos++;
	}
	tmp = NULL;
	pos = count_moves_in_stack_b(pos_min, size);
	push_minimum_to_top(pos, 0, stack_a, &tmp);
}
