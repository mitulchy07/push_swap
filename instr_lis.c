/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instrctionLIS.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: hchowdhu <hchowdhu@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2025/01/29 19:47:05 by hchowdhu          #+#    #+#             */
/*   updated: 2025/03/04 13:02:21 by hchowdhu            ###   ########.fr       */
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

int	find_max_length_of_lis(int *lis, int size, int *endIndex)
{
	int	maxLisLength;
	int	i;

	maxLisLength = 0;
	*endIndex = 0;
	i = 0;
	while (i < size)
	{
		if (lis[i] > maxLisLength)
		{
			maxLisLength = lis[i];
			*endIndex = i;
		}
		i++;
	}
	free(lis);
	return (maxLisLength);
}

int	*construct_lis(int *stackNumbers, int *prev, int lisLength, int endIndex)
{
	int	*result;
	int	i;

	result = (int *)malloc(lisLength * sizeof(int));
	if (!result)
		write_error();
	i = lisLength - 1;
	while (endIndex >= 0)
	{
		result[i] = stackNumbers[endIndex];
		endIndex = prev[endIndex];
		i--;
	}
	free(prev);
	return (result);
}

int	*find_lis_and_length(int *stackNumbers, int size, int *len)
{
	int	*lis;
	int	*prev;
	int	endIndex;

	lis = (int *)malloc(size * sizeof(int));
	prev = (int *)malloc(size * sizeof(int));
	if (!lis || !prev)
		write_error();
	init_lis_prev_val(lis, prev, size);
	update_lis_prev_val(lis, prev, stackNumbers, size);
	*len = find_max_length_of_lis(lis, size, &endIndex);
	return (construct_lis(stackNumbers, prev, *len, endIndex));
}

int	*define_lis(int *stackNumbers, int size, int *len)
{
	return (find_lis_and_length(stackNumbers, size, len));
}
