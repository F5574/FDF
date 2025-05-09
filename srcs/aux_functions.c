/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisrael <gisrael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 23:27:02 by gisrael           #+#    #+#             */
/*   Updated: 2025/05/09 02:08:07 by gisrael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	is_signals(int c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int	is_color(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))
		return (1);
	return (0);
}

void	map_info(t_map *map, char *file)
{
	int		fd;
	char	*line;

	fd = filecheck(file);
	line = get_next_line(fd);
	if (!line)
		ft_error(ERROR_MAP, 0);
	map->mtz = ft_split(line, ' ');
	while (line)
	{
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
	while (map->mtz[map->width])
	{
		free(map->mtz[map->width]);
		map->width++;
	}
	free(map->mtz);
	close(fd);
}

void	isometric(t_map *map)
{
	map->ang[X] = 30;
	map->ang[Y] = 330;
	map->ang[Z] = 45;
}
