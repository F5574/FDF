/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvon-ah- <gvon-ah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:35:38 by gvon-ah-          #+#    #+#             */
/*   Updated: 2024/11/19 17:47:01 by gvon-ah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(const char *str, char d)
{
	size_t	i;
	size_t	tt;

	tt = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == d)
			i++;
		if (str[i])
			tt++;
		while (str[i] && str[i] != d)
			i++;
	}
	return (tt);
}

static char	*str_alloc(const char *src, char c)
{
	char	*str;
	size_t	len;
	size_t	i;

	i = -1;
	len = 0;
	while (src[len] && src[len] != c)
		len++;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	while (++i < len)
		str[i] = src[i];
	str[i] = '\0';
	return (str);
}

static void	*free_str(char **str, int i)
{
	while (i >= 0)
		free(str[i--]);
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**str;

	if (!s)
		return (NULL);
	i = 0;
	str = malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			str[i] = str_alloc(s, c);
			if (!str[i++])
				return (free_str(str, i - 1));
		}
		while (*s && *s != c)
			s++;
	}
	str[i] = 0;
	return (str);
}
