/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisrael <gisrael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 23:21:32 by gisrael           #+#    #+#             */
/*   Updated: 2025/05/09 12:40:04 by gisrael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	hook_control(t_fdf *fdf)
{
	mlx_hook(fdf->window.mlx_window, 17, 0, window_close, fdf);
	mlx_hook(fdf->window.mlx_window, 2, 1L << 0, key_press, fdf);
	mlx_mouse_hook(fdf->window.mlx_window, map_zoom, fdf);
}

int	key_press(int key_code, t_fdf *fdf)
{
	if (key_code == ESC)
		window_close(&fdf->window);
	else if (key_code == UP || key_code == DOWN \
		|| key_code == RA || key_code == LA)
		translation(key_code, fdf);
	return (0);
}

int	map_zoom(int key_code, int x, int y, t_fdf *fdf)
{
	float	prev_zoom;

	prev_zoom = fdf->map.zoom;
	if (key_code == SRC_UP)
		fdf->map.zoom *= 1.2;
	else if (key_code == SRC_DOWN && fdf->map.zoom > 0.2)
		fdf->map.zoom /= 1.2;
	else
		return (0);
	fdf->map.orig_cord[X] = x - ((x - fdf->map.orig_cord[X]) \
		* (fdf->map.zoom / prev_zoom));
	fdf->map.orig_cord[Y] = y - ((y - fdf->map.orig_cord[Y]) \
		* (fdf->map.zoom / prev_zoom));
	return (0);
}
