/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_dot_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alachris <alachris@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 21:48:06 by alachris          #+#    #+#             */
/*   Updated: 2022/06/10 23:39:39 by alachris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	check_dot(const char *str, t_vari **vari, va_list print)
{
	t_types	types;
	t_flags	flags;

	ft_bzero(&flags, sizeof(t_flags));
	ft_bzero(&types, sizeof(t_types));
	(*vari)->min_width = (*vari)->min;
	(*vari)->i++;
	(*vari)->min = 0;
	(*vari)->n = 0;
	count_min_zero_neg(str, vari);
	(*vari)->i = (*vari)->i + (*vari)->n;
	if (str[(*vari)->i] == 's')
	{
		if ((*vari)->min >= (*vari)->min_width)
			do_dot(str, vari, print, &flags);
		else
			dot_width_s(vari, print);
	}
}

void	do_dot(const char *str, t_vari **vari,
			va_list print, t_flags *flags)
{
	t_types	types;

	ft_bzero(&types, sizeof(t_types));
	if (str[(*vari)->i] == 's')
	{
		types.string = va_arg(print, char *);
		if (!types.string)
			putstr_dot(vari, types.string);
		else if (((int)ft_strlen(types.string)) > ((*vari)->min))
			putstr_dot(vari, types.string);
		else
			flag_width_continue2(str, vari, &types, print);
	}
	else if (str[(*vari)->i] == 'i' || str[(*vari)->i] == 'd')
		putid_dot(str, vari, print, flags);
	else if (str[(*vari)->i] == 'u')
		putu_dot(str, vari, print, flags);
	else if ((str[(*vari)->i] == 'x') || (str[(*vari)->i] == 'X'))
	{
		do_dot_sharp(str, vari, print, flags);
	}
}

void	do_dot_sharp(const char *str, t_vari **vari,
			va_list print, t_flags *flags)
{
	if (((str[(*vari)->i] == 'x')) && (flags->sharp == 1))
		write(1, "0x", 2);
	else if (((str[(*vari)->i] == 'X')) && (flags->sharp == 1))
		write(1, "0X", 2);
	if (flags->sharp == 1)
		(*vari)->amount = (*vari)->amount + 2;
	putx_dot(str, vari, print, flags);
}

void	dot_comb_id(const char *str, t_vari **vari,
			va_list print, t_flags **flags)
{
	t_types	types;

	ft_bzero(&types, sizeof(t_types));
	types.integer = va_arg(print, int);
	if ((types.integer >= 0) && ((*flags)->positive == 1))
		write(1, "+", 1);
	else if (types.integer < 0)
		write(1, "-0", 2);
	else if ((*flags)->space == 1)
		write(1, " ", 1);
	(*vari)->amount++;
	(*vari)->i = (*vari)->i + 2;
	count_min_zero_neg(str, vari);
	(*vari)->i = (*vari)->i + (*vari)->n;
	count_int(vari, types.integer);
	flag_zero_continue(str, vari, &types, flags);
	(*vari)->i++;
}

void	flag_dot(const char *str, t_vari **vari,
			va_list print, t_flags **flags)
{
	t_types	types;

	ft_bzero(&types, sizeof(t_types));
	if ((str[(*vari)->i] == ' ') || (str[(*vari)->i] == '+'))
	{
		dot_comb_id(str, vari, print, flags);
	}
	else if (str[(*vari)->i] == '#')
		(*vari)->i++;
	else
	{
		(*vari)->i++;
		count_min_zero_neg(str, vari);
		(*vari)->i = (*vari)->i + (*vari)->n;
		do_dot(str, vari, print, *flags);
		(*vari)->i++;
	}
}
