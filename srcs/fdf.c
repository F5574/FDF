/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisrael <gisrael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:26:38 by gisrael           #+#    #+#             */
/*   Updated: 2025/05/08 17:17:00 by gisrael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	main(int argc, char *argv[])
{
	t_fdf	fdf;

	if (argc == 2)
	{
		parser(&fdf, argv[1]);
	}
	else
		ft_error(ERROR_ARGS, 0);
}

static void	parser(t_map *map, char *path)
{
	error_file_extension(path);
	map_init(map, path);
	isometric(map);
}
