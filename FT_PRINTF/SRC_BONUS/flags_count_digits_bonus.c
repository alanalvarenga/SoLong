/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_count_digits_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alachris <alachris@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 23:03:58 by alachris          #+#    #+#             */
/*   Updated: 2022/06/10 23:43:41 by alachris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	print_id(int n)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('2', 1);
		n = 147483648;
	}	
	if (n < 0)
	{		
		n = n * (-1);
	}			
	if (n > 9)
	{
		print_id(n / 10);
	}
	ft_putchar_fd((n % 10) + 48, 1);
}

void	count_int(t_vari **vari, int integer)
{
	int	count;
	int	size;

	size = 0;
	if (integer < 0)
	{
		size = 1;
		(*vari)->is_negative = 1;
	}
	count = integer / 10;
	size++;
	while (count != 0)
	{
		size++;
		count = count / 10;
	}
	(*vari)->numbers = (*vari)->numbers + size;
}

void	count_unsi(t_vari **vari, unsigned int unsi_int)
{
	int	count;
	int	size;

	size = 0;
	count = unsi_int / 10;
	size++;
	while (count != 0)
	{
		size++;
		count = count / 10;
	}
	(*vari)->numbers = (*vari)->numbers + size;
}

void	count_hexa(size_t n, t_vari **vari)
{
	if (n < 16)
	{		
		(*vari)->numbers++;
	}
	else
	{
		count_hexa(n / 16, vari);
		(*vari)->numbers++;
	}
}
