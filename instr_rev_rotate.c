/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructionRevRotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: hchowdhu <hchowdhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2025/01/29 19:47:25 by hchowdhu          #+#    #+#             */
/*   updated: 2025/02/27 20:20:08 by hchowdhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

void	reverse_rotate_stack_a(t_list **stackA)
{
	t_list	*last;
	t_list	*tmp;

	last = *stackA;
	tmp = *stackA;
	while (last->next != NULL)
	{
		tmp = last;
		last = last->next;
	}
	last->next = *stackA;
	*stackA = last;
	tmp->next = NULL;
	write(1, "rra\n", 4);
}

void	reverse_rotate_stack_b(t_list **stackB)
{
	t_list	*last;
	t_list	*tmp;

	last = *stackB;
	tmp = *stackB;
	while (last->next != NULL)
	{
		tmp = last;
		last = last->next;
	}
	last->next = *stackB;
	*stackB = last;
	tmp->next = NULL;
	write(1, "rrb\n", 4);
}

void	reverse_rotate_both_stacks(t_list **stackA, t_list **stackB)
{
	t_list	*last;
	t_list	*tmp;

	last = *stackA;
	tmp = *stackA;
	while (last->next != NULL)
	{
		tmp = last;
		last = last->next;
	}
	last->next = *stackA;
	*stackA = last;
	tmp->next = NULL;
	last = *stackB;
	tmp = *stackB;
	while (last->next != NULL)
	{
		tmp = last;
		last = last->next;
	}
	last->next = *stackB;
	*stackB = last;
	tmp->next = NULL;
	write(1, "rrr\n", 4);
	return ;
}
