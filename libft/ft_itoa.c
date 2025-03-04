/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchowdhu <hchowdhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:25:38 by hchowdhu          #+#    #+#             */
/*   Updated: 2025/03/04 21:07:25 by hchowdhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	slen(int n)
{
	size_t	size;

	if (n > 0)
		size = 0;
	else
		size = 1;
	while (n)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	long	num;
	size_t	len;
	char	*str;

	num = (long)n;
	len = slen(n);
	str = (char *)malloc (len + 1);
	if (!str)
		return (NULL);
	*(str + len--) = '\0';
	if (n < 0)
		num *= -1;
	while (num > 0)
	{
		*(str + len--) = num % 10 + '0';
		num /= 10;
	}
	if (str[1] == '\0' && len == 0)
		*(str + len) = '0';
	else if (str[1] != '\0' && len == 0)
		*(str + len) = '-';
	return (str);
}
