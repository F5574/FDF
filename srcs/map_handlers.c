/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisrael <gisrael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 17:20:19 by gisrael           #+#    #+#             */
/*   Updated: 2025/05/09 12:44:34 by gisrael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static int	dots_count(char *line)
{
	int	i;
	int	count;
	int	in_value;

	i = 0;
	count = 0;
	in_value = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != ' ' && !in_value)
		{
			count++;
			in_value = 1;
		}
		else if (line[i] == ' ')
		{
			in_value = 0;
		}
		i++;
	}
	return (count);
}

static void	error_map(char *line, int fd, char *msg)
{
	free(line);
	close(fd);
	ft_error(msg, 0);
	exit(1);
}

static void	map_cord_put(char *line, int y, t_map *map)
{
	int		x;
	char	*temp;

	x = 0;
	temp = line;
	while (*temp && x < map->width)
	{
		while (*temp == ' ' || *temp == 9)
			temp++;
		if (!is_valid_char(temp))
		{
			ft_error(ERROR_CHAR, 0);
			free(line);
			free_cord(map);
			exit (0);
		}
		map->point[y][x].cord[X] = (x + 0.5 - (map->width / 2));
		map->point[y][x].cord[Y] = (y + 0.5 - (map->height / 2));
		map->point[y][x].cord[Z] = ft_atoi(temp);
		while (*temp && (is_signals(*temp) || ft_isdigit(*temp)
				|| is_color(*temp)))
			temp++;
		x++;
	}
}

void	map_format(char *path)
{
	int		fd;
	char	*line;
	int		dot_count;
	int		prev_dot_count;

	dot_count = 0;
	prev_dot_count = 0;
	fd = filecheck(path);
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == '\n' || line[0] == '\0')
			error_map(line, fd, "Error: Empty line in map");
		dot_count = dots_count(line);
		if (prev_dot_count == 0)
			prev_dot_count = dot_count;
		if (dot_count != prev_dot_count)
			error_map(line, fd, "Error: Inconsistent number of dots in lines");
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	map_matriz(t_map *map, char *file)
{
	int		fd;
	int		y;
	char	*temp;
	char	*line;

	y = 0;
	fd = filecheck(file);
	map->point = malloc(sizeof(t_dots *) * (map->height));
	if (!map->point)
		ft_error(ERROR_INIT, 0);
	dot_allocs(map->point, map->width, map->height, map);
	while (y < map->height)
	{
		line = get_next_line(fd);
		temp = line;
		last_space(temp, map);
		map_cord_put(temp, y, map);
		free(line);
		y++;
	}
	close (fd);
}
