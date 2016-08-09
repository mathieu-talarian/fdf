/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_screen2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 12:14:00 by mmoullec          #+#    #+#             */
/*   Updated: 2016/08/09 12:40:46 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	line1(t_mlx *mlx, t_draw draw, t_alt alt)
{
	int				i;
	unsigned int	color;

	i = 0;
	draw.cumul = draw.dx / 2;
	color = MAX(alt.col_n, alt.col_p);
	while (++i <= draw.dx)
	{
		draw.x += draw.xinc;
		draw.cumul += draw.dy;
		if (draw.cumul >= draw.dx)
		{
			draw.cumul -= draw.dx;
			draw.y += draw.yinc;
		}
		put_color_to_pixel(mlx, draw, color);
	}
}

void	line2(t_mlx *mlx, t_draw draw, t_alt alt)
{
	int				i;
	unsigned int	color;

	i = 0;
	color = MAX(alt.col_n, alt.col_p);
	draw.cumul = draw.dy / 2;
	while (++i <= draw.dy)
	{
		draw.y += draw.yinc;
		draw.cumul += draw.dx;
		if (draw.cumul >= draw.dy)
		{
			draw.cumul -= draw.dy;
			draw.x += draw.xinc;
		}
		put_color_to_pixel(mlx, draw, color);
	}
}
