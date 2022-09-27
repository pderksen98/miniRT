/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pderksen <pderksen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:23:43 by pderksen      #+#    #+#                 */
/*   Updated: 2021/10/28 13:50:13 by pderksen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

void	free_function(char **arr, int row)
{
	while (row > 0)
	{
		free (arr[row]);
		row--;
	}
	free (arr);
}

int	word_length(const char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] != c && s[len] != 0)
		len++;
	return (len);
}

int	word_counter(const char *s, char c)
{
	unsigned int	i;
	unsigned int	count;

	count = 0;
	i = 0;
	if (*s == 0)
		return (0);
	if (s[i] != c)
		count++;
	while (s[i] != 0)
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}

char	**ft_split2(char **arr, int words, const char *s, char c)
{
	int	i;
	int	j;
	int	length;

	i = 0;
	while (i < words)
	{
		while (*s == c)
			s++;
		length = word_length(s, c);
		arr[i] = ft_substr(s, 0, length);
		if (!arr[i])
			free_function(arr, i);
		j = 0;
		while (j < length && *s)
		{
			s++;
			j++;
		}
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_split(const char *s, char c)
{
	char	**arr;
	int		words;

	if (!s)
		return (NULL);
	words = word_counter(s, c);
	arr = (char **)ft_calloc(sizeof(char *), (words + 1));
	if (!arr)
		return (NULL);
	return (ft_split2(arr, words, s, c));
}
