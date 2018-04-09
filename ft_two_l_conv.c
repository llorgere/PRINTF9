/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_two_l_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llorgere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 16:56:33 by llorgere          #+#    #+#             */
/*   Updated: 2018/04/09 18:51:00 by llorgere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_two_l_conv(char *str)
{
	if (str[0] == 'd' || str[0] == 'i')
		return (9);
	else if (str[0] == 'u')
		return (10);
	else if (str[0] == 'o')
		return (11);
	else if (str[0] == 'x')
		return (12);
	else if (str[0] == 'X')
		return (13);
	else if (str[0] == 'c')
		return (14);
	else if (str[0] == 's')
		return (15);
	else if (str[0] == 'D')
		return (16);
	else if (str[0] == 'U')
		return (17);
	else if (str[0] == 'O')
		return (18);
	else
		return (ft_one_conv(str));
}
