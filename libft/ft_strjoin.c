/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pderksen <pderksen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:23:59 by pderksen      #+#    #+#                 */
/*   Updated: 2021/12/07 15:50:57 by pderksen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

char	*mr_magic(char const *first, char const *second, char *result)
{
	size_t	count;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	count = 0;
	while (!(first[i] == 0 && second[j] == 0))
	{
		if (first[i] != 0)
		{
			result[count] = first[i];
			i++;
		}
		else if (second[j] != 0)
		{
			result[count] = second[j];
			j++;
		}
		count++;
	}
	result[count] = '\0';
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (s1 == 0 || s2 == 0)
		return (NULL);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	return (mr_magic(s1, s2, str));
}
