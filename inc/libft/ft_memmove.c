/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvon-ah- <gvon-ah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:03:55 by gvon-ah-          #+#    #+#             */
/*   Updated: 2024/11/04 15:34:03 by gvon-ah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;

	i = 0;
	if (src == NULL && dst == NULL)
		return (NULL);
	if ((size_t)dst - (size_t)src < len)
	{
		i = (int)len -1;
		while (i >= 0 && i < (int)len)
		{
			(((unsigned char *)dst)[i] = ((unsigned char *)src)[i]);
			i--;
		}
	}
	else
	{
		while (i < (int)len)
		{
			(((unsigned char *)dst)[i] = ((unsigned char *)src)[i]);
			i++;
		}
	}
	return (dst);
}
