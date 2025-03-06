/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instrcutionPushSwap.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: hchowdhu <hchowdhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2025/01/29 19:47:18 by hchowdhu          #+#    #+#             */
/*   updated: 2025/02/27 20:20:08 by hchowdhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

void	swap_stack_a(t_list **stackA)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *stackA;
	tmp2 = tmp->next;
	*stackA = tmp2;
	tmp->next = tmp2->next;
	tmp2->next = tmp;
	write(1, "sa\n", 3);
	return ;
}

void	swap_stack_b(t_list **stackB)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *stackB;
	tmp2 = tmp->next;
	*stackB = tmp2;
	tmp->next = tmp2->next;
	tmp2->next = tmp;
	write(1, "sb\n", 3);
	return ;
}

void	swap_both_stacks(t_list **stackA, t_list **stackB)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *stackA;
	tmp2 = tmp->next;
	*stackA = tmp2;
	tmp->next = tmp2->next;
	tmp2->next = tmp;
	tmp = NULL;
	tmp2 = NULL;
	tmp = *stackB;
	tmp2 = tmp->next;
	*stackB = tmp2;
	tmp->next = tmp2->next;
	tmp2->next = tmp;
	write(1, "ss\n", 3);
	return ;
}

void	push_to_stack_a(t_list **stackB, t_list **stackA)
{
	t_list	*tmp;

	if (*stackB == NULL)
		return ;
	tmp = *stackB;
	*stackB = (*stackB)->next;
	tmp->next = *stackA;
	*stackA = tmp;
	write(1, "pa\n", 3);
	return ;
}

void	push_to_stack_b(t_list **stackA, t_list **stackB)
{
	t_list	*tmp;

	if (*stackA == NULL)
		return ;
	tmp = *stackA;
	*stackA = (*stackA)->next;
	tmp->next = *stackB;
	*stackB = tmp;
	write(1, "pb\n", 3);
	return ;
}
