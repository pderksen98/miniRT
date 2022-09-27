/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup_c.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pderksen <pderksen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/25 09:59:08 by pderksen      #+#    #+#                 */
/*   Updated: 2022/02/17 12:35:17 by pderksen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strdup_c(char *line, char c)
{
	int		len;
	int		i;
	char	*newline;

	len = 0;
	while (line[len] != '\0' && line[len] != c)
		len++;
	newline = (char *)malloc(sizeof(char) * (len + 1));
	if (!newline)
		return (NULL);
	i = 0;
	while (i < len)
	{
		newline[i] = line[i];
		i++;
	}
	newline[i] = '\0';
	return (newline);
}
