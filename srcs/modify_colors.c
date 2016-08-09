/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 17:38:46 by mmoullec          #+#    #+#             */
/*   Updated: 2016/08/09 12:40:41 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_next_y(t_datas *datas, t_line *line, t_mlx *mlx)
{
	t_line		*next_y;
	t_alt		alt;

	next_y = find_next_y(&datas, line->x, line->y + 1);
	if (line->color == find_color("0xffffff"))
	{
		alt.col_n = GET_COLOR(find_color(modify_colors(line, mlx)));
		alt.col_p = GET_COLOR(find_color(modify_colors(next_y, mlx)));
	}
	else
	{
		alt.col_n = GET_COLOR(line->color);
		alt.col_p = GET_COLOR(next_y->color);
	}
	mlx_draw_line_2(line, next_y, mlx, alt);
}

char		*modify_colors(t_line *line, t_mlx *mlx)
{
	if (line->z * mlx->cst->prop_z == 0)
		return ("0xffffff");
	if (line->z * mlx->cst->prop_z < 0 && line->z * mlx->cst->prop_z > -20)
		return ("0x7fffd4");
	if (line->z * mlx->cst->prop_z > 0 && line->z * mlx->cst->prop_z < 20)
		return ("0x98fb98");
	if (line->z * mlx->cst->prop_z >= 20 && line->z * mlx->cst->prop_z < 50)
		return ("0xff");
	if (line->z * mlx->cst->prop_z >= 50)
		return ("0xbfff");
	if (line->z * mlx->cst->prop_z <= -20 && line->z * mlx->cst->prop_z > -50)
		return ("0x202baa");
	if (line->z * mlx->cst->prop_z <= -50)
		return ("0x66cdaa");
	return ("0xffffff");
}
