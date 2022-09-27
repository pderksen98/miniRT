/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check_malloc.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pderksen <pderksen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/25 10:07:49 by pderksen      #+#    #+#                 */
/*   Updated: 2022/01/25 10:22:20 by pderksen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

void	ft_check_malloc(void *ptr)
{
	if (!ptr)
		exit(1);
}
