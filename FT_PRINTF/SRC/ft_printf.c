/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alachris <alachris@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 22:24:48 by alachris          #+#    #+#             */
/*   Updated: 2022/06/10 23:23:23 by alachris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_percent_p(t_vari **vari, va_list print)
{
	t_types	types;

	ft_bzero(&types, sizeof(t_types));
	types.unsi_long = va_arg(print, unsigned long);
	if (!types.unsi_long)
	{
		write(1, "(nil)", 5);
		(*vari)->amount = (*vari)->amount +5;
	}
	else
	{
		write(1, "0x", 2);
		ft_puthexa_point(types.unsi_long, vari);
		ft_free_null(&(*vari)->hextab);
		(*vari)->amount = (*vari)->amount + 2;
	}
}

void	no_flags2(const char *str, t_vari **vari, va_list print)
{
	t_types	types;

	ft_bzero(&types, sizeof(t_types));
	if (str[(*vari)->i] == 'u')
	{
		types.unsi_int = va_arg(print, unsigned int);
		ft_putnbr_unsi_fd(types.unsi_int, 1);
		count_unsi_numbers(vari, types.unsi_int);
	}
	else if ((str[(*vari)->i] == 'x') || (str[(*vari)->i] == 'X'))
	{
		types.unsi_int = va_arg(print, unsigned int);
		ft_puthexa(types.unsi_int, str[(*vari)->i], vari);
		ft_free_null(&(*vari)->hextab);
	}
	else if (str[(*vari)->i] == 'p')
		ft_percent_p(vari, print);
	else
	{
		write (1, "%", 1);
		(*vari)->i--;
	}
}

void	no_flags(const char *str, t_vari **vari, va_list print)
{
	t_types	types;

	ft_bzero(&types, sizeof(t_types));
	if (str[(*vari)->i] == 's')
	{
		types.string = va_arg(print, char *);
		if (!types.string)
			types.string = "(null)";
		ft_putstr_fd(types.string, 1);
		(*vari)->amount = (*vari)->amount + ft_strlen(types.string);
	}
	else if (str[(*vari)->i] == 'c')
	{
		types.character = va_arg(print, int);
		ft_putchar_fd(types.character, 1);
		(*vari)->amount++;
	}
	else if (str[(*vari)->i] == 'i' || str[(*vari)->i] == 'd')
	{
		types.integer = va_arg(print, int);
		ft_putnbr_fd(types.integer, 1);
		count_numbers(vari, types.integer);
	}
	else
		no_flags2(str, vari, print);
}

void	verify(const char *str, t_vari *vari, va_list print)
{
	if (ft_isalpha(str[vari->i]) > 0)
	{
		no_flags(str, &vari, print);
		vari->i++;
	}
	else if (str[vari->i] == '%')
	{
		write (1, "%", 1);
		vari->i++;
		vari->amount++;
	}	
}

int	ft_printf(const char *str, ...)
{
	t_vari	vari;
	va_list	print;

	va_start(print, str);
	ft_bzero(&vari, sizeof(t_vari));
	while (str[vari.i] != '\0')
	{
		if (str[vari.i] == '%')
		{
			vari.i++;
			verify(str, &vari, print);
		}
		else
		{
			write (1, &str[vari.i], 1);
			vari.i++;
			vari.amount++;
		}
	}
	va_end(print);
	return (vari.amount);
}
