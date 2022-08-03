/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_play_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alachris <alachris@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 22:51:12 by alachris          #+#    #+#             */
/*   Updated: 2022/08/04 00:18:51 by alachris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong_bonus.h"

void	animation_left(t_global *global)
{
	if (global->animation.count >= 0 && global->animation.count <= 150)
		global->animation.control = 4;
	else if (global->animation.count >= 151 && global->animation.count <= 300)
		global->animation.control = 5;
	else if (global->animation.count >= 301 && global->animation.count <= 450)
		global->animation.control = 4;
	else if (global->animation.count >= 451 && global->animation.count <= 600)
		global->animation.control = 6;
	else if (global->animation.count >= 601)
		global->animation.count = 0;
}

void	animation_up(t_global *global)
{
	if (global->animation.count >= 0 && global->animation.count <= 150)
		global->animation.control = 7;
	else if (global->animation.count >= 151 && global->animation.count <= 300)
		global->animation.control = 8;
	else if (global->animation.count >= 301 && global->animation.count <= 450)
		global->animation.control = 7;
	else if (global->animation.count >= 451 && global->animation.count <= 600)
		global->animation.control = 9;
	else if (global->animation.count >= 601)
		global->animation.count = 0;
}

void	animation_down(t_global *global)
{
	if (global->animation.count >= 0 && global->animation.count <= 150)
		global->animation.control = 10;
	else if (global->animation.count >= 151 && global->animation.count <= 300)
		global->animation.control = 11;
	else if (global->animation.count >= 301 && global->animation.count <= 450)
		global->animation.control = 10;
	else if (global->animation.count >= 451 && global->animation.count <= 600)
		global->animation.control = 12;
	else if (global->animation.count >= 601)
		global->animation.count = 0;
}

void	animation_player(t_global *global)
{
	global->animation.count++;
	if (global->animation.play_right == 1)
	{
		if (global->animation.count >= 0 && global->animation.count <= 150)
			global->animation.control = 1;
		else if ((global->animation.count >= 151)
			&& (global->animation.count <= 300))
				global->animation.control = 2;
		else if ((global->animation.count >= 301)
			&& (global->animation.count <= 450))
				global->animation.control = 1;
		else if ((global->animation.count >= 451)
			&& (global->animation.count <= 600))
				global->animation.control = 3;
		else if (global->animation.count >= 601)
			global->animation.count = 0;
	}
	else if (global->animation.play_left == 1)
		animation_left(global);
	else if (global->animation.play_up == 1)
		animation_up(global);
	else if (global->animation.play_down == 1)
		animation_down(global);
}
