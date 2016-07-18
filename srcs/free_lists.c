/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 17:41:09 by mmoullec          #+#    #+#             */
/*   Updated: 2016/07/18 20:51:20 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_line_list(t_line **begin_list)
{
	t_line *ll;
	t_line *next;

	ll = *begin_list;
	if (ll)
	{
		while (ll)
		{
			next = ll->next;
			free(ll);
			ll = NULL;
			ll = next;
		}
		*begin_list = NULL;
	}
}

void	free_datas_list(t_datas **begin_list)
{
	t_datas *ll;
	t_datas *next;

	ll = *begin_list;
	if (ll)
	{
		while (ll)
		{
			next = ll->next;
			free(ll);
			ll = NULL;
			ll = next;
		}
		*begin_list = NULL;
	}
}

void	free_lists(t_datas **datas, t_line **line)
{
	free_line_list(line);
	free_datas_list(datas);
}

void	pre_free(t_all *all)
{
	mlx_destroy_image(MLX, IMG);
	mlx_clear_window (MLX, WIN);
	mlx_destroy_window (MLX, WIN);
	free(all->mlx->infos_img);
	free(all->mlx->cst);
	free_lists(&all->datas, &all->datas->line);
}
