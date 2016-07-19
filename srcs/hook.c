/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 15:24:10 by mmoullec          #+#    #+#             */
/*   Updated: 2016/07/19 13:17:45 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hook(int keycode, void *params)
{
	ft_putstr("keycode = ");
	ft_putnbr_endl(keycode);
	if (keycode == 53)
	{
		pre_free((t_all *)params);
		exit(0);
	}
	if (123 <= keycode && keycode <= 126)
		redraw_key_position((t_all *)params, keycode);
	else if (37 <= keycode && keycode <= 47)
		redraw_key_cst((t_all *)params, keycode);
	else
		redraw_key((t_all *)params, keycode);
	return (0);
}
