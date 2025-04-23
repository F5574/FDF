/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvon-ah- <gvon-ah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:26:42 by gvon-ah-          #+#    #+#             */
/*   Updated: 2024/11/04 12:49:43 by gvon-ah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_d(int b)
{
	long int	i;
	long int	buf;

	buf = b;
	i = 1;
	if (b < 0)
	{
		buf = -buf;
		i++;
	}
	while (buf / 10 > 0)
	{
		buf /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;
	long	num;

	num = n;
	i = get_d(n);
	res = (char *)malloc(i + 1);
	if (!res)
		return (NULL);
	if (num < 0)
	{
		res[0] = '-';
		num = -num;
	}
	if (num == 0)
		res[0] = '0';
	res[i] = '\0';
	i--;
	while (i >= 0 && num > 0)
	{
		res[i] = (num % 10) + '0';
		num /= 10;
		i--;
	}
	return (res);
}
