/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvon-ah- <gvon-ah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 01:03:51 by gisrael           #+#    #+#             */
/*   Updated: 2025/05/15 15:50:37 by gvon-ah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	color_verify(char *temp, int i)
{
	int	start;

	if (temp[i] != ',')
		return (1);
	i++;
	if (temp[i] != '0' || temp[i + 1] != 'x')
		return (1);
	i += 2;
	start = i;
	while (temp[i] && ((temp[i] >= '0' && temp[i] <= '9')
			|| (temp[i] >= 'A' && temp[i] <= 'F')
			|| (temp[i] >= 'a' && temp[i] <= 'f')))
		i++;
	if (i - start < 1 || i - start > 6)
		return (1);
	if (temp[i] && temp[i] != ' ' && temp[i] != '\t' && temp[i] != '\n')
		return (1);
	return (0);
}

void	error_color(char *temp, t_map *map, int type)
{
	if (type == 1)
		ft_error(ERROR_COLOR, 0);
	else if (type == 2)
		ft_error(ERROR_CHAR, 0);
	free(temp);
	free_cord(map);
	exit(0);
}
