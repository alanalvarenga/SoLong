/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils3_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alachris <alachris@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 23:29:58 by alachris          #+#    #+#             */
/*   Updated: 2022/06/10 23:57:52 by alachris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	putid_dot(const char *str, t_vari **vari,
			va_list print, t_flags *flags)
{
	t_types	types;

	ft_bzero(&types, sizeof(t_types));
	types.integer = va_arg(print, int);
	count_int(vari, types.integer);
	if ((((*vari)->min) == 0) && (types.integer == 0))
		write(1, NULL, 1);
	else if (((*vari)->numbers) <= ((*vari)->min))
	{
		if ((types.integer) < 0)
		{
			write(1, "-", 1);
			(*vari)->min++;
		}
		flag_zero_continue(str, vari, &types, &flags);
	}
	else
	{
		ft_putnbr_fd(types.integer, 1);
		count_numbers(vari, types.integer);
	}
}

void	putu_dot(const char *str, t_vari **vari,
			va_list print, t_flags *flags)
{
	t_types	types;

	ft_bzero(&types, sizeof(t_types));
	types.unsi_int = va_arg(print, unsigned int);
	count_unsi(vari, types.unsi_int);
	if ((((*vari)->min) == 0) && (types.unsi_int == 0))
		write(1, NULL, 1);
	else if (((*vari)->numbers) < ((*vari)->min))
	{
		flag_zero_continue(str, vari, &types, &flags);
	}
	else
	{
		if (((*vari)->min == 0) && (types.unsi_int == 0))
		{
			write(1, "", 1);
		}
		else
		{
			ft_putnbr_unsi_fd(types.unsi_int, 1);
			count_unsi_numbers(vari, types.unsi_int);
		}
	}
}

void	putx_dot(const char *str, t_vari **vari,
			va_list print, t_flags *flags)
{
	t_types	types;

	ft_bzero(&types, sizeof(t_types));
	types.unsi_int = va_arg(print, unsigned int);
	flags->sharp = 0;
	count_hexa(types.unsi_int, vari);
	if ((((*vari)->min) == 0) && (types.unsi_int == 0))
		write(1, NULL, 1);
	else if (((*vari)->numbers) < ((*vari)->min))
	{
		flag_zero_continue(str, vari, &types, &flags);
	}
	else
	{
		ft_puthexa(types.unsi_int, str[(*vari)->i], vari, flags);
		ft_free_null(&(*vari)->hextab);
	}
}
