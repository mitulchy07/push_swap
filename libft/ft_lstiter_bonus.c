/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchowdhu <hchowdhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:11:30 by hchowdhu          #+#    #+#             */
/*   Updated: 2025/03/04 21:06:36 by hchowdhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(int *))
{
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		f(&lst->number);
		lst = lst->next;
	}
}

void	func(void *number)
{
	*(int *)number += 1;
}
