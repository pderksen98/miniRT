/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pderksen <pderksen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:24:36 by pderksen      #+#    #+#                 */
/*   Updated: 2021/10/28 12:24:37 by pderksen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_second_substr(const char *s, char *sub_s, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && s[i])
	{
		sub_s[i] = s[i];
		i++;
	}
	sub_s[i] = '\0';
	return (sub_s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	i;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (size < start)
		return (ft_strdup(""));
	if (len > size - start)
		return (ft_strdup(s + start));
	sub_s = ft_calloc((len + 1), sizeof(char));
	if (!sub_s)
		return (NULL);
	i = 0;
	while (s[i] && start > i)
		i++;
	s += i;
	return (ft_second_substr(s, sub_s, len));
}
