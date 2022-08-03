/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alachris <alachris@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 22:53:41 by alachris          #+#    #+#             */
/*   Updated: 2022/08/04 00:28:22 by alachris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong_bonus.h"

void	save_play_info(t_mapinfo *map_info, int x, int y)
{
	map_info->p++;
	map_info->play_x = x;
	map_info->play_y = y;
}

int	size_rows(t_mapinfo *map_info)
{
	int	x;
	int	y;
	int	count_row;

	x = 0;
	count_row = map_info->columns;
	while (x < map_info->rows)
	{
		y = 0;
		while (map_info->map[x][y] != '\0')
			y++;
		if (x < (map_info->rows - 1))
		{
			if ((y - 1) != count_row)
				return (1);
		}
		else
		{
			if (y != count_row)
				return (1);
		}
		x++;
	}
	return (0);
}

int	verify_size(t_mapinfo *map_info)
{
	if ((map_info->columns == 3) && (map_info->rows < 5))
		return (1);
	else if ((map_info->rows == 3) && (map_info->columns < 5))
		return (1);
	else if ((map_info->rows < 4) && (map_info->columns < 4))
		return (1);
	if (size_rows(map_info) == 1)
	{
		ft_printf("Error\nMap with more or less rows\n");
		return (1);
	}
	if (map_info->map[map_info->rows - 1][0] == '\0')
	{
		ft_printf("Error\nMap with more columns\n");
		return (1);
	}
	return (0);
}

int	verify_character(t_mapinfo *map_info)
{
	int	x;
	int	y;

	x = -1;
	while (++x < map_info->rows)
	{
		y = -1;
		while (++y < map_info->columns)
		{
			if (map_info->map[x][y] == 'P')
				save_play_info(map_info, x, y);
			else if (map_info->map[x][y] == 'E')
				map_info->e++;
			else if (map_info->map[x][y] == 'C')
				map_info->c++;
			else if (map_info->map[x][y] == 'V')
				map_info->v++;
			else if ((map_info->map[x][y] != '1')
				&& (map_info->map[x][y] != '0'))
				return (1);
		}
	}
	return (0);
}
