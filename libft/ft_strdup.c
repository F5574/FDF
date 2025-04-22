/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvon-ah- <gvon-ah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 22:37:32 by gvon-ah-          #+#    #+#             */
/*   Updated: 2024/11/04 15:41:55 by gvon-ah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	l;
	size_t	i;
	char	*dst;

	l = ft_strlen(s1);
	i = -1;
	dst = ft_calloc(sizeof(char), (l + 1));
	if (!dst)
		return (NULL);
	while (++i < l)
		dst[i] = s1[i];
	return (dst);
}
