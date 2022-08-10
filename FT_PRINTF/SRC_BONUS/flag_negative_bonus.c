/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_negative_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alachris <alachris@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 21:22:26 by alachris          #+#    #+#             */
/*   Updated: 2022/06/10 23:31:34 by alachris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	negative_continue3(const char *str, t_vari **vari,
						va_list print, t_flags **flags)
{
	t_types	types;

	ft_bzero(&types, sizeof(t_types));
	(*vari)->n = 1;
	count_min_zero_neg(str, vari);
	(*vari)->i = (*vari)->i + (*vari)->n;
	no_flags(str, vari, print);
	(*vari)->aux = (*vari)->amount - (*vari)->amount_current;
	if ((*vari)->min > (*vari)->aux)
	{
		if ((*flags)->sharp == 1)
				(*vari)->aux = (*vari)->aux + 2;
		while ((*vari)->aux++ < (*vari)->min)
		{
			write(1, " ", 1);
			(*vari)->amount++;
		}
	}
	(*vari)->i++;
}

void	negative_continue2(const char *str, t_vari **vari,
						va_list print, t_flags **flags)
{	
	(*vari)->n = 0;
	if (str[(*vari)->i] == ' ')
	{
		while (str[(*vari)->i + (*vari)->n] == ' ')
		{
			(*vari)->n++;
		}
	}
	if (str[(*vari)->i] == '+')
		(*vari)->n++;
	if ((str[(*vari)->i + (*vari)->n] == '-')
		&& (str[(*vari)->i + (*vari)->n + 1] == ' '))
	{
		(*vari)->n++;
		while (str[(*vari)->i + (*vari)->n] == ' ')
		{
			(*vari)->n++;
		}	
		(*vari)->i = (*vari)->i + (*vari)->n - 2;
		(*flags)->negative = 2;
		negative_continue(str, vari, print, flags);
	}		
	else
		negative_continue3(str, vari, print, flags);
}

void	negative_continue(const char *str, t_vari **vari,
					va_list print, t_flags **flags)
{
	if (((str[(*vari)->i] == ' ') && (str[(*vari)->i + 1] == '-')
			&& (str[(*vari)->i + 2] != ' ')) || ((*flags)->negative == 2))
	{
		(*vari)->i++;
		(*vari)->n = 1;
		count_min_zero_neg(str, vari);
		(*vari)->i = (*vari)->i + (*vari)->n;
		print_numb_neg_space(vari, print);
		(*vari)->aux = (*vari)->amount - (*vari)->amount_current;
		if ((*vari)->min > (*vari)->aux)
		{
			if ((*flags)->sharp == 1)
				(*vari)->aux = (*vari)->aux + 2;
			while ((*vari)->aux++ < (*vari)->min)
			{
				write(1, " ", 1);
				(*vari)->amount++;
			}
		}
	}
	else
		negative_continue2(str, vari, print, flags);
}

void	flag_negative(const char *str, t_vari **vari,
			va_list print, t_flags **flags)
{	
	(*vari)->amount_current = (*vari)->amount;
	if ((str[(*vari)->i - 1] == '%') && (str[(*vari)->i] == '-')
		&& (str[(*vari)->i + 1] == ' ') && (str[(*vari)->i + 2] != ' '))
	{
		(*vari)->n = 2;
		count_min_zero_neg(str, vari);
		(*vari)->i = (*vari)->i + (*vari)->n - 1;
		flag_space(str, vari, print);
		(*vari)->aux = (*vari)->amount - (*vari)->amount_current;
		if ((*vari)->min > (*vari)->aux)
		{
			if ((*flags)->sharp == 1)
				(*vari)->aux = (*vari)->aux + 2;
			while ((*vari)->aux++ < (*vari)->min)
			{
				write(1, " ", 1);
				(*vari)->amount++;
			}
		}
	}
	else
		negative_continue(str, vari, print, flags);
}
