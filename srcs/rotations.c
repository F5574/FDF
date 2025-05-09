/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisrael <gisrael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 23:31:03 by gisrael           #+#    #+#             */
/*   Updated: 2025/05/09 12:40:13 by gisrael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	rotation_x(t_map *map)
{
	float	radian_x;
	float	rot_x[3][3];
	int		y;
	int		x;

	radian_x = map->ang[X] * (PI / 180);
	rot_x[0][0] = 1;
	rot_x[0][1] = 0;
	rot_x[0][2] = 0;
	rot_x[1][0] = 0;
	rot_x[1][1] = cos(radian_x);
	rot_x[1][2] = -sin(radian_x);
	rot_x[2][0] = 0;
	rot_x[2][1] = sin(radian_x);
	rot_x[2][2] = cos(radian_x);
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
			map->point[y][x] = matxmul(rot_x, map->point[y][x]);
	}
}

void	rotation_y(t_map *map)
{
	float	radian_y;
	float	rot_y[3][3];
	int		y;
	int		x;

	radian_y = map->ang[Y] * (PI / 180);
	rot_y[0][0] = cos(radian_y);
	rot_y[0][1] = 0;
	rot_y[0][2] = sin(radian_y);
	rot_y[1][0] = 0;
	rot_y[1][1] = 1;
	rot_y[1][2] = 0;
	rot_y[2][0] = -sin(radian_y);
	rot_y[2][1] = 0;
	rot_y[2][2] = cos(radian_y);
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
			map->point[y][x] = matxmul(rot_y, map->point[y][x]);
	}
}

void	rotation_z(t_map *map)
{
	float	radian_z;
	float	rot_z[3][3];
	int		y;
	int		x;

	radian_z = map->ang[Z] * (PI / 180);
	rot_z[0][0] = cos(radian_z);
	rot_z[0][1] = -sin(radian_z);
	rot_z[0][2] = 0;
	rot_z[1][0] = sin(radian_z);
	rot_z[1][1] = cos(radian_z);
	rot_z[1][2] = 0;
	rot_z[2][0] = 0;
	rot_z[2][1] = 0;
	rot_z[2][2] = 1;
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
			map->point[y][x] = matxmul(rot_z, map->point[y][x]);
	}
}

t_dots	matxmul(float mat[3][3], t_dots point)
{
	int		i;
	int		j;
	t_dots	tmp;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		tmp.cord[i] = 0;
		while (++j < 3)
		{
			tmp.cord[i] += point.cord[j] * mat[i][j];
		}
	}
	return (tmp);
}
