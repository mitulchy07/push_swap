/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchowdhu <hchowdhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:50:36 by hchowdhu          #+#    #+#             */
/*   Updated: 2025/02/27 20:20:08 by hchowdhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

void	initialize_lis_and_prev(int *lis, int *prev, int size)
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

int	check_duplicate(t_list *stack_a, int value)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->number == value)
		{
			return (-1);
		}
		stack_a = stack_a->next;
	}
	return (1);
}

void	check_inverted(t_list **stack_a, int argc)
{
	t_list	*current;
	t_list	*next;

	current = *stack_a;
	next = current->next;
	while (next != NULL)
	{
		if (current->number < next->number)
			return ;
		current = current->next;
		next = next->next;
	}
	if (argc > 1)
		swap_a(stack_a);
}

int	is_numeric(char *str)
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

int	check_sorted(t_list **stack_a)
{
	t_list	*current;
	t_list	*next;

	current = *stack_a;
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
