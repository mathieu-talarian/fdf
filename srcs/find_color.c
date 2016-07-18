/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 17:02:57 by mmoullec          #+#    #+#             */
/*   Updated: 2016/06/30 17:15:03 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	tolowercase(char **str)
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

int		find_color(char *couleur)
{
	int		i;
	char	*chr;

	if (!couleur)
		return (0);
	tolowercase(&couleur);
	chr = ft_strchr(couleur, 'x');
	i = chr - couleur;
	couleur = &couleur[i];
	return (ft_atoi_base(couleur, "0123456789abcdef"));
}
