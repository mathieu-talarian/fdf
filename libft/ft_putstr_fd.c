/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 17:02:27 by mmoullec          #+#    #+#             */
/*   Updated: 2016/05/09 15:28:21 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(const char *str, int fd)
{
	int i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			ft_putchar_fd(str[i], fd);
			i++;
		}
	}
}