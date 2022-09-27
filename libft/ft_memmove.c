/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pderksen <pderksen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:23:21 by pderksen      #+#    #+#                 */
/*   Updated: 2021/10/28 12:23:22 by pderksen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)src;
	ptr2 = (unsigned char *)dst;
	if (dst == 0 && src == 0)
		return (0);
	else if (src > dst)
		return (ft_memcpy(dst, src, len));
	else
	{
		while (len)
		{
			ptr2[len - 1] = ptr1[len - 1];
			len--;
		}
	}
	return (dst);
}
