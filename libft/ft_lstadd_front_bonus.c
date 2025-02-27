/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchowdhu <hchowdhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:30:48 by hchowdhu          #+#    #+#             */
/*   Updated: 2025/02/27 20:20:08 by hchowdhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
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

	ft_lstadd_front(&node, ft_lstnew("front "));
	while(node)
	{
		printf("%s", (char *)node->content);
		node = node->next;
	}
}*/