/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchowdhu <hchowdhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 20:02:07 by hchowdhu          #+#    #+#             */
/*   Updated: 2025/02/27 20:02:11 by hchowdhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}
/*
int	main()
{
	size_t	i = 0;
	size_t	n = 3;
	char	str[] = "hello";
	char    str1[] = "hello";
	ft_bzero(str, n);
	while(i < 4)
	{
		printf("%c\n", str[i]);
		i++;
	}
	i = 0;
	bzero(str1, n);
	while ( i < 4)
	{
		printf("%c", str1[i]);
		i++;
	}
	return (0);
}
*/
