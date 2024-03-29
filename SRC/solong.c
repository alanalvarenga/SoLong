/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alachris <alachris@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 21:29:43 by alachris          #+#    #+#             */
/*   Updated: 2022/08/09 21:58:21 by alachris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	valid_extension(char *str)
{
	size_t	size;

	size = ft_strlen(str) - 4;
	if (ft_strncmp(".ber", str + size, 5) != 0)
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{	
	t_global	global;

	if (argc != 2)
	{
		ft_printf("Error\nParams Wrong\n");
		return (1);
	}
	if (valid_extension(argv[1]) == 1)
	{
		ft_printf("Error\nWrong Extension\n");
		return (1);
	}
	fill_map(&global.map_info, &global.animation, argv);
	if (valid_map(&global.map_info) == 1)
	{
		ft_printf("Error\nWrong map\n");
		free_map(&global.map_info);
		return (1);
	}
	render_window(&global);
	return (0);
}
