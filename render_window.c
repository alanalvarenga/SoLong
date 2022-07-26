/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alachris <alachris@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:48:16 by alachris          #+#    #+#             */
/*   Updated: 2022/07/26 02:04:36 by alachris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

unsigned int    get_color(t_data *data, int x, int y)
{
    char    *color;

    color = data->addr + (y * data->l_len + x * (data->bpp / 8));
    return (*(unsigned int *)color);
}

int	action_loop(t_global *global)
{
	//mlx_clear_window(global->mlx_d.mlx,global->mlx_d.win);
	render_map(&global->mlx_d,&global->map_info,&global->sprites,&global->animation);
	global->animation.count++;
	//ft_printf("\n%d",global->animation->count);
	if (global->animation.count >= 0 && global->animation.count <=150)
		global->animation.control = 1;
	else if (global->animation.count >= 151 && global->animation.count <= 300)
		global->animation.control = 2;
	else if (global->animation.count >= 301 && global->animation.count <= 450)
		global->animation.control = 1;
	else if (global->animation.count >= 451 && global->animation.count <= 600)
		global->animation.control = 3;
	else if (global->animation.count >=601)
		global->animation.count = 0;

	return(0);
}

int	key_press(int key, t_global *global)
{
	if (key == 'q' || key == ESC)
	{
		mlx_clear_window(global->mlx_d.mlx,global->mlx_d.win);
		mlx_destroy_window(global->mlx_d.mlx,global->mlx_d.win);
		mlx_destroy_display(global->mlx_d.mlx);
		free(global->mlx_d.mlx);
	}
	if (ft_strchr("wasd", key))
	{
		move_player(key,global);
	}
	return (0);
}

int	render_map(t_mlx *mlx, t_mapinfo *map_info, t_sprites *sprites,t_animation *animation)
{
	map_info->x_actual = 0;
	map_info->y_actual = 0;
	mlx->x = 0;
	mlx->y = 0;
		
	while(mlx->x < map_info->columns * 40)
	{		
		mlx->y = 0;
		map_info->y_actual = 0;
		while( mlx->y < map_info->rows * 40)
		{
			//ft_mlx_pixel_put(&img_teste.img,x,y,get_color(&img_data,x,y));
			//mlx_pixel_put(mlx,win,x,y,get_color(&img_data,x,y));			
			sprite_print(mlx, map_info, sprites,animation);			
			//mlx_put_image_to_window(mlx.mlx,mlx.win,img_data.img,mlx.x,mlx.y);
			mlx->y+=40;
			map_info->y_actual++;
		}		
		mlx->x+=40;
		map_info->x_actual++;
	}	
	return (0);
}

void	render_window(t_global *global)
{
	//t_mlx mlx_d;			
	//int	x = 0;
	//int	y = 0;	
	
	global->mlx_d.mlx = mlx_init();
	global->mlx_d.win = mlx_new_window(global->mlx_d.mlx,
	global->map_info.columns * 40,
	(global->map_info.rows * 40)+1, "Teste Window");	

	fill_sprites(&global->mlx_d, &global->sprites);
	
	
	// mlx_put_image_to_window(mlx,win,img_data.img,0,0);
	// mlx_put_image_to_window(mlx,win,img_data.img,40,0);
	// mlx_put_image_to_window(mlx,win,player.img,0,0);
	
	mlx_loop_hook(global->mlx_d.mlx, action_loop, (void *)global);
	mlx_key_hook(global->mlx_d.win, key_press, (void *)global);
	
	// t_data img_teste;
	// img_teste.img = mlx_new_image(mlx.mlx,640,360);
	// img_teste.addr = mlx_get_data_addr(img_teste.img,&img_teste.bpp,&img_teste.l_len,&img_teste.endian);
	
	//print_player(&mlx);
	//ft_printf("\ncor: %u\n",get_color(&player.img,0,0)); 4278190080
	//mlx_put_image_to_window(mlx,win,img_teste.img,0,0);	
	mlx_loop(global->mlx_d.mlx);
}
