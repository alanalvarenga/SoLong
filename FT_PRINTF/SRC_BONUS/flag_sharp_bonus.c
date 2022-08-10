/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_sharp_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alachris <alachris@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 21:08:52 by alachris          #+#    #+#             */
/*   Updated: 2022/06/10 23:36:12 by alachris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	flag_sharp(const char *str, t_vari **vari,
			va_list print, t_flags **flags)
{
	t_types	types;

	ft_bzero(&types, sizeof(t_types));
	if ((str[(*vari)->i] != 'x') && (str[(*vari)->i] != 'X'))
		(*vari)->i++;
	if (str[(*vari)->i] == '-')
		flag_negative(str, vari, print, flags);
	else if (str[(*vari)->i] == '0')
	{
		(*vari)->numbers = +2;
		flag_zero(str, vari, print, flags);
	}
	else if (str[(*vari)->i] == '.')
		flag_dot(str, vari, print, flags);
	else
	{		
		types.unsi_int = va_arg(print, unsigned int);
		ft_puthexa(types.unsi_int, str[(*vari)->i], vari, *flags);
		ft_free_null(&(*vari)->hextab);
		(*vari)->i++;
	}
}
