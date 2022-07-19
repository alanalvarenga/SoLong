/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alachris <alachris@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 20:01:29 by alachris          #+#    #+#             */
/*   Updated: 2022/07/16 22:25:58 by alachris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	size_rows(t_mapinfo *map_info)
{
	int	x;
	int	y;
	int	count_row;

	x = 0;
	count_row = map_info->columns;
	while (x < map_info->rows)
	{
		y = 0;		
		while (map_info->map[x][y] != '\0')
			y++;
		if(x < (map_info->rows - 1))
		{
			if ((y - 1) != count_row)			
				return (1);
		}
		else
		{
			if (y != count_row)
				return (1);
		}
		x++;
	}
	return (0);
}

int verify_size(t_mapinfo *map_info)
{
	if ((map_info->columns == 3) && (map_info->rows < 5))
		return (1);
	else if ((map_info->rows == 3) && (map_info->columns < 5))
		return (1);
	else if ((map_info->rows < 4) && (map_info->columns < 4))
		return (1);
	if (size_rows(map_info) == 1)
	{
		ft_printf("\nMapa com linha a menos ou a mais\n");
		return (1);
	}
	if (map_info->map[map_info->rows-1][0] == '\0')
	{
		ft_printf("\nMapa com coluna a mais\n");	
		return (1);
	}
	return (0);
}

int	verify_character(t_mapinfo *map_info)
{
	int	x;
	int	y;

	x = 0;
	while (x < map_info->rows)
	{
		y = 0;
		while (y < map_info->columns)
		{
			if (map_info->map[x][y] == 'P')
				map_info->p++;
			else if (map_info->map[x][y] == 'E')
				map_info->e++;
			else if (map_info->map[x][y] == 'C')
				map_info->c++;
			else if ((map_info->map[x][y] != '1')
				&& (map_info->map[x][y] != '0'))
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}
