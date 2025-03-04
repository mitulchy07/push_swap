/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchowdhu <hchowdhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:50:41 by hchowdhu          #+#    #+#             */
/*   Updated: 2025/02/27 20:20:08 by hchowdhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(int *))
{
	t_list	*tmp;

	tmp = lst;
	if (lst != NULL)
	{
		lst = tmp->next;
		del(&tmp->number);
		free(tmp);
	}
}
/*
void	del(void *number)
{
		free(number);
}

int	main()
{
	char *str = ft_strdup("Hello");
	char *str1 = ft_strdup(" I ");
	char *str2 = ft_strdup("am a ");
	char *str3 = ft_strdup("list");
	t_list	*node;
	t_list *tmp;
	
	node = ft_lstnew(str);
	node->next = ft_lstnew(str1);
	node->next->next = ft_lstnew(str2);
	node->next->next->next = ft_lstnew(str3);
	node->next->next->next->next = NULL;

	tmp = node->next;
	node->next = tmp ->next;
	ft_lstdelone(tmp, del);
	while(node)
	{
		printf("%s\n", (char *)node->number);
		tmp = node;
		node = node->next;
		free (tmp->number);
		free(tmp);
	}
}*/