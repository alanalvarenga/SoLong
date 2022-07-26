/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alachris <alachris@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 21:31:23 by alachris          #+#    #+#             */
/*   Updated: 2022/07/26 01:58:11 by alachris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void check_look(t_animation *animation)
{
	if (animation->control == 1)
	{
		//if(get_color(&sp->player[0],x,y) != 4278190080)
			//mlx_pixel_put(mlx->mlx,mlx->win,x_img,y_img,get_color(&sp->player_r[0],x,y));		
		animation->control = 2;
	}
	if (animation->control == 2)
	{
		//if(get_color(&sp->player[1],x,y) != 4278190080)
			//mlx_pixel_put(mlx->mlx,mlx->win,x_img,y_img,get_color(&sp->player_r[1],x,y));
		animation->control = 1;
	}		
}

void	print_player(t_mlx *mlx,t_sprites *sp,t_animation *animation)
{
	//t_data player;
	//t_data img_teste;
	int	x_img;
	int	y_img;
	int	x;
	int	y;
	
	x_img = mlx->x;
	y_img = mlx->y;
	x = 0;
	y = 0;

	// player.img = mlx_xpm_file_to_image(mlx->mlx,"./images/goku_stand_to_right.xpm",&player.pos_x,&player.pos_y);
	// player.addr = mlx_get_data_addr(player.img,&player.bpp,&player.l_len,&player.endian);

	// img_teste.img = mlx_new_image(mlx->mlx,40,40);
	// img_teste.addr = mlx_get_data_addr(img_teste.img,&img_teste.bpp,&img_teste.l_len,&img_teste.endian);

	ft_printf("",animation);
	while(x_img < (mlx->x + 40))
	{
		//mlx->y = 0;
		y_img = mlx->y;
		y=0;
		while(y_img < (mlx->y + 40))
		{
			//check_look(animation);
			if(get_color(&sp->player[animation->control],x,y) != 4278190080)
				mlx_pixel_put(mlx->mlx,mlx->win,x_img,y_img,get_color(&sp->player[animation->control],x,y));			
					//ft_mlx_pixel_put(img_teste.img,x,y,get_color(&sp->player,x,y));			
			y++;
			y_img++;
			//mlx->y++;
		}
		x++;
		x_img++;
		//mlx->x++;		
	}
	//mlx_put_image_to_window(mlx->mlx,mlx->win,img_teste.img,40,40);
}

void	fill_sprites(t_mlx *mlx, t_sprites *sprites)
{	
	sprites->floor.img = mlx_xpm_file_to_image(mlx->mlx,"./images/floor2.xpm",&sprites->floor.pos_x,&sprites->floor.pos_y);
	sprites->floor.addr = mlx_get_data_addr(sprites->floor.img,&sprites->floor.bpp,&sprites->floor.l_len,&sprites->floor.endian);

	sprites->wall.img = mlx_xpm_file_to_image(mlx->mlx,"./images/rock_wall.xpm",&sprites->wall.pos_x,&sprites->wall.pos_y);
	sprites->wall.addr = mlx_get_data_addr(sprites->wall.img,&sprites->wall.bpp,&sprites->wall.l_len,&sprites->wall.endian);

	sprites->player[1].img = mlx_xpm_file_to_image(mlx->mlx,"./images/goku_right_stand.xpm",&sprites->player[1].pos_x,&sprites->player[1].pos_y);
	sprites->player[1].addr = mlx_get_data_addr(sprites->player[1].img,&sprites->player[1].bpp,&sprites->player[1].l_len,&sprites->player[1].endian);	
	
	sprites->player[2].img = mlx_xpm_file_to_image(mlx->mlx,"./images/goku_right_left_leg.xpm",&sprites->player[2].pos_x,&sprites->player[2].pos_y);
	sprites->player[2].addr = mlx_get_data_addr(sprites->player[2].img,&sprites->player[2].bpp,&sprites->player[2].l_len,&sprites->player[2].endian);	
	
	sprites->player[3].img = mlx_xpm_file_to_image(mlx->mlx,"./images/goku_right_right_leg.xpm",&sprites->player[3].pos_x,&sprites->player[3].pos_y);
	sprites->player[3].addr = mlx_get_data_addr(sprites->player[3].img,&sprites->player[3].bpp,&sprites->player[3].l_len,&sprites->player[3].endian);	
}

void	sprite_print(t_mlx *mlx, t_mapinfo *map_info, t_sprites *sp,t_animation *animation)
{
	if (map_info->map[map_info->y_actual][map_info->x_actual] == '1')
		mlx_put_image_to_window(mlx->mlx,mlx->win,sp->wall.img,mlx->x,mlx->y);		
	else if (map_info->map[map_info->y_actual][map_info->x_actual] == '0')
		mlx_put_image_to_window(mlx->mlx,mlx->win,sp->floor.img,mlx->x,mlx->y);
	else if (map_info->map[map_info->y_actual][map_info->x_actual] == 'P')
	{
		mlx_put_image_to_window(mlx->mlx,mlx->win,sp->floor.img,mlx->x,mlx->y);
    	print_player(mlx,sp,animation);
	}
}