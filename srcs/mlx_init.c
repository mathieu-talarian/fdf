/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 14:22:08 by mmoullec          #+#    #+#             */
/*   Updated: 2016/07/18 20:39:07 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_image		*init_image(t_mlx *mlx)
{
	t_image		*ll;

	ll = (t_image *)malloc(sizeof(t_image));
	ll->img = mlx_new_image(mlx->mlx, mlx->cst->win_x, mlx->cst->win_y);
	printf("%d\n%d\n", mlx->cst->win_y, mlx->cst->win_x);
	ll->d_addr = mlx_get_data_addr(ll->img, &ll->bpp, &ll->sizeline, \
			&ll->endian);
	return (ll);
}

t_mlx		*mlx_initialise(t_datas **datas)
{
	t_mlx		*mlx;
	t_datas		*dts;

	dts = *datas;
	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	mlx->cst = fill_cst(&dts);
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, mlx->cst->win_x, \
			mlx->cst->win_y, "fdf");
	return (mlx);
}

int			ft_max_y(t_datas *ll)
{
	int i;

	i = 0;
	if (ll)
	{
		while (ll)
		{
			ll = ll->next;
			i++;
		}
		return (i);
	}
	return (0);
}

int			find_zoom(int x_max, int y_max, t_cst *cst)
{
	double		x;
	double		y;
	double		zoom;

	x = 0.0;
	x = (double)x_max / (double)cst->win_x;
	y = (double)y_max / (double)cst->win_y;
	zoom = MIN(1 / x, 1 / y);
	return (zoom / 2);
}

t_cst		*fill_cst(t_datas **datas)
{
	t_cst		*cst;
	t_datas		*ll;

	ll = *datas;
	cst = (t_cst *)malloc(sizeof(t_cst));
	format_window(&cst->win_x, &cst->win_y, ll->nb_words, ft_max_y(ll));
	cst->aggr_y = cst->win_y / 3;
	cst->aggr_x = cst->win_x / 2;
	cst->ct1 = 0.5;
	cst->ct2 = 0.9;
	cst->ct3 = 0;
	cst->ct4 = -3;
	cst->img_x = 0;
	cst->img_y = 0;
	cst->prop_z = 0.1;
	cst->zoom = find_zoom(ll->nb_words, ft_max_y(ll), cst);
	return (cst);
}
