/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvon-ah- <gvon-ah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:00:14 by gvon-ah-          #+#    #+#             */
/*   Updated: 2024/11/01 18:08:06 by gvon-ah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*buf;
	const unsigned char	*inp;
	size_t				i;

	i = 0;
	buf = dst;
	inp = src;
	while (i < n && (src || dst))
	{
		buf[i] = inp[i];
		i++;
	}
	return (dst);
}
