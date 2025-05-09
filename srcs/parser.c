/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisrael <gisrael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:49:18 by gisrael           #+#    #+#             */
/*   Updated: 2025/05/09 12:50:41 by gisrael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	filecheck(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_error("Error opening file", 0);
		exit(0);
	}
	if (read(fd, 0, 0) < 0)
	{
		ft_error("Error reading file", 0);
		close(fd);
		exit(0);
	}
	return (fd);
}

void	error_file_extension(char *path)
{
	size_t	len;

	len = ft_strlen(path);
	if (len < 4 || ft_strncmp(path + len - 4, ".fdf", 4))
	{
		ft_error("WRONG Type of file!     !(.fdf)", 0);
		exit(1);
	}
}

bool	is_valid_char(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (false);
	if (is_signals(str[i]))
		i++;
	while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
	{
		if (str[i] == ',')
		{
			if (color_verify(str, i))
				return (false);
			break ;
		}
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

void	free_map(char **map)
{
	size_t	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

void	last_space(char *line, t_map *map)
{
	char	*temp;
	size_t	i;

	temp = line;
	i = 0;
	while (temp[i] && temp[i] != '\n')
	{
		while (temp[i] == ' ' || temp[i] == '\t')
			i++;
		if (ft_isdigit(temp[i]) || is_signals(temp[i]))
		{
			while (ft_isdigit(temp[i]))
				i++;
			if (temp[i] == ',')
			{
				if (color_verify(temp, i))
					error_color(temp, map, 1);
				while (temp[i] && temp[i] != ' ' && temp[i] != '\t'
					&& temp[i] != '\n')
					i++;
			}
		}
		else if (temp[i] != '\0' && temp[i] != '\n')
			error_color(temp, map, 2);
	}
}
