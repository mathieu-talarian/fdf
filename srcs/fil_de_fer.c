/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fil_de_fer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 14:17:43 by mmoullec          #+#    #+#             */
/*   Updated: 2016/08/09 12:42:34 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	to_screen2(t_all *all, t_datas *datas, t_line **ll)
{
	t_line *line;

	line = *ll;
	while (line->next)
	{
		mlx_draw_line(datas, &line, all->mlx, 0);
		line = line->next;
	}
}

void	to_screen(t_all *all, t_datas **ll)
{
	t_datas *datas;

	datas = *ll;
	if (datas)
	{
		while (datas->next)
		{
			print_pixel_per_line(datas, all->mlx, &datas->line);
			datas = datas->next;
		}
	}
	to_screen2(all, datas, &datas->line);
}

void	aff_coord(t_all **ll)
{
	static int		j = 0;
	t_all			*all;

	all = *ll;
	if (j == 0)
		j = get_line_max(&all->datas);
	to_screen(all, &all->datas);
	mlx_put_image_to_window(all->mlx->mlx, all->mlx->win, \
			all->mlx->infos_img->img, 0, 0);
	mlx_hook(all->mlx->win, KeyPress, KeyPressMask, key_hook, all);
	mlx_loop(all->mlx->mlx);
}
