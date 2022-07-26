/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alachris <alachris@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 21:10:26 by alachris          #+#    #+#             */
/*   Updated: 2022/07/26 01:30:09 by alachris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H
# define ESC 65307

# include "./FT_PRINTF/ft_printf.h"
# include "./GNL/get_next_line.h"
# include "./LibMLX/mlx.h"
# include <fcntl.h> // open, close
# include <stdlib.h>

typedef struct s_mapinfo
{
	int	rows;
	int	columns;
	int	p;
	int	c;
	int	e;	
	int	got_colection;
	int	x_actual;
	int	y_actual;
	int	play_x;
	int	play_y;
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
}        t_mlx;

typedef struct s_img
{
	void	*img_floor;
	void	*img_wall;
	void	*img_exit0;
	void	*img_exit1;
	void	*img_play_r[3];
	void	*img_play_l[3];
	void	*img_play_u[3];
	void	*img_play_d[3];
}	t_img;


typedef struct s_data
{
    void    *img;
    char    *addr;
    int        bpp;
    int        l_len;
    int        endian;
    int		pos_x;
	int		pos_y;
}            t_data;

typedef struct s_sprites
{
	t_data	floor;
	t_data	wall;
	t_data	player[12];
	t_data	player_l[3];
	t_data	player_u[3];
	t_data	player_d[3];
}	t_sprites;


typedef struct s_global
{
	t_mlx		mlx_d;
	t_mapinfo	map_info;
	t_data		data;
	t_sprites	sprites;
	t_animation	animation;
}	t_global;


void			fill_map(t_mapinfo *map_info,t_animation *animation, char *argv[]);
void			count_columns(t_mapinfo *map_info, t_animation *animation, char *str);
int				valid_map(t_mapinfo *map_info);
int				verify_wallsX(t_mapinfo *map_info);
int				verify_wallsY(t_mapinfo *map_info);
int				verify_character(t_mapinfo *map_info);
int				verify_size(t_mapinfo *map_info);
int				size_rows(t_mapinfo *map_info);
unsigned int	get_color(t_data *data, int x, int y);
void			render_window(t_global *global);
void			print_player(t_mlx *mlx,t_sprites *sp,t_animation *animation);
int				render_map(t_mlx *mlx, t_mapinfo *map_info, t_sprites *sprites,t_animation *animation);
void			sprite_print(t_mlx *mlx, t_mapinfo *map_info, t_sprites *sp,t_animation *animation);
int				action_loop(t_global *global);
void			ft_mlx_pixel_put(t_data *img_data, int x, int y, int color);
void			fill_sprites(t_mlx *mlx, t_sprites *sprites);
void			move_player(int key,t_global *global);
void			move_up(t_mapinfo *map_info);
void			move_down(t_mapinfo *map_info);
void			move_left(t_mapinfo *map_info);
void			move_right(t_mapinfo *map_info,t_animation *animation);


#endif