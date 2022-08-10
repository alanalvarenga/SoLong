/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_space_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alachris <alachris@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 21:41:11 by alachris          #+#    #+#             */
/*   Updated: 2022/06/10 23:42:41 by alachris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	print_numb_neg_space(t_vari **vari, va_list print)
{
	t_types	types;

	ft_bzero(&types, sizeof(t_types));
	types.integer = va_arg(print, int);
	if (types.integer >= 0)
	{
		write (1, " ", 1);
		(*vari)->amount++;
	}
	ft_putnbr_fd(types.integer, 1);
	count_numbers(vari, types.integer);
	(*vari)->i++;
}

void	space_continue(const char *str, t_vari **vari, va_list print)
{
	if ((str[(*vari)->i] == 'x') || (str[(*vari)->i] == 'X')
		|| (str[(*vari)->i] == '%') || (str[(*vari)->i] == 'c')
		|| (str[(*vari)->i] == 's') || (str[(*vari)->i] == 'u'))
	{
		no_flags(str, vari, print);
		(*vari)->i++;
	}
	else if (ft_isalpha(str[(*vari)->i]) > 0)
	{
		no_flags2(str, vari, print);
	}
}

void	check_spaces(const char *str, t_vari **vari)
{
	if (str[(*vari)->i] == ' ')
	{
		while (str[(*vari)->i] == ' ')
		{
			(*vari)->i++;
		}
	}
}

void	flag_space(const char *str, t_vari **vari, va_list print)
{
	t_types	types;

	ft_bzero(&types, sizeof(t_types));
	check_spaces(str, vari);
	if ((str[(*vari)->i] == 'i') || (str[(*vari)->i] == 'd'))
	{
		types.integer = va_arg(print, int);
		if (types.integer >= 0)
		{
			write (1, " ", 1);
			(*vari)->amount++;
		}
		ft_putnbr_fd(types.integer, 1);
		count_numbers(vari, types.integer);
		(*vari)->i = (*vari)->i + 1;
	}
	else if (str[(*vari)->i] == 'p')
	{
		write (1, " ", 1);
		(*vari)->amount++;
		ft_percent_p(vari, print);
		(*vari)->i = (*vari)->i + 1;
	}
	else
		space_continue(str, vari, print);
}
