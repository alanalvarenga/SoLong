/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alachris <alachris@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 22:02:57 by alachris          #+#    #+#             */
/*   Updated: 2022/06/10 23:44:52 by alachris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	sharp_zero_x(size_t n, int c, t_vari **vari, t_flags *flags)
{
	if ((flags)->sharp == 1)
	{
		if ((c == 'x') && (n != 0))
			write(1, "0x", 2);
		else if ((c == 'X') && (n != 0))
			write(1, "0X", 2);
		if (n != 0)
			(*vari)->amount = (*vari)->amount + 2;
		(flags)->sharp = 0;
	}
}

void	ft_free_null(char **ptr)
{
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
}

void	width_p(t_vari **vari, t_types *types)
{
	if (!types->unsi_long)
	{
		write(1, "(nil)", 5);
		(*vari)->amount = (*vari)->amount +5;
	}
	else
	{
		write(1, "0x", 2);
		ft_puthexa_point(types->unsi_long, vari);
		ft_free_null(&(*vari)->hextab);
		(*vari)->amount = (*vari)->amount + 2;
	}	
}

void	putstr_dot(t_vari **vari, char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		if ((*vari)->min <= 5)
			write(1, NULL, 1);
		else
		{
			write(1, "(null)", 6);
			(*vari)->amount = (*vari)->amount + 6;
		}
	}
	else if (s)
	{
		(*vari)->amount = (*vari)->amount + (*vari)->min;
		while ((*vari)->min > 0)
		{
			write(1, &s[i], 1);
			(*vari)->min--;
			i++;
		}
	}
}

void	dot_width_s(t_vari **vari, va_list print)
{
	int		i;
	t_types	types;

	ft_bzero(&types, sizeof(t_types));
	i = 0;
	(*vari)->aux = (*vari)->min_width - (*vari)->min;
	while ((*vari)->aux > 0)
	{
		write(1, " ", 1);
		(*vari)->aux--;
		(*vari)->amount++;
	}
	types.string = va_arg(print, char *);
	(*vari)->amount = (*vari)->amount + (*vari)->min;
	while ((*vari)->min > 0)
	{
		write(1, &types.string[i], 1);
		(*vari)->min--;
		i++;
	}
}
