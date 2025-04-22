/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvon-ah- <gvon-ah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:43:25 by gvon-ah-          #+#    #+#             */
/*   Updated: 2025/04/22 19:23:58 by gvon-ah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	l1;
	size_t	l2;

	l1 = 0;
	if (!*to_find)
		return ((char *)str);
	while (str[l1] != '\0' && l1 < len)
	{
		if (str[l1] == to_find[0])
		{
			l2 = 1;
			while (to_find[l2] != '\0' && str[l1 + l2] == to_find[l2]
				&& l1 + l2 < len)
				++l2;
			if (to_find[l2] == '\0')
				return ((char *)&str[l1]);
		}
		++l1;
	}
	return (0);
}
