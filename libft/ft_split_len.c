/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split_len.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pderksen <pderksen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/25 10:19:12 by pderksen      #+#    #+#                 */
/*   Updated: 2022/01/25 10:48:48 by pderksen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_split_len(char **line_2d)
{
	size_t	i;

	i = 0;
	while (line_2d[i])
		i++;
	return (i);
}

void	ft_split_free(char **line_2d)
{
	size_t	i;

	i = 0;
	while (line_2d[i])
	{
		free(line_2d[i]);
		i++;
	}
	free(line_2d);
}
