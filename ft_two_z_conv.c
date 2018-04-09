/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_two_z_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llorgere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 17:05:15 by llorgere          #+#    #+#             */
/*   Updated: 2018/04/09 17:05:19 by llorgere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_two_z_conv(char *str)
{
	if (str[0] == 'd' || str[0] == 'i')
		return (31);
	else if (str[0] == 'u')
		return (32);
	else if (str[0] == 'o')
		return (33);
	else if (str[0] == 'x')
		return (34);
	else if (str[0] == 'X')
		return (35);
	else
		return (ft_one_conv(str));
}
