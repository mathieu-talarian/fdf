/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 15:22:57 by mmoullec          #+#    #+#             */
/*   Updated: 2016/07/19 15:22:17 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	redraw_key_position(t_all *all, int keycode)
{
	if (keycode == 124)
		MMC->aggr_x += 5;
	else if (keycode == 123)
		MMC->aggr_x -= 5;
	else if (keycode == 126)
		MMC->aggr_y -= 5;
	else if (keycode == 125)
		MMC->aggr_y += 5;
	mlx_destroy_image(MLX, IMG);
	IMG = mlx_new_image(MLX, all->mlx->cst->win_x, all->mlx->cst->win_y);
	MMI->d_addr = mlx_get_data_addr(IMG, &MMI->bpp, &MMI->sizeline, \
			&MMI->endian);
	aff_coord(&all);
}

void	redraw_key_cst(t_all *all, int keycode)
{
	if (keycode == 37)
		MMC->ct3 = MMC->ct3 + 0.1;
	else if (keycode == 47)
		MMC->ct3 = MMC->ct3 - 0.1;
	else if (keycode == 40)
		MMC->ct4 = MMC->ct4 + 0.1;
	else if (keycode == 43)
		MMC->ct4 = MMC->ct4 - 0.1;
	mlx_destroy_image(MLX, IMG);
	IMG = mlx_new_image(MLX, all->mlx->cst->win_x, all->mlx->cst->win_y);
	MMI->d_addr = mlx_get_data_addr(IMG, &MMI->bpp, &MMI->sizeline, \
			&MMI->endian);
	aff_coord(&all);
}

void	redraw_key(t_all *all, int keycode)
{
	if (keycode == 24)
		MMC->ct1 = MMC->ct1 + 0.1;
	else if (keycode == 27)
		MMC->ct1 = MMC->ct1 - 0.1;
	else if (keycode == 29)
		MMC->ct2 = MMC->ct2 + 0.1;
	else if (keycode == 25)
		MMC->ct2 = MMC->ct2 - 0.1;
	else if (keycode == 78)
		MMC->zoom = MMC->zoom - 0.3;
	else if (keycode == 69)
		MMC->zoom = MMC->zoom + 0.3;
	else if (keycode == 0)
		MMC->prop_z = MMC->prop_z + 0.1;
	else if (keycode == 6)
		MMC->prop_z = MMC->prop_z - 0.1;
	mlx_destroy_image(MLX, IMG);
	IMG = mlx_new_image(MLX, all->mlx->cst->win_x, all->mlx->cst->win_y);
	MMI->d_addr = mlx_get_data_addr(IMG, &MMI->bpp, &MMI->sizeline, \
			&MMI->endian);
	aff_coord(&all);
}
