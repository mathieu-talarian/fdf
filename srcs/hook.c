/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 15:24:10 by mmoullec          #+#    #+#             */
/*   Updated: 2016/07/18 20:39:51 by mmoullec         ###   ########.fr       */
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
	redraw_key((t_all *)params, keycode);
	return (0);
}
