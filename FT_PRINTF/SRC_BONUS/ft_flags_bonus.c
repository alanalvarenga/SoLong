/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alachris <alachris@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 03:18:41 by alachris          #+#    #+#             */
/*   Updated: 2022/06/10 23:35:54 by alachris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	flag_positive(const char *str, t_vari **vari, va_list print)
{
	t_types	types;

	ft_bzero(&types, sizeof(t_types));
	(*vari)->i++;
	if (str[(*vari)->i] == '+')
	{
		while (str[(*vari)->i] == '+')
		{
			(*vari)->i++;
		}
	}
	if (str[(*vari)->i] == 'i' || str[(*vari)->i] == 'd')
	{
		types.integer = va_arg(print, int);
		if (types.integer >= 0)
		{
			write(1, "+", 1);
			(*vari)->amount++;
		}
		ft_putnbr_fd(types.integer, 1);
		count_numbers(vari, types.integer);
		(*vari)->i++;
	}
}

void	using_flags(const char *str, t_vari **vari,
			va_list print, t_flags *flags)
{
	(*vari)->min = 0;
	(*vari)->n = 0;
	(*vari)->numbers = 0;
	if ((flags->space == 0) && (flags->sharp == 1))
		flag_sharp(str, vari, print, &flags);
	else if (flags->negative == 1)
		flag_negative(str, vari, print, &flags);
	else if (flags->negative == 0 && flags->zero == 1)
	{
		flag_zero(str, vari, print, &flags);
		(*vari)->i++;
	}
	else if ((flags->zero == 0) && (flags->width == 1))
	{
		flag_width(str, vari, print, &flags);
		(*vari)->i++;
	}
	else if (flags->dot == 1)
		flag_dot(str, vari, print, &flags);
	else if (flags->space == 1)
		flag_space(str, vari, print);
	else if (flags->positive == 1)
		flag_positive(str, vari, print);
	ft_bzero(&flags, sizeof(t_flags));
}

void	is_flag(const char *str, t_vari **vari, va_list print)
{
	t_flags	flags;

	ft_bzero(&flags, sizeof(t_flags));
	while (!ft_isalpha(str[(*vari)->i + (*vari)->n]) && (flags.negative == 0)
		&& (flags.zero == 0) && (flags.width == 0)
		&& (flags.dot == 0))
	{
		if (str[(*vari)->i + (*vari)->n] == '-')
			flags.negative = 1;
		else if (str[(*vari)->i + (*vari)->n] == '0')
			flags.zero = 1;
		else if (str[(*vari)->i + (*vari)->n] == ' ')
			flags.space = 1;
		else if (str[(*vari)->i + (*vari)->n] == '#')
			flags.sharp = 1;
		else if (str[(*vari)->i + (*vari)->n] == '+')
			flags.positive = 1;
		else if (((ft_isdigit(str[(*vari)->i + (*vari)->n])) > 0)
			&& (str[(*vari)->i + (*vari)->n] != '0'))
			flags.width = 1;
		else if (str[(*vari)->i + (*vari)->n] == '.')
			flags.dot = 1;
		(*vari)->n++;
	}
	using_flags(str, vari, print, &flags);
}
