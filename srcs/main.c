/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 15:17:54 by mmoullec          #+#    #+#             */
/*   Updated: 2016/07/18 19:02:46 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				fdf_open(char *filename, int *fd)
{
	if ((*fd = open(filename, O_RDONLY)) < 0)
		return (0);
	return (1);
}

int				fdf_fill_list(int fd, char **line, t_datas **datas)
{
	int			i;
	int			j;
	int			k;
	char		**tab;

	k = 0;
	tab = NULL;
	j = 0;
	while ((i = get_next_line(fd, line)))
	{
		if (i == -1)
			return (-1);
		j = ft_count_words(*line, ' ', ft_char_cmp);
		tab = ft_strsplit(*line, ' ');
		data_list_add(datas, new_data_list(j, k, tab));
		tab_clr(&tab);
		k++;
	}
	free(tab);
	return (1);
}

int				fdf_start_fill(int fd, t_datas **datas)
{
	char		*line;

	if ((fdf_fill_list(fd, &line, datas)) < 0)
		return (0);
	return (1);
}

int				fdf_parsing(char *filename, t_all **ll)
{
	int			fd;
	t_all		*all;

	all = *ll;
	if (!(fdf_open(filename, &fd)))
		return (fdf_error_open(filename));
	if (!(fdf_start_fill(fd, &all->datas)))
	{
		fdf_no_data();
		return (ERROR);
	}
	if (fdf_length(all->datas) < 0)
		return (ERROR);
	return (1);
}

int				main(int ac, char **av)
{
	static t_all		*all;

	if (ac != 2)
		return (fdf_usage());
	if (!(all = (t_all *)malloc(sizeof(t_all))))
		return (0);
	all->datas = NULL;
	if (fdf_parsing(av[1], &all) <= 0)
		return (0);
	all->mlx = mlx_initialise(&all->datas);
	all->mlx->infos_img = init_image(all->mlx);
	aff_coord(&all);
	return (1);
}
