/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchowdhu <hchowdhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:46:44 by hchowdhu          #+#    #+#             */
/*   Updated: 2025/02/27 20:20:08 by hchowdhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

void	check_delete_list(t_list **stack)
{
	t_list	*tmp;

	if (*stack == NULL)
		return ;
	tmp = *stack;
	while (*stack != NULL)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

int	check_dup(t_list *stack_a, int check)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->number == check)
		{
			return (-1);
		}
		stack_a = stack_a->next;
	}
	return (1);
}

int	ok_or_ko(t_list **stack_a)
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

int	check_list(t_list **stack_a, int argc, char **argv, int size)
{
	t_list	*new_node;
	int		error;
	int		j;
	int		i;

	error = 0;
	i = 1;
	if (size == 2)
		i--;
	new_node = NULL;
	while (i < argc)
	{
		j = check_len(argv[i]);
		if (j > 10)
			return (-1);
		new_node = ft_lstnew(check_atoi(argv[i], stack_a, argv, size), stack_a);
		ft_lstadd_back(stack_a, new_node);
		error = check_dup(*stack_a, new_node->number);
		if (error == -1)
			return (-1);
		i++;
	}
	ok_or_ko(stack_a);
	new_node = NULL;
	return (0);
}

void	check_error_args(char **av)
{
	int	i;

	i = 0;
	if (!av[0])
	{
		check_free_tab(av);
		write_error();
	}
	while (av[i] && av)
	{
		if (check_numeric(av[i]))
		{
			check_free_tab(av);
			write_error();
		}
		i++;
	}
}
