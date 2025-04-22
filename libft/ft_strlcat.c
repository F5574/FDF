/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvon-ah- <gvon-ah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:53:08 by gvon-ah-          #+#    #+#             */
/*   Updated: 2024/11/01 21:06:58 by gvon-ah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t s)
{
	size_t	i;
	size_t	j;
	size_t	srcl;
	size_t	dstl;

	srcl = ft_strlen(src);
	dstl = ft_strlen(dst);
	if (s <= dstl)
		return (s + srcl);
	i = 0;
	j = dstl;
	while ((i + j) < (s -1) && src[i] != '\0')
	{
		dst[i + j] = src[i];
		i++;
	}
	dst[i + j] = '\0';
	return (srcl + dstl);
}
