/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_destroy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisrael <gisrael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 23:46:04 by gisrael           #+#    #+#             */
/*   Updated: 2025/04/24 00:02:49 by gisrael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	window_init(t_window *wind)
{
	wind->mlx = mlx_init();
	wind->mlx_window = mlx_new_window(wind->mlx, WIDTH, \
		HEIGHT, "gvon-ah- FDF!");
	wind->img = mlx_new_image(wind->mlx, WIDTH, HEIGHT);
	wind->addr = mlx_get_data_addr(wind->img, &wind->bitpp, \
		&wind->line_length, &wind->endian);
}

void	map_init(t_map *map, char *file)
{
	map->file = file;
	map_format(file);
	map->height = 0;
	map->width = 0;
	map->orig_cord[X] = WIDTH / 2;
	map->orig_cord[Y] = HEIGHT / 2;
	map->orig_cord[Z] = 0;
	map_info(map, file);
	map->scale = 25;
	map->zoom = 1;
	map_matriz(map, file);
}

void	remap(t_map *map)
{
	map->height = 0;
	map->width = 0;
	map_info(map, map->file);
	map->scale = 25;
	map_matriz(map, map->file);
}

void	dot_allocs(t_dots **dots, int width, int height, t_map *map)
{
	int	y;

	y = -1;
	while (++y < height)
	{
		dots[y] = malloc(sizeof(t_dots) * (width));
		if (!dots[y])
		{
			free_cord(map);
			ft_error(ERROR_ARGS, 0);
			exit(1);
		}
	}
}

int	window_close(t_window *wind)
{
	mlx_destroy_image(wind->mlx, wind->img);
	mlx_destroy_window(wind->mlx, wind->mlx_window);
	mlx_destroy_display(wind->mlx);
	free(wind->mlx);
	exit(0);
}
