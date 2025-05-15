/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvon-ah- <gvon-ah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:26:51 by gisrael           #+#    #+#             */
/*   Updated: 2025/05/09 17:01:02 by gvon-ah-         ###   ########.fr       */
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
# define ERROR_COLOR "INVALID COLOR IN MAP"

// KEYS
# define ESC 65307
# define SRC_UP 4
# define SRC_DOWN 5
# define LA 65361
# define UP 65362
# define RA 65363
# define DOWN 65364

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

// aux_functions.c
int		is_signals(int c);
int		is_color(int c);
void	map_info(t_map *map, char *file);

// color.c
int		color_verify(char *temp, int i);
void	error_color(char *temp, t_map *map, int type);

// construct_destroy.c
void	window_init(t_window *wind);
void	map_init(t_map *map, char *file);
void	remap(t_map *map);
void	dot_allocs(t_dots **dots, int width, int height, t_map *map);
int		window_close(t_window *wind);

// draw.c
void	draw_map(t_map *map, t_window *window);
void	dda_alg(t_map *map, t_window *img);
void	dda_steps(t_map *map, t_window *img, t_dots cord1, t_dots cord2);
void	translation(int key_code, t_fdf *fdf);

// fdf_aux.c
void	ft_error(char *error_msg, int sys_func);
void	m_mlx_pixel_put(t_window *img, int x, int y, int color);
float	fabs_v(float n);
void	free_cord(t_map *map);
void	isometric(t_map *map);

// fdf.c
int		draw_img(t_fdf *fdf);
void	parser(t_map *map, char *path);

// hooks.c
void	hook_control(t_fdf *fdf);
int		key_press(int keycode, t_fdf *fdf);
int		map_zoom(int key_code, int x, int y, t_fdf *fdf);

// map_handlers.c
void	map_format(char *path);
void	map_matriz(t_map *map, char *file);

// parser.c
int		filecheck(char *path);
void	error_file_extension(char *path);
bool	is_valid_char(char *str);
void	free_map(char **map);
void	last_space(char *line, t_map *map, size_t i);

// rotations.c
void	rotation_x(t_map *map);
void	rotation_y(t_map *map);
void	rotation_z(t_map *map);
t_dots	matxmul(float mat[3][3], t_dots point);

#endif