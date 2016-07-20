/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 16:35:51 by mmoullec          #+#    #+#             */
/*   Updated: 2016/07/19 19:10:36 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_line			*find_next_y2(t_line **line, int x)
{
	t_line		*tmp;

	tmp = *line;
	if (tmp)
	{
		while (tmp)
		{
			if (tmp->x == x)
				return (tmp);
			tmp = tmp->next;
		}
	}
	return (NULL);
}

t_line			*find_next_y(t_datas **datas, int x, int y)
{
	t_datas		*tmp;

	tmp = *datas;
	if (tmp)
	{
		while (tmp)
		{
			if (tmp->num_line == y)
				return (find_next_y2(&tmp->line, x));
			tmp = tmp->next;
		}
	}
	return (NULL);
}
