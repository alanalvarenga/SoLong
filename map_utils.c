/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alachris <alachris@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 22:33:53 by alachris          #+#    #+#             */
/*   Updated: 2022/07/15 23:22:34 by alachris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int verify_wallsY(t_mapinfo *map_info)
{
	int	x;
	int	y;
	int	b;

	x = 0;
	y = 0;
	b = 0;
	while(b < 2)
	{
		x = 0;
		while(x < map_info->rows)
		{
			if (map_info->map[x][y] != '1')
			{
				ft_printf("\nParedes erradas linha\n");
				return (1);
			}
			x++;
		}	
		y = map_info->columns - 1;		
		b++;
	}
	return (0);
}

int verify_wallsX(t_mapinfo *map_info)
{
	int	x;
	int	y;
	int	b;

	x = 0;
	y = 0;
	b = 0;
	while(b < 2)
	{
		y = 0;
		while(y < map_info->columns)
		{
			if (map_info->map[x][y] != '1')
			{
				ft_printf("\nParedes erradas coluna\n");
				return (1);
			}
			y++;
		}
		x = map_info->rows - 1;
		b++;
	}
	return (0);
}

int valid_map(t_mapinfo *map_info)
{
	if (verify_size(map_info) == 1)
	{
		ft_printf("\nMapa tamanho errado\n");
		return (1);
	}
	if ((verify_wallsX(map_info)) || (verify_wallsY(map_info)))
		return (1);	
	if (verify_character(map_info) == 1)
	{
		ft_printf("\nCharacter especial diferente\n");
		return (1);
	}
	ft_printf("\nP: %d",map_info->p);
	ft_printf("\nC: %d",map_info->c);
	ft_printf("\nE: %d\n",map_info->e);
	if (map_info->p != 1)
		ft_printf("\nQuantidade de posição errada\n");
	if (map_info->c < 1)
		ft_printf("\nNão tem pelo menos 1 coletavel\n");
	if (map_info->e < 1)
		ft_printf("\nNão tem pelo menos 1 saída\n");
	if ((map_info->p != 1) || (map_info->c < 1) || (map_info->e < 1))
		return (1);
	return (0);
}

void	count_columns(t_mapinfo *map_info, char *str)
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
}

void	fill_map(t_mapinfo *map_info, char *argv[])
{
	int fd;
	int i;
	int count;	
	char *gnl;

	i = 1;
	fd = open(argv[1],O_RDONLY);
	gnl = get_next_line(fd);	
	while (gnl)
	{
		free(gnl);
		gnl = get_next_line(fd);
		i++;
	}	
	free(gnl);
	close(fd);
	map_info->rows = i-1;
	fd = open(argv[1],O_RDONLY);
	map_info->map = (char **)malloc(sizeof(char *) * (i + 1));
	count = 0;
	while(count < i)
		map_info->map[count++] = get_next_line(fd);
	close(fd);
	count_columns(map_info, map_info->map[0]);
}
