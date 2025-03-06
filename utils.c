/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchowdhu <hchowdhu@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:50:36 by hchowdhu          #+#    #+#             */
/*   Updated: 2025/03/04 13:21:45 by hchowdhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

void	init_lis_prev_val(int *lis, int *prev, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		lis[i] = 1;
		prev[i] = -1;
		i++;
	}
}

int	check_for_duplicates(t_list *stackA, int value)
{
	while (stackA->next != NULL)
	{
		if (stackA->number == value)
		{
			return (-1);
		}
		stackA = stackA->next;
	}
	return (1);
}

void	check_if_inverted(t_list **stackA, int argc)
{
	t_list	*current;
	t_list	*next;

	current = *stackA;
	next = current->next;
	while (next != NULL)
	{
		if (current->number < next->number)
			return ;
		current = current->next;
		next = next->next;
	}
	if (argc > 1)
		swap_stack_a(stackA);
}

int	is_numeric_string(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (1);
	while (str[i] != '\0' && ft_isdigit(str[i]))
		i++;
	if (str[i] == '\0')
		return (0);
	return (1);
}

int	check_if_sorted(t_list **stackA)
{
	t_list	*current;
	t_list	*next;

	current = *stackA;
	next = current->next;
	while (next != NULL)
	{
		if (current->number > next->number)
		{
			return (-1);
		}
		current = current->next;
		next = next->next;
	}
	return (1);
}
