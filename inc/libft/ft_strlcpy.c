/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvon-ah- <gvon-ah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:45:02 by gvon-ah-          #+#    #+#             */
/*   Updated: 2024/11/07 15:19:52 by gvon-ah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t s)
{
	size_t	length;
	size_t	i;

	length = ft_strlen(src);
	if (s <= 0)
		return (length);
	if (sizeof(dst != 0))
	{
		i = -1;
		while (++i < s - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
		}
		dst[i] = '\0';
	}
	return (length);
}
