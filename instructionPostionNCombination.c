/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructionPostionNCombination.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: hchowdhu <hchowdhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2025/01/29 19:49:32 by hchowdhu          #+#    #+#             */
/*   updated: 2025/02/27 20:20:08 by hchowdhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

int	moveRemainingNumbers(t_list *stackA, int size, int *arr, int len)
{
	int	pos;
	int	i;

	pos = 0;
	i = 0;
	while (stackA != NULL)
	{
		i = 0;
		while (stackA->number != arr[i] && i < len)
		{
			if (i == len - 1)
				return (pos);
			i++;
		}
		stackA = stackA->next;
		pos++;
	}
	size = -1;
	return (size);
}

int	findBestCombinationHelper(int *arrA, int *arrB, int *tmp, int size)
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
	free(arrA);
	free(arrB);
	free(tmp);
	return (pos);
}

int	findBestCombination(int *arrA, int *arrB, int size)
{
	int	*tmp;
	int	i;

	i = -1;
	tmp = (int *) malloc (sizeof(int) * size);
	if (!tmp || !arrA || !arrB)
		write_error();
	while (++i < size)
	{
		if ((arrA[i] > 0 && arrB[i] > 0)
			|| (arrA[i] < 0 && arrB[i] < 0))
			tmp[i] = maxNumber(arrA[i], arrB[i]);
		else
		{
			if (arrA[i] < 0)
				arrA[i] *= -1;
			if (arrB[i] < 0)
				arrB[i] *= -1;
			tmp[i] = arrA[i] + arrB[i];
		}
	}
	return (findBestCombinationHelper(arrA, arrB, tmp, size));
}

int	pushMinToTop(int a, int b, t_list **stackA, t_list **stackB)
{
	while (a < 0 && b < 0)
	{
		reverseRotateBoth(stackA, stackB);
		a++;
		b++;
	}
	while (a > 0 && b > 0)
	{
		rotateBoth(stackA, stackB);
		a--;
		b--;
	}
	if (a < 0)
		while (a++ < 0)
			reverseRotateA(stackA);
	else if (a > 0)
		while (a-- > 0)
			rotateA(stackA);
	return (b);
}

int	findBestPositionB(t_list **stackB, int sizeB,
	t_list **stackA, int sizeA)
{
	int		*arrB;
	int		*arrA;
	t_list	*tmpB;
	int		i;

	i = -1;
	tmpB = *stackB;
	arrA = (int *) malloc (sizeof(int) * sizeB);
	arrB = (int *) malloc (sizeof(int) * sizeB);
	if (!arrB || !arrA)
		write_error();
	while (++i < sizeB)
		arrB[i] = countMovesB(i, sizeB);
	i = -1;
	while (++i < sizeB && tmpB != NULL)
	{
		arrA[i] = countMovesA(*stackA, tmpB->number, sizeA);
		tmpB = tmpB->next;
	}
	i = findBestCombination(copyIntArray(arrA, sizeB),
			copyIntArray(arrB, sizeB), sizeB);
	i = pushMinToTop(arrA[i], arrB[i], stackA, stackB);
	free(arrA);
	free(arrB);
	return (i);
}
