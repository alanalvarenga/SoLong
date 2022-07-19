/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alachris <alachris@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:48:16 by alachris          #+#    #+#             */
/*   Updated: 2022/07/19 21:34:55 by alachris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

unsigned int    get_color(t_data *data, int x, int y)
{
    char    *color;

    color = data->addr + (y * data->l_len + x * (data->bpp / 8));
    return (*(unsigned int *)color);
}

void	print_player(t_mlx *mlx)
{
	t_data player;

	int	x_img = mlx->x;
	int	y_img = mlx->y;
	int	x = 0;
	int	y = 0;

	player.img = mlx_xpm_file_to_image(mlx->mlx,"./images/goku_stand_to_right.xpm",&player.pos_x,&player.pos_y);
	player.addr = mlx_get_data_addr(player.img,&player.bpp,&player.l_len,&player.endian);

	while(x_img < (mlx->x + 40))
	{
		//mlx->y = 0;
		y_img = mlx->y;
		y=0;
		while(y_img < (mlx->y + 40))
		{
			if(get_color(&player,x,y) != 4278190080)
			{
				//ft_mlx_pixel_put(&img_teste.img,x,y,get_color(&player,x,y));
				mlx_pixel_put(mlx->mlx,mlx->win,x_img,y_img,get_color(&player,x,y));
			}
			y++;
			y_img++;
			//mlx->y++;
		}
		x++;
		x_img++;
		//mlx->x++;
	}
}

void	sprite_print(t_mlx *mlx, t_mapinfo *map_info)
{
	t_data floor;	
	t_data wall;
	
	floor.img = mlx_xpm_file_to_image(mlx->mlx,"./images/floor2.xpm",&floor.pos_x,&floor.pos_y);
	floor.addr = mlx_get_data_addr(floor.img,&floor.bpp,&floor.l_len,&floor.endian);

	wall.img = mlx_xpm_file_to_image(mlx->mlx,"./images/rock_wall.xpm",&wall.pos_x,&wall.pos_y);
	wall.addr = mlx_get_data_addr(wall.img,&wall.bpp,&wall.l_len,&wall.endian);	

	if (map_info->map[map_info->y_actual][map_info->x_actual] == '1')
		mlx_put_image_to_window(mlx->mlx,mlx->win,wall.img,mlx->x,mlx->y);
	else if (map_info->map[map_info->y_actual][map_info->x_actual] == '0')
		mlx_put_image_to_window(mlx->mlx,mlx->win,floor.img,mlx->x,mlx->y);
	else if (map_info->map[map_info->y_actual][map_info->x_actual] == 'P')
	{
		mlx_put_image_to_window(mlx->mlx,mlx->win,floor.img,mlx->x,mlx->y);
    	//print_player(mlx);
	}
}

int	render_map(t_mlx *mlx, t_mapinfo *map_info)
{
	map_info->x_actual = 0;
	map_info->y_actual = 0;
	mlx->x = 0;
	mlx->y = 0;
		
	while(mlx->x < map_info->columns * 40)
	{
		ft_printf("\nENTRO1\n");
		mlx->y = 0;
		map_info->y_actual = 0;
		while( mlx->y < map_info->rows * 40)
		{
			//ft_mlx_pixel_put(&img_teste.img,x,y,get_color(&img_data,x,y));
			//mlx_pixel_put(mlx,win,x,y,get_color(&img_data,x,y));
			ft_printf("\nENTROU2\n");
			//sprite_print(mlx,map_info);
			//mlx_put_image_to_window(mlx.mlx,mlx.win,img_data.img,mlx.x,mlx.y);
			mlx->y+=40;
			map_info->y_actual++;
		}		
		mlx->x+=40;
		map_info->x_actual++;
	}
	return (0);
}

void	render_window(t_mapinfo *map_info)
{
	t_mlx mlx_d;			
	//int	x = 0;
	//int	y = 0;	
	
	mlx_d.mlx = mlx_init();
	mlx_d.win = mlx_new_window(mlx_d.mlx, map_info->columns * 40, (map_info->rows * 40)+1, "Teste Window");	
	
	
	// mlx_put_image_to_window(mlx,win,img_data.img,0,0);
	// mlx_put_image_to_window(mlx,win,img_data.img,40,0);
	// mlx_put_image_to_window(mlx,win,player.img,0,0);
	
	mlx_loop_hook(mlx_d.mlx, render_map, (void *)&mlx_d);

	// t_data img_teste;
	// img_teste.img = mlx_new_image(mlx.mlx,640,360);
	// img_teste.addr = mlx_get_data_addr(img_teste.img,&img_teste.bpp,&img_teste.l_len,&img_teste.endian);
	
	//print_player(&mlx);
	//ft_printf("\ncor: %u\n",get_color(&player.img,0,0)); 4278190080
	//mlx_put_image_to_window(mlx,win,img_teste.img,0,0);	
	mlx_loop(mlx_d.mlx);
}
