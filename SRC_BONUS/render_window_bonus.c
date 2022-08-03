/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_window_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alachris <alachris@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 22:54:29 by alachris          #+#    #+#             */
/*   Updated: 2022/08/04 00:19:22 by alachris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong_bonus.h"

int	action_loop(t_global *global)
{
	render_map(&global->mlx_d, &global->map_info, &global->sprites,
		&global->animation);
	animation_player(global);
	return (0);
}

int	key_press(int key, t_global *global)
{
	if (key == 'q' || key == ESC)
	{
		close_game(global);
	}
	if (ft_strchr("wasd", key))
	{
		move_player(key, global);
	}
	return (0);
}

int	render_map(t_mlx *mlx, t_mapinfo *map_info, t_sprites *sprites,
				t_animation *animation)
{
	map_info->x_actual = 0;
	map_info->y_actual = 0;
	mlx->x = 0;
	mlx->y = 0;
	while (mlx->x < (map_info->columns * 40))
	{
		mlx->y = 0;
		map_info->y_actual = 0;
		while (mlx->y < (map_info->rows * 40))
		{	
			sprite_print(mlx, map_info, sprites, animation);
			mlx->y += 40;
			map_info->y_actual++;
		}		
		mlx->x += 40;
		map_info->x_actual++;
	}	
	return (0);
}

int	close_game(t_global *global)
{	
	free_map(&global->map_info);
	free_images(global);
	free_mlx(global);
	exit(0);
	return (0);
}

void	render_window(t_global *global)
{
	global->mlx_d.mlx = mlx_init();
	global->mlx_d.win = mlx_new_window(global->mlx_d.mlx,
			global->map_info.columns * 40,
			(global->map_info.rows * 40) + 1, "So Long");
	fill_sprites(&global->mlx_d, &global->sprites);
	mlx_loop_hook(global->mlx_d.mlx, action_loop, (void *)global);
	mlx_key_hook(global->mlx_d.win, key_press, (void *)global);
	mlx_hook(global->mlx_d.win, EXIT, 0, close_game, (void *)global);
	mlx_loop(global->mlx_d.mlx);
}
