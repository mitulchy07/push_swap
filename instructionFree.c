/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructionFree.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: hchowdhu <hchowdhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2025/02/14 21:54:32 by hchowdhu          #+#    #+#             */
/*   updated: 2025/03/02 22:05:08 by hchowdhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

void	freeAtoi(t_list **stack, char **argv, int size)
{
	if (size == 2)
	{
		freeTab(argv);
		write_error();
	}
	else
	{
		deleteList(stack);
		write_error();
	}
}

int	ftAtoi(const char *str, t_list **stack, char **argv, int size)
{
	unsigned int		i;
	int					sign;
	unsigned long int	number;

	i = 0;
	number = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			freeAtoi(stack, argv, size);
		number = (str[i] - '0') + (number * 10);
		i++;
	}
	if ((number > 2147483648 && sign == -1)
		|| (number > 2147483647 && sign == 1))
		freeAtoi(stack, argv, size);
	return (number * sign);
}

void	checkErrorArg(char **av)
{
	int	i;

	i = 0;
	if (!av[0])
	{
		freeTab(av);
		exit(0);
	}
	while (av[i] && av)
	{
		if (isNumeric(av[i]))
		{
			freeTab(av);
			write_error();
		}
		i++;
	}
}

void	freeTab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	deleteList(t_list **stack)
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
