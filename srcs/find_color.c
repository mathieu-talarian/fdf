/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 15:29:06 by mmoullec          #+#    #+#             */
/*   Updated: 2016/07/19 17:58:41 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				tolowercase(char **str)
{
	int		i;
	char	*rend;

	i = 0;
	rend = *str;
	if (rend)
	{
		while (rend[i])
		{
			if (65 <= rend[i] && rend[i] <= 90)
				rend[i] = rend[i] - 65 + 97;
			i++;
		}
	}
}

unsigned int		find_color(char *couleur)
{
	int		i;
	char	*chr;

	if (!couleur)
		return (0);
	tolowercase(&couleur);
	chr = ft_strchr(couleur, 'x');
	i = chr - couleur + 1;
	couleur = &couleur[i];
	printf("%s\n", couleur);
	return (ft_atoi_base(couleur, "0123456789abcdef"));
}

unsigned int		fill_color(int alt)
{
	if (alt < 100)
		return (find_color("0x191970"));
	if (100 <= alt && alt < 0)
		return (find_color("0x1213"));
	if (0 <= alt && alt < 10)
		return (find_color("0xff00"));
	if (10 <= alt && alt < 30)
		return (find_color("0xffff"));
	return (find_color("0xffffff"));
}
