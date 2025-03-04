/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchowdhu <hchowdhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:05:10 by hchowdhu          #+#    #+#             */
/*   Updated: 2025/02/27 20:20:08 by hchowdhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*cdest;
	unsigned char	*csrc;

	if (!src && !dest)
		return (NULL);
	cdest = (unsigned char *) dest;
	csrc = (unsigned char *) src;
	if (dest < src)
	{
		while (n--)
			*cdest++ = *csrc++;
	}
	else if (dest > src)
	{
		cdest = cdest + n - 1;
		csrc = csrc + n - 1;
		while (n--)
			*cdest-- = *csrc--;
	}
	return (dest);
}
