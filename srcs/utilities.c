/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 17:29:22 by mmoullec          #+#    #+#             */
/*   Updated: 2016/07/19 15:38:08 by mmoullec         ###   ########.fr       */
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
					all->datas->line = all->datas->line->next;
				}
			}
			all->datas = all->datas->next;
		}
	}
}

void	ft_tabdel(char ***tab)
{
	char	**tmp;
	int		i;

	tmp = *tab;
	i = 0;
	while (tmp[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tmp);
	tmp = NULL;
}

void	tab_clr(char ***tab)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = *tab;
	while (tmp[i])
	{
		tmp[i] = 0;
		i++;
	}
}
