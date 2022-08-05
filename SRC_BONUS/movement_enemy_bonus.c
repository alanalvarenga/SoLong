/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_enemy_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alachris <alachris@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 22:36:49 by alachris          #+#    #+#             */
/*   Updated: 2022/08/05 02:27:15 by alachris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong_bonus.h"

void	move_enemy_right(t_mapinfo *map_info, int x, int *y)
{
	map_info->map[x][*y] = '0';
	map_info->map[x][*y + 1] = 'V';
	map_info->go_back = 1;
	*y = map_info->columns;
}

void	move_enemy_left(t_mapinfo *map_info, int x, int *y)
{
	if ((map_info->go_back == 1) && (map_info->map[x][*y - 1] == '0'))
	{
		map_info->map[x][*y] = '0';
		map_info->map[x][*y - 1] = 'V';
		map_info->go_back = 2;
	}
	else if ((map_info->go_back == 2) && (map_info->map[x][*y - 1] == '0'))
	{
		map_info->map[x][*y] = '0';
		map_info->map[x][*y - 1] = 'V';
		map_info->go_back = 0;
		*y = map_info->columns;
	}
	else
		map_info->go_back = 0;
}

void	move_enemy(t_mapinfo *map_info)
{
	int			x;
	int			y;

	x = 0;
	while (x < map_info->rows)
	{
		y = 0;
		while (y < map_info->columns)
		{
			if (map_info->map[x][y] == 'V')
			{
				if ((map_info->map[x][y + 1] == '0')
					&& (map_info->go_back == 0))
					move_enemy_right(map_info, x, &y);
				else if (map_info->go_back != 0)
					move_enemy_left(map_info, x, &y);
			}
			y++;
		}
		x++;
	}
}
