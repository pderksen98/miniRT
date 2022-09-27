/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pderksen <pderksen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:23:18 by pderksen      #+#    #+#                 */
/*   Updated: 2021/10/28 12:23:19 by pderksen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	int				i;

	i = 0;
	ptr1 = (unsigned char *)src;
	ptr2 = (unsigned char *)dst;
	if (dst == 0 && src == 0)
		return (0);
	while (n > 0)
	{
		ptr2[i] = ptr1[i];
		n--;
		i++;
	}
	return (dst);
}
