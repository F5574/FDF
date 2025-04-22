/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvon-ah- <gvon-ah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:46:34 by gvon-ah-          #+#    #+#             */
/*   Updated: 2025/04/22 19:40:43 by gvon-ah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*res;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || FOPEN_MAX <= fd)
	{
		if (fd > 0 && FOPEN_MAX > fd)
			while (buffer[fd][i])
				buffer[fd][i++] = '\0';
		return (NULL);
	}
	res = NULL;
	while (buffer[fd][0] || read(fd, buffer[fd], BUFFER_SIZE) > 0)
	{
		res = aux_strjoin(res, buffer[fd]);
		if (!res)
			return (NULL);
		aux_buffer_clean(buffer[fd]);
		if (res[aux_len(res) - 1] == '\n')
			return (res);
	}
	return (res);
}
