/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_one_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llorgere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 17:10:29 by llorgere          #+#    #+#             */
/*   Updated: 2018/04/09 18:14:16 by llorgere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		ft_one_up_conv(char *str)
{
	if (str[0] == 'D')
		return (9);
	else if (str[0] == 'U')
		return (10);
	else if (str[0] == 'O')
		return (11);
	else if (str[0] == 'C')
		return (14);
	else if (str[0] == 'S')
		return (15);
	else if (str[0] == 'X')
		return (5);
	else if (str[0] == '%')
		return (41);
	else
		return (0);
}

static int		ft_one_lo_conv(char *str)
{
	if (str[0] == 'd' || str[0] == 'i')
		return (1);
	else if (str[0] == 'u')
		return (2);
	else if (str[0] == 'o')
		return (3);
	else if (str[0] == 'x')
		return (4);
	else if (str[0] == 'c')
		return (6);
	else if (str[0] == 's')
		return (7);
	else if (str[0] == 'p')
		return (8);
	else
		return (0);
}

int				ft_one_conv(char *str)
{
	if (str[0] <= 'Z')
		return (ft_one_up_conv(str));
	else
		return (ft_one_lo_conv(str));
}
