/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchowdhu <hchowdhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:35:01 by hchowdhu          #+#    #+#             */
/*   Updated: 2025/02/27 20:20:08 by hchowdhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (*lst != NULL)
	{
		tmp = ft_lstlast(*lst);
		tmp->next = new;
	}
	else
		(*lst) = new;
}
/*
int	main()
{
	t_list	*node;
	
	node = ft_lstnew("Hello");
	node->next = ft_lstnew(" I ");
	node->next->next = ft_lstnew("am a ");
	node->next->next->next = ft_lstnew("list");
	node->next->next->next->next = NULL;

	ft_lstadd_back(&node, ft_lstnew(" back"));
	while(node)
	{
		printf("%s", (char *)node->content);
		node = node->next;
	}
}
*/