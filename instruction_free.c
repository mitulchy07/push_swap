/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchowdhu <hchowdhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:54:32 by hchowdhu          #+#    #+#             */
/*   Updated: 2025/03/02 22:05:08 by hchowdhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

void	free_atoi(t_list **stack, char **argv, int size)
{
	if (size == 2)
	{
		free_tab(argv);
		write_error();
	}
	else
	{
		delete_list(stack);
		write_error();
	}
}

int	ft_atoi(const char *str, t_list **stack, char **argv, int size)
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
			free_atoi(stack, argv, size);
		number = (str[i] - '0') + (number * 10);
		i++;
	}
	if ((number > 2147483648 && sign == -1)
		|| (number > 2147483647 && sign == 1))
		free_atoi(stack, argv, size);
	return (number * sign);
}

void	check_error_arg(char **av)
{
	int	i;

	i = 0;
	if (!av[0])
	{
		free_tab(av);
		exit(0);
	}
	while (av[i] && av)
	{
		if (is_numeric(av[i]))
		{
			free_tab(av);
			write_error();
		}
		i++;
	}
}

void	free_tab(char **tab)
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

void	delete_list(t_list **stack)
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
