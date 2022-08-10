/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_zero_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alachris <alachris@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 22:10:51 by alachris          #+#    #+#             */
/*   Updated: 2022/06/10 23:40:03 by alachris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	count_min_zero_neg(const char *str, t_vari **vari)
{
	while (!ft_isalpha(str[(*vari)->i + (*vari)->n])
		&& (str[(*vari)->i + (*vari)->n] != '.'))
	{
		if (str[(*vari)->i + (*vari)->n] != ' ')
		(*vari)->min = ((*vari)->min * 10)
				+ (str[(*vari)->i + (*vari)->n] - 48);
		(*vari)->n++;
		if (str[(*vari)->i + (*vari)->n] == '.')
			(*vari)->have_dot = 1;
	}
	if (str[(*vari)->i + (*vari)->n] == '.')
		(*vari)->have_dot = 1;
	else
		(*vari)->have_dot = 0;
}

void	count_digits(const char *str, t_vari **vari,
	va_list print, t_types *types)
{			
	(*vari)->is_negative = 0;
	if (str[(*vari)->i] == 'i' || str[(*vari)->i] == 'd')
	{
		types->integer = va_arg(print, int);
		count_int(vari, types->integer);
		if ((str[(*vari)->i - (*vari)->n] == ' ')
			|| (str[(*vari)->i - (*vari)->n] == '+'))
		{
			if ((*vari)->is_negative == 1)
				write(1, "-", 1);
		}		
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
}

void	flag_zero_continue(const char *str, t_vari **vari,
			t_types *types, t_flags **flags)
{
	(*vari)->aux = (*vari)->min - (*vari)->numbers;
	if ((*vari)->aux > 0)
	{
		while ((*vari)->aux > 0)
		{
			write(1, "0", 1);
			(*vari)->aux--;
			(*vari)->amount++;
		}
	}
	if (str[(*vari)->i] == 'i' || str[(*vari)->i] == 'd')
	{		
		print_id(types->integer);
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

void	flag_zero(const char *str, t_vari **vari,
			va_list print, t_flags **flags)
{	
	t_types	types;

	ft_bzero(&types, sizeof(t_types));
	if ((str[(*vari)->i - (*vari)->n] == ' ')
		|| (str[(*vari)->i - (*vari)->n] == '+'))
		(*vari)->n = 1;
	count_min_zero_neg(str, vari);
	(*vari)->i = (*vari)->i + (*vari)->n;
	count_digits(str, vari, print, &types);
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
	else if (types.integer < 0)
		write(1, "-", 1);
	flag_zero_continue(str, vari, &types, flags);
}
