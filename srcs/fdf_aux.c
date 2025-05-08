/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisrael <gisrael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:44:03 by gisrael           #+#    #+#             */
/*   Updated: 2025/04/24 00:02:28 by gisrael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_error(char *error_msg, int sys_func)
{
	if (!sys_func)
		ft_putendl_fd(error_msg, STDERR_FILENO);
	else
		perror(error_msg);
}

void	my_mlx_pixel_put(t_window *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bitpp / 8));
	*(unsigned int *)dst = color;
}

int	testkey(int key_code, t_window *wind)
{
	(void)wind;
	ft_printf("key_code: %d\n", key_code);
	return (0);
}

float	fabs_v(float n)
{
	if (n < 0)
		n = -n;
	return (n);
}

void	free_cord(t_map *map)
{
	int	y;

	y = -1;
	if (map && map->point)
	{
		while (++y < map->height)
			free(map->point[y]);
		free(map->point);
		map->point = NULL;
	}
}
