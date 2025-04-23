/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvon-ah- <gvon-ah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:14:11 by gvon-ah-          #+#    #+#             */
/*   Updated: 2024/10/30 20:02:09 by gvon-ah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	unsigned char	*str;
	unsigned char	cha;
	size_t			i;

	str = (unsigned char *)s;
	cha = (unsigned char)c;
	i = 0;
	while (i++ < len)
	{
		if (*str == cha)
		{
			return (str);
		}
		str++;
	}
	return (NULL);
}
