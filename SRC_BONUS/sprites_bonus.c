/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alachris <alachris@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 22:54:58 by alachris          #+#    #+#             */
/*   Updated: 2022/08/04 00:19:31 by alachris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong_bonus.h"

unsigned int	get_color(t_data *data, int x, int y)
{
	char	*color;

	color = data->addr + (y * data->l_len + x * (data->bpp / 8));
	return (*(unsigned int *)color);
}

void	print_player(t_mlx *mlx, t_sprites *sp, t_animation *animation)
{
	int	x_img;
	int	y_img;
	int	x;
	int	y;

	x_img = mlx->x;
	y_img = mlx->y;
	x = 0;
	y = 0;
	while (x_img < (mlx->x + 40))
	{
		y_img = mlx->y;
		y = 0;
		while (y_img < (mlx->y + 40))
		{
			if (get_color(&sp->player[animation->control], x, y) != 4278190080)
				mlx_pixel_put(mlx->mlx, mlx->win, x_img, y_img,
					get_color(&sp->player[animation->control], x, y));
			y++;
			y_img++;
		}
		x++;
		x_img++;
	}
}

void	fill_sprites(t_mlx *mlx, t_sprites *sprites)
{	
	sprites->floor.img = mlx_xpm_file_to_image(mlx->mlx, "./images/floor.xpm",
			&sprites->floor.pos_x, &sprites->floor.pos_y);
	sprites->wall.img = mlx_xpm_file_to_image(mlx->mlx,
			"./images/rock_wall.xpm", &sprites->wall.pos_x,
			&sprites->wall.pos_y);
	sprites->collec.img = mlx_xpm_file_to_image(mlx->mlx,
			"./images/dragon_ball_sphere.xpm", &sprites->collec.pos_x,
			&sprites->collec.pos_y);
	sprites->exit.img = mlx_xpm_file_to_image(mlx->mlx,
			"./images/shenlong.xpm", &sprites->exit.pos_x,
			&sprites->exit.pos_y);
	sprites_player_right(mlx, sprites);
	sprites_player_left(mlx, sprites);
	sprites_player_up(mlx, sprites);
	sprites_player_down(mlx, sprites);
}

void	sprite_print(t_mlx *mlx, t_mapinfo *map_info, t_sprites *sprites,
					t_animation *animation)
{
	if (map_info->map[map_info->y_actual][map_info->x_actual] == '1')
		mlx_put_image_to_window(mlx->mlx, mlx->win, sprites->wall.img, mlx->x,
			mlx->y);
	else if (map_info->map[map_info->y_actual][map_info->x_actual] == '0')
		mlx_put_image_to_window(mlx->mlx, mlx->win, sprites->floor.img, mlx->x,
			mlx->y);
	else if (map_info->map[map_info->y_actual][map_info->x_actual] == 'C')
		mlx_put_image_to_window(mlx->mlx, mlx->win, sprites->collec.img, mlx->x,
			mlx->y);
	else if ((map_info->map[map_info->y_actual][map_info->x_actual] == 'E')
		&& (map_info->got_colection != map_info->c))
		mlx_put_image_to_window(mlx->mlx, mlx->win, sprites->exit.img, mlx->x,
			mlx->y);
	else if (map_info->map[map_info->y_actual][map_info->x_actual] == 'P')
	{		
		mlx_put_image_to_window(mlx->mlx, mlx->win, sprites->floor.img,
			mlx->x, mlx->y);
		print_player(mlx, sprites, animation);
	}
}
