/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alachris <alachris@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 22:33:49 by alachris          #+#    #+#             */
/*   Updated: 2022/07/18 23:03:55 by alachris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h> // APAGAR-------------
#include "solong.h"

//PRIMEIRO OPEN-- CHAMAR READ PARA CONTAR QUANTOS \N PRA SABER QUANTIDADE DE LINHAS
//FAZER MALLOC NO PONTEIRO DUPLO E CHAMAR GNL
//CHAMAR GNL PARA CADA PONTEIRO DUPLO E VALIDAR OS CARACTERES

//PRIMEIRA VALIDAÇÃO - MAPA RETANGULO
//MAPA FECHADO BORDAS

void    ft_mlx_pixel_put(t_data *img_data, int x, int y, int color)
{
    char    *dst;

    dst = img_data->addr + (y * img_data->l_len + x * (img_data->bpp / 8));
    *(unsigned int *)dst = color;
}

int main( int argc, char *argv[])
{	
	t_mapinfo map_info;
	
			
	if (argc != 2)
	{
		ft_printf("Parametros errado");
		//return (1);
	}
	fill_map(&map_info,argv);	
	if (valid_map(&map_info) == 1)
	{
		ft_printf("\nmapa errado\n");
		//return (1);
	}
	render_window(&map_info);
	//ft_printf("\n\n");
	//ft_printf("%d\n",map_info.columns);
	// while(map_info.map[count])
	//  	ft_printf("%s",map_info.map[count++]);
	// ft_printf("\n\n");

	return (0);
}