/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 16:58:12 by mmoullec          #+#    #+#             */
/*   Updated: 2016/07/19 12:39:34 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		fdf_usage(void)
{
	ft_putendl("Usage : ./fdf <filename> [ case_size z_size ]");
	return (ERROR);
}

int		fdf_error_open(char *filename)
{
	ft_putstr("No file ");
	ft_putendl(filename);
	return (ERROR);
}

int		fdf_no_data(void)
{
	ft_putendl("No data found.");
	return (ERROR);
}

int		fdf_length(t_datas *datas)
{
	int i;

	i = datas->nb_words;
	while (datas)
	{
		if (datas->nb_words != i)
		{
			ft_putendl("Found wrong file length. Exiting.");
			return (ERROR);
		}
		datas = datas->next;
	}
	return (1);
}
