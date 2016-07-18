/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_transfo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 16:30:36 by mmoullec          #+#    #+#             */
/*   Updated: 2016/07/15 15:33:06 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_x1(t_mlx *mlx, int x, int y)
{
	return (ZOOM * ((CT1 * x) - (CT2 * y)));
}

int		ft_y1(t_mlx *mlx, int x, int y, int z)
{
	return (ZOOM * ((-z * mlx->cst->prop_z) / 2 + (CT1 / 2 * x) + \
				(CT2 / 2 * y)));
}

int		ft_x2(t_mlx *mlx, int x, int z)
{
	return (ZOOM * (x + CT1 * -z));
}

int		ft_y2(t_mlx *mlx, int y, int z)
{
	return (ZOOM * (y + CT1 / 2 * -z));
}
