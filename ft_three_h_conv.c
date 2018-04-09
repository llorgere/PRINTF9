/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_three_h_conv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llorgere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 16:59:11 by llorgere          #+#    #+#             */
/*   Updated: 2018/04/09 16:59:13 by llorgere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_three_h_conv(char *str)
{
	if (str[0] == 'd' || str[0] == 'i')
		return (26);
	else if (str[0] == 'u')
		return (27);
	else if (str[0] == 'o')
		return (28);
	else if (str[0] == 'x')
		return (29);
	else if (str[0] == 'X')
		return (30);
	else
		return (ft_one_conv(str));
}
