/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alachris <alachris@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 23:31:20 by alachris          #+#    #+#             */
/*   Updated: 2022/08/03 02:06:56 by alachris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	sprites_player_right(t_mlx *mlx, t_sprites *sprites)
{
	sprites->player[1].img = mlx_xpm_file_to_image(mlx->mlx,
			"./images/goku_right_stand.xpm", &sprites->player[1].pos_x,
			&sprites->player[1].pos_y);
	sprites->player[1].addr = mlx_get_data_addr(sprites->player[1].img,
			&sprites->player[1].bpp, &sprites->player[1].l_len,
			&sprites->player[1].endian);
	sprites->player[2].img = mlx_xpm_file_to_image(mlx->mlx,
			"./images/goku_right_left_leg.xpm", &sprites->player[2].pos_x,
			&sprites->player[2].pos_y);
	sprites->player[2].addr = mlx_get_data_addr(sprites->player[2].img,
			&sprites->player[2].bpp, &sprites->player[2].l_len,
			&sprites->player[2].endian);
	sprites->player[3].img = mlx_xpm_file_to_image(mlx->mlx,
			"./images/goku_right_right_leg.xpm", &sprites->player[3].pos_x,
			&sprites->player[3].pos_y);
	sprites->player[3].addr = mlx_get_data_addr(sprites->player[3].img,
			&sprites->player[3].bpp, &sprites->player[3].l_len,
			&sprites->player[3].endian);
}

void	sprites_player_left(t_mlx *mlx, t_sprites *sprites)
{
	sprites->player[4].img = mlx_xpm_file_to_image(mlx->mlx,
			"./images/goku_left_stand.xpm", &sprites->player[4].pos_x,
			&sprites->player[4].pos_y);
	sprites->player[4].addr = mlx_get_data_addr(sprites->player[4].img,
			&sprites->player[4].bpp, &sprites->player[4].l_len,
			&sprites->player[4].endian);
	sprites->player[5].img = mlx_xpm_file_to_image(mlx->mlx,
			"./images/goku_left_left_leg.xpm", &sprites->player[5].pos_x,
			&sprites->player[5].pos_y);
	sprites->player[5].addr = mlx_get_data_addr(sprites->player[5].img,
			&sprites->player[5].bpp, &sprites->player[5].l_len,
			&sprites->player[5].endian);
	sprites->player[6].img = mlx_xpm_file_to_image(mlx->mlx,
			"./images/goku_left_right_leg.xpm", &sprites->player[6].pos_x,
			&sprites->player[6].pos_y);
	sprites->player[6].addr = mlx_get_data_addr(sprites->player[6].img,
			&sprites->player[6].bpp, &sprites->player[6].l_len,
			&sprites->player[6].endian);
}

void	sprites_player_up(t_mlx *mlx, t_sprites *sprites)
{
	sprites->player[7].img = mlx_xpm_file_to_image(mlx->mlx,
			"./images/goku_up_stand.xpm", &sprites->player[7].pos_x,
			&sprites->player[7].pos_y);
	sprites->player[7].addr = mlx_get_data_addr(sprites->player[7].img,
			&sprites->player[7].bpp, &sprites->player[7].l_len,
			&sprites->player[7].endian);
	sprites->player[8].img = mlx_xpm_file_to_image(mlx->mlx,
			"./images/goku_up_left_leg.xpm", &sprites->player[8].pos_x,
			&sprites->player[8].pos_y);
	sprites->player[8].addr = mlx_get_data_addr(sprites->player[8].img,
			&sprites->player[8].bpp, &sprites->player[8].l_len,
			&sprites->player[8].endian);
	sprites->player[9].img = mlx_xpm_file_to_image(mlx->mlx,
			"./images/goku_up_right_leg.xpm", &sprites->player[9].pos_x,
			&sprites->player[9].pos_y);
	sprites->player[9].addr = mlx_get_data_addr(sprites->player[9].img,
			&sprites->player[9].bpp, &sprites->player[9].l_len,
			&sprites->player[9].endian);
}

void	sprites_player_down(t_mlx *mlx, t_sprites *sprites)
{
	sprites->player[10].img = mlx_xpm_file_to_image(mlx->mlx,
			"./images/goku_down_stand.xpm", &sprites->player[10].pos_x,
			&sprites->player[10].pos_y);
	sprites->player[10].addr = mlx_get_data_addr(sprites->player[10].img,
			&sprites->player[10].bpp, &sprites->player[10].l_len,
			&sprites->player[10].endian);
	sprites->player[11].img = mlx_xpm_file_to_image(mlx->mlx,
			"./images/goku_down_left_leg.xpm", &sprites->player[11].pos_x,
			&sprites->player[11].pos_y);
	sprites->player[11].addr = mlx_get_data_addr(sprites->player[11].img,
			&sprites->player[11].bpp, &sprites->player[11].l_len,
			&sprites->player[11].endian);
	sprites->player[12].img = mlx_xpm_file_to_image(mlx->mlx,
			"./images/goku_down_right_leg.xpm", &sprites->player[12].pos_x,
			&sprites->player[12].pos_y);
	sprites->player[12].addr = mlx_get_data_addr(sprites->player[12].img,
			&sprites->player[12].bpp, &sprites->player[12].l_len,
			&sprites->player[12].endian);
}
