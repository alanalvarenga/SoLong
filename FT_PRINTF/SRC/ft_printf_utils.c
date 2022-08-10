/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alachris <alachris@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 22:24:53 by alachris          #+#    #+#             */
/*   Updated: 2022/06/10 23:22:20 by alachris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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

void	ft_puthexa(unsigned long n, int c, t_vari **vari)
{
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
		ft_puthexa(n / 16, c, vari);
		ft_putchar_fd((*vari)->hextab[n % 16], 1);
		(*vari)->amount++;
	}
}

void	ft_puthexa_point(unsigned long n, t_vari **vari)
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
