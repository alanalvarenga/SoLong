/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alachris <alachris@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 21:10:26 by alachris          #+#    #+#             */
/*   Updated: 2022/07/19 21:06:35 by alachris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

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
	int	x_actual;
	int	y_actual;
	char	**map;
}	t_mapinfo;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
    int		y;
    int		x;
}        t_mlx;

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

void	fill_map(t_mapinfo *map_info, char *argv[]);
void	count_columns(t_mapinfo *map_info, char *str);
int		valid_map(t_mapinfo *map_info);
int		verify_wallsX(t_mapinfo *map_info);
int		verify_wallsY(t_mapinfo *map_info);
int		verify_character(t_mapinfo *map_info);
int		verify_size(t_mapinfo *map_info);
int		size_rows(t_mapinfo *map_info);
void	render_window(t_mapinfo *map_info);
void	print_player(t_mlx *mlx);
int		render_map(t_mlx *mlx, t_mapinfo *map_info);

#endif