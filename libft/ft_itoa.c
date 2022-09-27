/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pderksen <pderksen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:23:06 by pderksen      #+#    #+#                 */
/*   Updated: 2021/10/28 12:23:07 by pderksen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

int	power_checker(int x)
{
	int	i;

	i = 10;
	if (x == 0)
		return (1);
	while (x > 1)
	{
		i = i * 10;
		x--;
	}
	return (i);
}

int	digit_counter(int n)
{
	int	count;

	count = 0;
	while (n > 9)
	{
		n = n / 10;
		count++;
	}
	count++;
	return (count);
}

char	*negative(int n, int i)
{
	int		count;
	char	*str;

	if (n == -2147483648)
	{
		return (ft_strdup("-2147483648"));
	}
	n = n * -1;
	count = digit_counter(n);
	count++;
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (str == NULL)
		return (NULL);
	str[i] = '-';
	i++;
	count = count - 2;
	while (count >= 0)
	{
		str[i] = ((n / power_checker(count)) % 10) + '0';
		i++;
		count--;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		count;

	i = 0;
	if (n < 0)
		return (negative(n, i));
	count = digit_counter(n);
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (str == NULL)
		return (NULL);
	count--;
	while (count >= 0)
	{
		str[i] = ((n / power_checker(count)) % 10) + '0';
		i++;
		count--;
	}
	str[i] = '\0';
	return (str);
}
