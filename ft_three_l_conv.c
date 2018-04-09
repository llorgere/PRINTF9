/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_three_l_conv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llorgere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 18:13:34 by llorgere          #+#    #+#             */
/*   Updated: 2018/04/09 18:13:36 by llorgere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_three_l_conv(char *str)
{
	if (str[0] == 'd' || str[0] == 'i')
		return (16);
	else if (str[0] == 'u')
		return (17);
	else if (str[0] == 'o')
		return (18);
	else if (str[0] == 'x')
		return (19);
	else if (str[0] == 'X')
		return (20);
	else
		return (ft_one_conv(str));
}
