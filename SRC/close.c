/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alachris <alachris@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 21:39:54 by alachris          #+#    #+#             */
/*   Updated: 2022/08/03 02:09:36 by alachris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	free_map(t_mapinfo *map_info)
{
	int	count;

	count = 0;
	while (count <= map_info->rows - 1)
	{
		free(map_info->map[count]);
		count++;
	}
	free(map_info->map);
}

void	free_images_player(t_global *global)
{
	int	i;

	i = 1;
	while (i < 13)
	{
		mlx_destroy_image(global->mlx_d.mlx, global->sprites.player[i].img);
		i++;
	}
}

void	free_images(t_global *global)
{
	mlx_destroy_image(global->mlx_d.mlx, global->sprites.collec.img);
	mlx_destroy_image(global->mlx_d.mlx, global->sprites.floor.img);
	mlx_destroy_image(global->mlx_d.mlx, global->sprites.wall.img);
	mlx_destroy_image(global->mlx_d.mlx, global->sprites.exit.img);
	free_images_player(global);
}

void	free_mlx(t_global *global)
{
	mlx_clear_window(global->mlx_d.mlx, global->mlx_d.win);
	mlx_destroy_window(global->mlx_d.mlx, global->mlx_d.win);
	mlx_destroy_display(global->mlx_d.mlx);
	free(global->mlx_d.mlx);
	global->mlx_d.mlx = NULL;
}
