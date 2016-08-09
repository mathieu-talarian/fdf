/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 12:43:46 by mmoullec          #+#    #+#             */
/*   Updated: 2016/08/09 13:03:39 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		fill_points(t_line *line_x, t_line *line_y, t_mlx *mlx, t_pts *pts)
{
	int		a;
	int		b;
	int		c;
	int		d;

	a = ft_x1(mlx, line_x->x, line_x->y);
	c = ft_x1(mlx, line_y->x, line_y->y);
	b = ft_y1(mlx, line_x->x, line_x->y, line_x->z);
	d = ft_y1(mlx, line_y->x, line_y->y, line_y->z);
	pts->x0 = X(a, b, COS, SIN);
	pts->y0 = Y(a, b, SIN, COS);
	pts->x1 = X(c, d, COS, SIN);
	pts->y1 = Y(c, d, SIN, COS);
}

void		mlx_draw_line_2(t_line *line_x, t_line *line_y, t_mlx *mlx, \
		t_alt alt)
{
	t_pts	pts;

	if (mlx->form == 1)
		fill_points(line_x, line_y, mlx, &pts);
	else
	{
		pts.x0 = X(ft_x2(mlx, line_x->x, line_x->z), ft_y2(mlx, line_x->y, \
					line_x->z), COS, SIN);
		pts.y0 = Y(ft_x2(mlx, line_x->x, line_x->z), ft_y2(mlx, line_x->y, \
					line_x->z), SIN, COS);
		pts.x1 = X(ft_x2(mlx, line_y->x, line_y->z), ft_y2(mlx, line_y->y, \
					line_y->z), COS, SIN);
		pts.y1 = Y(ft_x2(mlx, line_y->x, line_y->z), ft_y2(mlx, line_y->y, \
					line_y->z), SIN, COS);
	}
	ligne(mlx, pts, alt);
}
