/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvon-ah- <gvon-ah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:02:36 by gvon-ah-          #+#    #+#             */
/*   Updated: 2024/11/02 16:56:17 by gvon-ah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_char(const char *str, const char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	st;
	size_t	en;
	size_t	cr;

	st = 0;
	cr = 0;
	if (!s1)
		return (NULL);
	while (s1[st] && is_char(set, s1[st]))
		st++;
	en = ft_strlen(s1);
	while (en > st && is_char(set, s1[en -1]))
		en--;
	res = (char *)malloc(en - st + 1);
	if (!res)
		return (NULL);
	while (en > st)
	{
		res[cr] = s1[st];
		cr++;
		st++;
	}
	res[cr] = '\0';
	return (res);
}
