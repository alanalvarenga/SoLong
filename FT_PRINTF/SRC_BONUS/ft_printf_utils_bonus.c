/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alachris <alachris@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 21:25:34 by alachris          #+#    #+#             */
/*   Updated: 2022/06/08 01:13:42 by alachris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	count_numbers(t_vari **vari, int integer)
{
	int	count;
	int	size;

	size = 0;
	if (integer < 0)
		size = 1;
	count = integer / 10;
	size++;
	while (count != 0)
	{
		size++;
		count = count / 10;
	}
	(*vari)->amount = (*vari)->amount + size;
}

void	count_unsi_numbers(t_vari **vari, unsigned int unsi_int)
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
	(*vari)->amount = (*vari)->amount + size;
}

void	ft_putnbr_unsi_fd(unsigned int n, int fd)
{
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	ft_putchar_fd((n % 10) + 48, fd);
}

void	ft_puthexa(size_t n, int c, t_vari **vari, t_flags *flags)
{	
	sharp_zero_x(n, c, vari, flags);
	if ((c == 'x') && (!(*vari)->hextab))
		(*vari)->hextab = ft_strdup("0123456789abcdef");
	else if ((c == 'X') && (!(*vari)->hextab))
		(*vari)->hextab = ft_strdup("0123456789ABCDEF");
	if (n < 16)
	{
		ft_putchar_fd((*vari)->hextab[n], 1);
		(*vari)->amount++;
	}
	else
	{
		ft_puthexa(n / 16, c, vari, flags);
		ft_putchar_fd((*vari)->hextab[n % 16], 1);
		(*vari)->amount++;
	}	
}

void	ft_puthexa_point(size_t n, t_vari **vari)
{
	if (!(*vari)->hextab)
		(*vari)->hextab = ft_strdup("0123456789abcdef");
	if (n < 16)
	{
		ft_putchar_fd((*vari)->hextab[n], 1);
		(*vari)->amount++;
	}
	else
	{
		ft_puthexa_point(n / 16, vari);
		ft_putchar_fd((*vari)->hextab[n % 16], 1);
		(*vari)->amount++;
	}
}
