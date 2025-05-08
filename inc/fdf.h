/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisrael <gisrael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:26:51 by gisrael           #+#    #+#             */
/*   Updated: 2025/05/08 17:15:00 by gisrael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>
# include <string.h>
# include <stdint.h>
# include <errno.h>
# include <stdbool.h>
# include <math.h>
# include <fcntl.h>
# include "../inc/libft/libft.h"
# include "../minilibx-linux/mlx.h"

// Defines ###

// MAPS
# define WIDTH 1920
# define HEIGHT 1080

// Projections_Values
# define ISOMETRIC 0
# define FRONT_VIEW 1
# define SIDE_VIEW 2
# define TOP_VIEW 3

// CORD_AXIS
# define X 0
# define Y 1
# define Z 2

// PI
# define PI 3.14159265358979323846

// COLORS
# define WHITE 0x00FFFFFF
# define BLACK 0x000000 

# define ERROR_ARGS "ARGUMENTS DIFFERENT FROM 1"
# define ERROR_INIT "ERROR INIT"
# define ERROR_MAP_LEN "MAP TO BIG OR TO SMALL"
# define ERROR_MAP "MAP EMPTY OR NULL"
# define ERROR_SPACE "TO MANY SPACES"
# define ERROR_CHAR "INVALID CHARACTER IN MAP"
# define ERROR_FORMAT "MAP NOT RETANGULAR"

// structs ###
typedef struct s_window
{
	void	*mlx;
	void	*mlx_window;
	void	*img;
	char	*addr;
	int		bitpp;
	int		line_length;
	int		endian;
}			t_window;

typedef struct s_dots
{
	float	cord[3];
	float	dx;
	float	dy;
	int		color;
}			t_dots;

typedef struct s_map
{
	char	**mtz;
	int		ang[3];
	int		scale;
	float	zoom;
	float	orig_cord[3];
	int		height;
	int		width;
	char	*file;
	t_dots	**point;
}			t_map;

typedef struct s_fdf
{
	t_window	window;
	t_map		map;
}				t_fdf;

// Functions ###

// parser
int     filecheck(char *path);
void	error_file_extension(char *path);

#endif