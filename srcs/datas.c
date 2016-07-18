/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datas.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 14:49:15 by mmoullec          #+#    #+#             */
/*   Updated: 2016/06/02 14:52:32 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_line_max(t_datas **begin_list)
{
	t_datas *datas;

	datas = *begin_list;
	if (datas)
	{
		while (datas->next)
			datas = datas->next;
		return (datas->num_line);
	}
	return (0);
}
