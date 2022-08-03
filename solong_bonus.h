/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alachris <alachris@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 22:55:54 by alachris          #+#    #+#             */
/*   Updated: 2022/08/04 00:29:16 by alachris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_BONUS_H
# define SOLONG_BONUS_H
# define ESC 65307
# define EXIT 17

# include "./FT_PRINTF/ft_printf.h"
# include "./GNL/get_next_line.h"
# include "./LibMLX/mlx.h"
# include <fcntl.h> // open, close
# include <stdlib.h>

typedef struct s_mapinfo
{
	int		rows;
	int		columns;
	int		p;
	int		c;
	int		e;
	int		v;
	int		got_colection;
	int		x_actual;
	int		y_actual;
	int		play_x;
	int		play_y;
	char	**map;
}	t_mapinfo;

typedef struct s_animation
{
	int	play_up;
	int	play_down;
	int	play_right;
	int	play_left;
	int	exit_block;
	int	exit_ok;
	int	moves;	
	int	control;
	int	count;
}	t_animation;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	int		y;
	int		x;
}	t_mlx;

typedef struct s_data
{
	void	*img;
	void	*addr;
	int		bpp;
	int		l_len;
	int		endian;
	int		pos_x;
	int		pos_y;
}	t_data;

typedef struct s_sprites
{
	t_data	floor;
	t_data	wall;
	t_data	collec;
	t_data	exit;
	t_data	player[13];
	t_data	enemy[4];
}	t_sprites;

typedef struct s_global
{
	t_mlx		mlx_d;
	t_mapinfo	map_info;
	t_data		data;
	t_sprites	sprites;
	t_animation	animation;
}	t_global;

void			fill_map(t_mapinfo *map_info, t_animation *animation,
					char *argv[]);
void			count_columns(t_mapinfo *map_info, t_animation *animation,
					char *str);
int				valid_map(t_mapinfo *map_info);
int				verify_walls_x(t_mapinfo *map_info);
int				verify_walls_y(t_mapinfo *map_info);
int				verify_character(t_mapinfo *map_info);
int				verify_size(t_mapinfo *map_info);
int				size_rows(t_mapinfo *map_info);
unsigned int	get_color(t_data *data, int x, int y);
void			render_window(t_global *global);
void			print_player(t_mlx *mlx, t_sprites *sp, t_animation *animation);
int				render_map(t_mlx *mlx, t_mapinfo *map_info, t_sprites *sprites,
					t_animation *animation);
void			sprite_print(t_mlx *mlx, t_mapinfo *map_info, t_sprites *sp,
					t_animation *animation);
int				action_loop(t_global *global);
void			fill_sprites(t_mlx *mlx, t_sprites *sprites);
void			move_player(int key, t_global *global);
void			move_up(t_mapinfo *map_info, t_animation *animation,
					t_global *global);
void			move_down(t_mapinfo *map_info, t_animation *animation,
					t_global *global);
void			move_left(t_mapinfo *map_info, t_animation *animation,
					t_global *global);
void			move_right(t_mapinfo *map_info, t_animation *animation,
					t_global *global);
void			animation_player(t_global *global);
void			animation_left(t_global *global);
void			animation_up(t_global *global);
void			animation_down(t_global *global);
int				close_game(t_global *global);
void			free_map(t_mapinfo *map_info);
void			free_images(t_global *global);
void			free_images_player(t_global *global);
void			free_mlx(t_global *global);
void			sprites_player_right(t_mlx *mlx, t_sprites *sprites);
void			sprites_player_left(t_mlx *mlx, t_sprites *sprites);
void			sprites_player_up(t_mlx *mlx, t_sprites *sprites);
void			sprites_player_down(t_mlx *mlx, t_sprites *sprites);
void			save_play_info(t_mapinfo *map_info, int x, int y);

#endif