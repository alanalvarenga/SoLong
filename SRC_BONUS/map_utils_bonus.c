/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alachris <alachris@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 22:53:27 by alachris          #+#    #+#             */
/*   Updated: 2022/08/05 00:35:46 by alachris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong_bonus.h"

int	verify_walls_y(t_mapinfo *map_info)
{
	int	x;
	int	y;
	int	b;

	x = 0;
	y = 0;
	b = 0;
	while (b < 2)
	{
		x = 0;
		while (x < map_info->rows)
		{
			if (map_info->map[x][y] != '1')
			{
				ft_printf("Error\nWrong walls in rows\n");
				return (1);
			}
			x++;
		}	
		y = map_info->columns - 1;
		b++;
	}
	return (0);
}

int	verify_walls_x(t_mapinfo *map_info)
{
	int	x;
	int	y;
	int	b;

	x = 0;
	y = 0;
	b = 0;
	while (b < 2)
	{
		y = 0;
		while (y < map_info->columns)
		{
			if (map_info->map[x][y] != '1')
			{
				ft_printf("Error\nWrong walls in columns\n");
				return (1);
			}
			y++;
		}
		x = map_info->rows - 1;
		b++;
	}
	return (0);
}

int	valid_map(t_mapinfo *map_info)
{
	if (verify_size(map_info) == 1)
	{
		ft_printf("Error\nWrong map size\n");
		return (1);
	}
	if ((verify_walls_x(map_info)) || (verify_walls_y(map_info)))
		return (1);
	if (verify_character(map_info) == 1)
	{
		ft_printf("Error\nHave a characters special wrong\n");
		return (1);
	}	
	if (map_info->p != 1)
		ft_printf("Error\nDont have 1 position ou more than 1\n");
	if (map_info->c < 1)
		ft_printf("Error\nDont have at least 1 collectible\n");
	if (map_info->e < 1)
		ft_printf("Error\nDont have at least 1 exit\n");
	if (map_info->v < 1)
		ft_printf("Error\nDont have at least 1 enemy");
	if ((map_info->p != 1) || (map_info->c < 1) || (map_info->e < 1)
		|| (map_info->v < 1))
		return (1);
	return (0);
}

void	count_columns(t_mapinfo *map_info, t_animation *animation, char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	map_info->columns = count - 1;
	map_info->p = 0;
	map_info->c = 0;
	map_info->e = 0;
	map_info->v = 0;
	map_info->go_back = 0;
	map_info->got_colection = 0;
	animation->exit_block = 1;
	animation->exit_ok = 0;
	animation->play_up = 0;
	animation->play_down = 0;
	animation->play_right = 1;
	animation->play_left = 0;
	animation->moves = 0;
	animation->control = 1;
	animation->control_enemy = 1;
	animation->count = 0;
}

void	fill_map(t_mapinfo *map_info, t_animation *animation, char *argv[])
{
	int		fd;
	int		i;
	int		count;	
	char	*gnl;

	i = 1;
	fd = open(argv[1], O_RDONLY);
	gnl = get_next_line(fd);
	while (gnl)
	{
		free(gnl);
		gnl = get_next_line(fd);
		i++;
	}	
	free(gnl);
	close(fd);
	map_info->rows = i - 1;
	fd = open(argv[1], O_RDONLY);
	map_info->map = (char **)malloc(sizeof(char *) * (i + 1));
	count = 0;
	while (count < i)
		map_info->map[count++] = get_next_line(fd);
	close(fd);
	count_columns(map_info, animation, map_info->map[0]);
}
