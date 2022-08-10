/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_width_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alachris <alachris@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 01:04:27 by alachris          #+#    #+#             */
/*   Updated: 2022/06/10 23:38:29 by alachris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	count_dig_wid_sp(const char *str, t_vari **vari,
			va_list print, t_types *types)
{
	if (str[(*vari)->i] == 's')
	{
		types->string = va_arg(print, char *);
		if (types->string)
			(*vari)->numbers = (*vari)->numbers + ft_strlen(types->string);
		else
			(*vari)->numbers = (*vari)->numbers + 6;
	}
	else if (str[(*vari)->i] == 'c')
	{
		types->character = va_arg(print, int);
		(*vari)->numbers++;
		(*vari)->amount++;
	}
	else if (str[(*vari)->i] == 'p')
	{
		types->unsi_long = va_arg(print, unsigned long);
		if (!types->unsi_long)
			(*vari)->numbers = (*vari)->numbers + 5;
		else
		{
			(*vari)->numbers = (*vari)->numbers + 2;
			count_hexa(types->unsi_long, vari);
		}
	}
}

void	count_digits_width(const char *str, t_vari **vari,
			va_list print, t_types *types)
{			
	(*vari)->is_negative = 0;
	if (str[(*vari)->i] == 'i' || str[(*vari)->i] == 'd')
	{
		types->integer = va_arg(print, int);
		count_int(vari, types->integer);
	}
	else if (str[(*vari)->i] == 'u')
	{
		types->unsi_int = va_arg(print, unsigned int);
		count_unsi(vari, types->unsi_int);
	}
	else if ((str[(*vari)->i] == 'x') || (str[(*vari)->i] == 'X'))
	{
		types->unsi_int = va_arg(print, unsigned int);
		count_hexa(types->unsi_int, vari);
	}
	else
		count_dig_wid_sp(str, vari, print, types);
}

void	flag_width_continue2(const char *str, t_vari **vari,
			t_types *types, va_list print)
{	
	if (str[(*vari)->i] == 's')
	{
		if (!types->string)
			types->string = "(null)";
		ft_putstr_fd(types->string, 1);
		(*vari)->amount = (*vari)->amount + ft_strlen(types->string);
	}
	else if (str[(*vari)->i] == 'c')
		ft_putchar_fd(types->character, 1);
	else if (str[(*vari)->i] == 'p')
		width_p(vari, types);
	else if (str[(*vari)->i] == '.')
		check_dot(str, vari, print);
}

void	flag_width_continue(const char *str, t_vari **vari,
			t_types *types, t_flags **flags)
{
	(*vari)->aux = (*vari)->min - (*vari)->numbers;
	if ((*vari)->aux > 0)
	{
		while (((*vari)->aux > 0) && ((*vari)->have_dot == 0))
		{
			write(1, " ", 1);
			(*vari)->aux--;
			(*vari)->amount++;
		}
	}
	if (str[(*vari)->i] == 'i' || str[(*vari)->i] == 'd')
	{		
		ft_putnbr_fd(types->integer, 1);
		count_numbers(vari, types->integer);
	}
	else if ((str[(*vari)->i] == 'x') || (str[(*vari)->i] == 'X'))
	{
		ft_puthexa(types->unsi_int, str[(*vari)->i], vari, *flags);
		ft_free_null(&(*vari)->hextab);
	}
	else if (str[(*vari)->i] == 'u')
	{
		ft_putnbr_unsi_fd(types->unsi_int, 1);
		count_unsi_numbers(vari, types->unsi_int);
	}	
}

void	flag_width(const char *str, t_vari **vari,
			va_list print, t_flags **flags)
{	
	t_types	types;

	ft_bzero(&types, sizeof(t_types));
	if ((str[(*vari)->i - (*vari)->n] == ' ')
		|| (str[(*vari)->i - (*vari)->n] == '+'))
		(*vari)->n = 1;
	count_min_zero_neg(str, vari);
	(*vari)->i = (*vari)->i + (*vari)->n;
	count_digits_width(str, vari, print, &types);
	if ((str[(*vari)->i - (*vari)->n] == ' ')
		|| (str[(*vari)->i - (*vari)->n] == '+'))
	{
		if ((*vari)->is_negative == 0)
		{
			if ((*flags)->positive == 0)
				write(1, " ", 1);
			else if ((*flags)->positive == 1)
				write(1, "+", 1);
			(*vari)->min--;
			(*vari)->amount++;
		}
	}
	flag_width_continue(str, vari, &types, flags);
	flag_width_continue2(str, vari, &types, print);
}
