/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 17:29:22 by mmoullec          #+#    #+#             */
/*   Updated: 2016/07/15 16:01:12 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_datas(t_all **ll)
{
	t_all *all;

	all = *ll;
	if (all->datas)
	{
		while (all->datas)
		{
			if (all->datas->line)
			{
				while (all->datas->line)
				{
					ft_putnbr_endl(all->datas->line->x);
					ft_putnbr_endl(all->datas->line->y);
					ft_putnbr_endl(all->datas->line->z);
					ft_putendl(all->datas->line->color);
					all->datas->line = all->datas->line->next;
				}
			}
			all->datas = all->datas->next;
		}
	}
}
