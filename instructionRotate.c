/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructionRotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: hchowdhu <hchowdhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2025/01/29 19:47:39 by hchowdhu          #+#    #+#             */
/*   updated: 2025/02/27 20:20:08 by hchowdhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

void	rotateA(t_list **stackA)
{
	t_list	*last;
	t_list	*first;

	if (*stackA == NULL || (*stackA)->next == NULL)
		return ;
	last = *stackA;
	first = *stackA;
	while (last->next != NULL)
		last = last->next;
	*stackA = first->next;
	first->next = NULL;
	last->next = first;
	write(1, "ra\n", 3);
	return ;
}

void	rotateB(t_list **stackB)
{
	t_list	*last;
	t_list	*first;

	if (*stackB == NULL || (*stackB)->next == NULL)
		return ;
	last = *stackB;
	first = *stackB;
	while (last->next != NULL)
		last = last->next;
	*stackB = first->next;
	first->next = NULL;
	last->next = first;
	write(1, "rb\n", 3);
	return ;
}

void	rotateBoth(t_list **stackA, t_list **stackB)
{
	t_list	*last;
	t_list	*first;

	if (*stackA == NULL || (*stackA)->next == NULL)
		return ;
	last = *stackA;
	first = *stackA;
	while (last->next != NULL)
		last = last->next;
	*stackA = first->next;
	first->next = NULL;
	last->next = first;
	if (*stackB == NULL || (*stackB)->next == NULL)
		return ;
	last = *stackB;
	first = *stackB;
	while (last->next != NULL)
		last = last->next;
	*stackB = first->next;
	first->next = NULL;
	last->next = first;
	write(1, "rr\n", 3);
	return ;
}
