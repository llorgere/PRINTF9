/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_two_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llorgere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 17:12:08 by llorgere          #+#    #+#             */
/*   Updated: 2018/04/09 17:12:10 by llorgere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_two_conv(char *str)
{
	if (str[0] == 'l')
		return (ft_two_l_conv(str));
	else if (str[0] == 'h')
		return (ft_two_h_conv(str));
	else if (str[0] == 'z')
		return (ft_two_z_conv(str));
	else if (str[0] == 'j')
		return (ft_two_j_conv(str));
	else
		return (0);
}
