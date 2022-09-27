/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pderksen <pderksen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:24:31 by pderksen      #+#    #+#                 */
/*   Updated: 2021/10/28 12:24:32 by pderksen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		i;
	int		count;

	if (!s1)
		return (NULL);
	while (ft_strchr(set, *s1) != NULL && *s1)
		s1++;
	i = ft_strlen(s1);
	count = 0;
	while (ft_strchr(set, s1[i]) != NULL && *s1)
	{
		i--;
		count++;
	}
	ptr = ft_substr(s1, 0, ft_strlen(s1) - count + 1);
	if (!ptr)
		return (NULL);
	return (ptr);
}
