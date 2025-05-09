/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisrael <gisrael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 23:11:13 by gisrael           #+#    #+#             */
/*   Updated: 2025/05/09 00:39:36 by gisrael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	draw_map(t_map *map, t_window *img)
{
	rotation_x(map);
	rotation_y(map);
	rotation_z(map);
	dda_alg(map, img);
	mlx_put_image_to_window(img->mlx, img->mlx_window, img->img, 0, 0);
	free_cord(map);
}

void	dda_alg(t_map *map, t_window *img)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x != map->width - 1)
				dda_steps(map, img, map->point[y][x], map->point[y][x + 1]);
			if (y != map->height - 1)
				dda_steps(map, img, map->point[y][x], map->point[y + 1][x]);
			x += 1;
		}
		y += 1;
	}
}

void	dda_steps(t_map *map, t_window *img, t_dots cord1, t_dots cord2)
{
	float	step;
	float	xin;
	float	yin;

	map->point[Y][X].dx = (cord2.cord[X] * map->scale * map->zoom) \
		- (cord1.cord[X] * map->scale * map->zoom);
	map->point[Y][X].dy = (cord2.cord[Y] * map->scale * map->zoom) \
		- (cord1.cord[Y] * map->scale * map->zoom);
	step = sqrt(pow(map->point[Y][X].dx, 2) + pow(map->point[Y][X].dy, 2));
	xin = map->point[Y][X].dx / step;
	yin = map->point[Y][X].dy / step;
	cord1.dx = map->orig_cord[X] + (cord1.cord[X] * map->scale * map->zoom);
	cord1.dy = map->orig_cord[Y] + (cord1.cord[Y] * map->scale * map->zoom);
	while (step >= 0)
	{
		if ((int)cord1.dx < WIDTH && (int)cord1.dx > 0 && \
			((int)cord1.dy < HEIGHT && (int)cord1.dy > 0))
			m_mlx_pixel_put(img, (int)cord1.dx, (int)cord1.dy, WHITE);
		cord1.dx += xin;
		cord1.dy += yin;
		step--;
	}
}

void	translation(int key_code, t_fdf *fdf)
{
	if (key_code == DOWN)
		fdf->map.orig_cord[Y] -= 100;
	else if (key_code == UP)
		fdf->map.orig_cord[Y] += 100;
	else if (key_code == RA)
		fdf->map.orig_cord[X] -= 100;
	else if (key_code == LA)
		fdf->map.orig_cord[X] += 100;
}