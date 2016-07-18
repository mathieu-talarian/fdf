/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 16:33:09 by mmoullec          #+#    #+#             */
/*   Updated: 2016/07/16 16:34:10 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		print_pixel_per_line(t_datas *datas, t_mlx *mlx, t_line **line)
{
	t_line *ll;

	ll = *line;
	if (ll)
		while (ll)
		{
			mlx_draw_line(datas, &ll, mlx, 1);
			ll = ll->next;
		}
}
