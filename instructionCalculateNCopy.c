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

int	countMoves(int min, int len, int size)
{
	int	i;

	if (min > (size / 2))
		min = min - size;
	if (len > (size / 2))
		len = len - size;
	i = minNumber(len, min);
	return (i);
}

int	countMovesB(int len, int size)
{
	if (len > (size / 2))
		len = len - size;
	return (len);
}

int	countMovesA(t_list *stackA, int nb, int size)
{
	t_list	*tmp;
	int		i;

	tmp = stackA;
	i = maxOrMin(stackA, nb, size);
	if (i != size + 1)
		return (countMovesB(i, size));
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
	return (countMovesB(i, size));
}

int	*copyStackNumber(t_list *stackA, int size)
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

int	*copyIntArray(int	*arr, int size)
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
