/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_lis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchowdhu <hchowdhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:49:47 by hchowdhu          #+#    #+#             */
/*   Updated: 2025/03/04 14:08:34 by hchowdhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

void	update_lis_prev_val(int *lis, int *prev, int *stackNumbers, int size)
{
	int	i;
	int	j;

	i = 1;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (stackNumbers[i] > stackNumbers[j] && lis[i] < lis[j] + 1)
			{
				lis[i] = lis[j] + 1;
				prev[i] = j;
			}
			j++;
		}
		i++;
	}
}

int	find_max_length_of_lis(int *lis, int size, int *end_index)
{
	int	max_lis_length;
	int	i;

	max_lis_length = 0;
	*end_index = 0;
	i = 0;
	while (i < size)
	{
		if (lis[i] > max_lis_length)
		{
			max_lis_length = lis[i];
			*end_index = i;
		}
		i++;
	}
	free(lis);
	return (max_lis_length);
}

int	*construct_lis(int *stackNumbers, int *prev, int lisLength, int end_index)
{
	int	*result;
	int	i;

	result = (int *)malloc(lisLength * sizeof(int));
	if (!result)
		write_error();
	i = lisLength - 1;
	while (end_index >= 0)
	{
		result[i] = stackNumbers[end_index];
		end_index = prev[end_index];
		i--;
	}
	free(prev);
	return (result);
}

int	*find_lis_and_length(int *stackNumbers, int size, int *len)
{
	int	*lis;
	int	*prev;
	int	end_index;

	lis = (int *)malloc(size * sizeof(int));
	prev = (int *)malloc(size * sizeof(int));
	if (!lis || !prev)
		write_error();
	init_lis_prev_val(lis, prev, size);
	update_lis_prev_val(lis, prev, stackNumbers, size);
	*len = find_max_length_of_lis(lis, size, &end_index);
	return (construct_lis(stackNumbers, prev, *len, end_index));
}

int	*define_lis(int *stackNumbers, int size, int *len)
{
	return (find_lis_and_length(stackNumbers, size, len));
}
