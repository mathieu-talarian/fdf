/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_listing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 18:21:48 by mmoullec          #+#    #+#             */
/*   Updated: 2016/07/19 17:58:13 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		fill_line_list(t_line **list, int num_line, char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		line_list_add(list, new_line_list(num_line, i, tab[i]));
		i++;
	}
}

t_line		*new_line_list(int y, int x, char *nbr)
{
	t_line	*new;
	char	**tab;

	tab = NULL;
	if (!(new = (t_line *)malloc(sizeof(t_line))))
		return (NULL);
	if (new && nbr)
	{
		tab = ft_strsplit(nbr, ',');
		new->x = x;
		new->y = y;
		new->z = ft_atoi(tab[0]);
		ft_strdel(&tab[0]);
		if (tab[1])
		{
			new->color = find_color(tab[1]);
			ft_strdel(&tab[1]);
		}
		else
			new->color = find_color("0xffffff");
		new->next = NULL;
	}
	ft_strdel(tab);
	return (new);
}

t_datas		*new_data_list(int count_words, int num_line, char **tab)
{
	t_datas		*new;
	int			i;

	i = 0;
	new = NULL;
	if (!(new = (t_datas *)malloc(sizeof(t_datas))))
		return (NULL);
	if (new)
	{
		new->num_line = num_line;
		new->nb_words = count_words;
		new->line = NULL;
		fill_line_list(&new->line, num_line, tab);
		new->next = NULL;
	}
	return (new);
}

void		data_list_add(t_datas **begin_list, t_datas *new)
{
	t_datas *datas;

	datas = *begin_list;
	if (datas && new)
	{
		while (datas->next)
			datas = datas->next;
		datas->next = new;
	}
	else
	{
		if (new)
		{
			*begin_list = new;
		}
	}
}

void		line_list_add(t_line **begin_list, t_line *new)
{
	t_line *line;

	line = *begin_list;
	if (line && new)
	{
		while (line->next)
			line = line->next;
		line->next = new;
	}
	else
	{
		if (new)
			*begin_list = new;
	}
}
