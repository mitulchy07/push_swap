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

void	sort_three_elements(t_list **stackA)
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
			swap_stack_a(stackA);
		if (i > j && j < x && x < i)
			rotate_stack_a(stackA);
		if (i < j && j > x && x < i)
			reverse_rotate_stack_a(stackA);
	}
}

void	sort_five_elements(t_list **stackA, t_list **stackB)
{
	int	i;

	i = 2;
	while (i-- > 0)
		push_to_stack_b(stackA, stackB);
	sort_three_elements(stackA);
	move_to_stack_a(stackA, stackB);
	find_minimum_in_stack(stackA, ft_lstsize(*stackA));
}

void	move_to_stack_a(t_list **stackA, t_list **stackB)
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
				reverse_rotate_stack_b(stackB);
		}
		else if (bestPos > 0)
		{
			while (bestPos-- > 0)
				rotate_stack_b(stackB);
		}
		push_to_stack_a(stackB, stackA);
		sizeA++;
		sizeB--;
	}
}

void	move_to_stack_b(t_list **stackA, t_list **stackB, int *arr, int len)
{
	int	i;
	int	sizeA;

	sizeA = ft_lstsize(*stackA);
	i = move_remaining_numbers_to_b(*stackA, sizeA, arr, len);
	while (i != -1)
	{
		if (i > 0)
		{
			while (i > 0)
			{
				rotate_stack_a(stackA);
				i--;
			}
		}
		push_to_stack_b(stackA, stackB);
		i = move_remaining_numbers_to_b(*stackA, --sizeA, arr, len);
	}
}

int	push_swap_strlen(char *str)
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
