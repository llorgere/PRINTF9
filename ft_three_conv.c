/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_three_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llorgere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 17:13:25 by llorgere          #+#    #+#             */
/*   Updated: 2018/04/09 17:13:30 by llorgere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_three_conv(char *str)
{
	if (str[0] == 'l' && str[1] == 'l')
		return (ft_three_l_conv(str));
	else if (str[0] == 'h' && str[1] == 'h')
		return (ft_three_h_conv(str));
	else
		return (0);
}
