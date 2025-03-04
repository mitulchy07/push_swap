/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructionSort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: hchowdhu <hchowdhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2025/01/29 19:50:21 by hchowdhu          #+#    #+#             */
/*   updated: 2025/02/27 20:20:08 by hchowdhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

void	sortThree(t_list **stackA)
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
		tmp = *stackA;
		i = tmp->number;
		tmp = tmp->next;
		j = tmp->number;
		tmp = tmp->next;
		x = tmp->number;
		if ((i > j && j < x && x > i)
			|| (i > j && j > x && x < i) || (i < j && j > x && x > i))
			swapA(stackA);
		if (i > j && j < x && x < i)
			rotateA(stackA);
		if (i < j && j > x && x < i)
			reverseRotateA(stackA);
	}
}

void	sortFive(t_list **stackA, t_list **stackB)
{
	int	i;

	i = 2;
	while (i-- > 0)
		pushB(stackA, stackB);
	sortThree(stackA);
	moveToA(stackA, stackB);
	searchMin(stackA, ft_lstsize(*stackA));
}

void	moveToA(t_list **stackA, t_list **stackB)
{
	int	bestPos;
	int	sizeA;
	int	sizeB;

	sizeA = ft_lstsize(*stackA);
	sizeB = ft_lstsize(*stackB);
	while (*stackB != NULL)
	{
		bestPos = findBestPositionB(stackB, sizeB, stackA, sizeA);
		if (bestPos < 0)
		{
			while (bestPos++ < 0)
				reverseRotateB(stackB);
		}
		else if (bestPos > 0)
		{
			while (bestPos-- > 0)
				rotateB(stackB);
		}
		pushA(stackB, stackA);
		sizeA++;
		sizeB--;
	}
}

void	moveToB(t_list **stackA, t_list **stackB, int *arr, int len)
{
	int	i;
	int	sizeA;

	sizeA = ft_lstsize(*stackA);
	i = moveRemainingNumbers(*stackA, sizeA, arr, len);
	while (i != -1)
	{
		if (i > 0)
		{
			while (i > 0)
			{
				rotateA(stackA);
				i--;
			}
		}
		pushB(stackA, stackB);
		i = moveRemainingNumbers(*stackA, --sizeA, arr, len);
	}
}

int	pushSwapStrlen(char *str)
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
