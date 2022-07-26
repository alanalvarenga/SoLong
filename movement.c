/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alachris <alachris@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 23:47:02 by alachris          #+#    #+#             */
/*   Updated: 2022/07/23 23:09:03 by alachris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	move_up(t_mapinfo *map_info)
{
	if (map_info->map[map_info->play_x - 1][map_info->play_y] != '1')
	{
		map_info->map[map_info->play_x][map_info->play_y] = '0';
		map_info->map[map_info->play_x - 1][map_info->play_y] = 'P';
		map_info->play_x = map_info->play_x - 1;
	}
}

void	move_down(t_mapinfo *map_info)
{
	if (map_info->map[map_info->play_x + 1][map_info->play_y] != '1')
	{
		map_info->map[map_info->play_x][map_info->play_y] = '0';
		map_info->map[map_info->play_x + 1][map_info->play_y] = 'P';
		map_info->play_x = map_info->play_x + 1;
	}
}

void	move_left(t_mapinfo *map_info)
{
	if (map_info->map[map_info->play_x][map_info->play_y - 1] != '1')
	{
		map_info->map[map_info->play_x][map_info->play_y] = '0';
		map_info->map[map_info->play_x][map_info->play_y-1] = 'P';
		map_info->play_y = map_info->play_y - 1;
	}
}

void	move_right(t_mapinfo *map_info,t_animation *animation)
{
	if (map_info->map[map_info->play_x][map_info->play_y + 1] == 'C')
		map_info->got_colection ++;
	if (map_info->map[map_info->play_x][map_info->play_y + 1] != '1')
	{
		map_info->map[map_info->play_x][map_info->play_y] = '0';
		map_info->map[map_info->play_x][map_info->play_y+1] = 'P';
		map_info->play_y = map_info->play_y + 1;
		animation->play_right = 1;
		animation->moves++;
		ft_printf("\n%d\n",animation->moves);
	}
}

void	move_player(int key,t_global *global)
{
	if (key == 'd')
	{
		move_right(&global->map_info,&global->animation);
	}
	if (key == 'a')
	{
		move_left(&global->map_info);
	}
	if (key == 's')
	{
		move_down(&global->map_info);
	}
	if (key == 'w')
	{
		move_up(&global->map_info);
	}
}