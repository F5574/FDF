/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisrael <gisrael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:26:38 by gisrael           #+#    #+#             */
/*   Updated: 2025/05/09 12:59:31 by gisrael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	main(int argc, char *argv[])
{
	t_fdf	fdf;

	if (argc == 2)
	{
		parser(&fdf.map, argv[1]);
		window_init(&fdf.window);
		draw_map(&fdf.map, &fdf.window);
		hook_control(&fdf);
		mlx_loop_hook(fdf.window.mlx, draw_img, &fdf);
		mlx_loop(fdf.window.mlx);
	}
	else
		ft_error(ERROR_ARGS, 0);
}

void	parser(t_map *map, char *path)
{
	error_file_extension(path);
	map_init(map, path);
	isometric(map);
}

int	draw_img(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			m_mlx_pixel_put(&fdf->window, x, y, BLACK);
			x++;
		}
		y++;
	}
	remap(&fdf->map);
	draw_map(&fdf->map, &fdf->window);
	return (0);
}

// valgrind --leak-check=full --show-leak-kinds=all 
//--track-fds=yes ./fdf Maps/test_maps/pnp_flat.fdf