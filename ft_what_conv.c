/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_what_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llorgere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 17:43:12 by llorgere          #+#    #+#             */
/*   Updated: 2018/04/09 17:43:21 by llorgere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_what_conv(char *str)
{
	int		len;

	len = ft_strlen(str);
	if (len == 1)
		return (ft_one_conv(str));
	else if (len == 2)
		return (ft_two_conv(str));
	else if (len == 3)
		return (ft_three_conv(str));
	else
		return (0);
}
