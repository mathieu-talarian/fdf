/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_calcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 16:52:50 by mmoullec          #+#    #+#             */
/*   Updated: 2016/07/18 19:35:02 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		format_window(int *win_x, int *win_y, int x_max, int y_max)
{
	if (x_max < 500 || y_max < 500)
	{
		*win_x = 1000;
		*win_y = 1000;
	}
	else
	{
		*win_x = 1500;
		*win_y = 1500;
	}
}

int			test_in_window(int drawx, int drawy, t_cst *cst)
{
	if (drawx < 0 || drawx > cst->win_x - 1)
		return (0);
	if (drawy < 0 || drawy > cst->win_y - 1)
		return (0);
	return (1);
}
