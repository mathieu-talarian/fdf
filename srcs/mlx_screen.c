/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_screen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 19:06:12 by mmoullec          #+#    #+#             */
/*   Updated: 2016/07/19 21:20:58 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		difference(int cpt, unsigned int *color, int j)
{
	if (cpt == 1)
		*color = *color + j;
	else if (cpt == 2)
		*color = *color - j;
}

void		line_1(t_mlx *mlx, t_draw draw, t_alt alt)
{
	t_diff diff;

	diff.i = 0;
	diff.cpt = 0;
	diff.j = 0;
	diff.color = alt.col_n;
	if (alt.diff != 0 && draw.dx != 0)
		diff.j = ABS(alt.diff / draw.dx);
	if (alt.diff < 0)
		diff.cpt = 1;
	else if (alt.diff > 0)
		diff.cpt = 2;
	draw.cumul = draw.dx / 2;
	while (++diff.i <= draw.dx)
	{
		draw.x += draw.xinc;
		draw.cumul += draw.dy;
		if (draw.cumul >= draw.dx)
		{
			draw.cumul -= draw.dx;
			draw.y += draw.yinc;
		}
		put_color_to_pixel(mlx, draw, diff.color);
		difference(diff.cpt, &diff.color, diff.j);
	}
}

void		line_2(t_mlx *mlx, t_draw draw, t_alt alt)
{
	t_diff diff;

	diff.i = 0;
	diff.cpt = 0;
	diff.j = 0;
	diff.color = alt.col_n;
	if (alt.diff != 0 && draw.dy != 0)
		diff.j = ABS(alt.diff / draw.dy);
	if (alt.diff < 0)
		diff.cpt = 1;
	else if (alt.diff > 0)
		diff.cpt = 2;
	draw.cumul = draw.dy / 2;
	while (++diff.i <= draw.dy)
	{
		draw.y += draw.yinc;
		draw.cumul += draw.dx;
		if (draw.cumul >= draw.dy)
		{
			draw.cumul -= draw.dy;
			draw.x += draw.xinc;
		}
		put_color_to_pixel(mlx, draw, diff.color);
		difference(diff.cpt, &diff.color, diff.j);
	}
}

void		put_color_to_pixel(t_mlx *mlx, t_draw draw, unsigned int color)
{
	int				j;

	draw.x = draw.x + AGGR_X;
	draw.y = draw.y + AGGR_Y;
	if (test_in_window(draw.x, draw.y, mlx->cst))
	{
		j = (draw.x * 4) + (draw.y * SL);
		ADR[j] = color;
		ADR[++j] = (color >> 8);
		ADR[++j] = (color >> 16);
	}
}
