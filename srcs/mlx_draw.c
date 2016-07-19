/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 16:41:19 by mmoullec          #+#    #+#             */
/*   Updated: 2016/07/19 16:19:33 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		line_to_pixel(t_mlx *mlx, t_draw draw, t_alt alt)
{
	if (test_in_window(draw.x, draw.y, mlx->cst))
		put_color_to_pixel(mlx, draw, alt.col_n);
	if (draw.dx > draw.dy)
		line_1(mlx, draw, alt);
	else
		line_2(mlx, draw, alt);
}

void		ligne(t_mlx *mlx, t_pts pts, t_alt alt)
{
	t_draw	draw;

	if (alt.col_n != alt.col_p)
	{
		draw.col_max = MAX(alt.col_n, alt.col_p);
		draw.col_min = MIN(alt.col_n, alt.col_p);
		alt.diff = alt.col_n - alt.col_p;
	}
	else
	{
		draw.col_min = alt.col_n;
		alt.diff = 0;
	}
	draw.x = pts.x0;
	draw.y = pts.y0;
	draw.dx = pts.x1 - pts.x0;
	draw.dy = pts.y1 - pts.y0;
	draw.xinc = (draw.dx > 0) ? 1 : -1;
	draw.yinc = (draw.dy > 0) ? 1 : -1;
	draw.dx = abs(draw.dx);
	draw.dy = abs(draw.dy);
	line_to_pixel(mlx, draw, alt);
}

void		mlx_draw_line_2(t_line *line_x, t_line *line_y, t_mlx *mlx, \
		t_alt alt)
{
	int		a;
	int		b;
	int		c;
	int		d;
	t_pts	pts;

	a = ft_x1(mlx, line_x->x, line_x->y);
	c = ft_x1(mlx, line_y->x, line_y->y);
	b = ft_y1(mlx, line_x->x, line_x->y, line_x->z);
	d = ft_y1(mlx, line_y->x, line_y->y, line_y->z);
	pts.x0 = X(a, b, COS, SIN);
	pts.y0 = Y(a, b, SIN, COS);
	pts.x1 = X(c, d, COS, SIN);
	pts.y1 = Y(c, d, SIN, COS);
	ligne(mlx, pts, alt);
}

void		fill_pts(t_pts *pts, t_mlx *mlx, t_line *line)
{
	pts->x0 = X(ft_x1(mlx, line->x, line->y), \
			ft_y1(mlx, line->x, line->y, line->z), COS, SIN);
	pts->y0 = Y(ft_x1(mlx, line->x, line->y), \
			ft_y1(mlx, line->x, line->y, line->z), SIN, COS);
	pts->x1 = X(ft_x1(mlx, line->next->x, line->next->y), \
			ft_y1(mlx, line->next->x, line->next->y, line->next->z), \
			COS, SIN);
	pts->y1 = Y(ft_x1(mlx, line->next->x, line->next->y), \
			ft_y1(mlx, line->next->x, line->next->y, line->next->z), \
			SIN, COS);
}

void		mlx_draw_line(t_datas *datas, t_line **ll, t_mlx *mlx, int cpt)
{
	t_pts				pts;
	t_line				*next_y;
	t_line				*line;
	t_alt				alt;

	line = *ll;
	if (line->next)
	{
		fill_pts(&pts, mlx, line);
		alt.col_n = GET_COLOR(line->color);
		alt.col_p = GET_COLOR(line->next->color);
		ligne(mlx, pts, alt);
	}
	if (cpt == 1)
	{
		next_y = find_next_y(&datas, line->x, line->y + 1);
		alt.col_n = GET_COLOR(line->color);
		alt.col_p = GET_COLOR(next_y->color);
		mlx_draw_line_2(line, next_y, mlx, alt);
	}
}
