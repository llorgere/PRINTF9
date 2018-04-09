/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_two_j_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llorgere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 17:07:15 by llorgere          #+#    #+#             */
/*   Updated: 2018/04/09 17:07:17 by llorgere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_two_j_conv(char *str)
{
	if (str[0] == 'd' || str[0] == 'i')
		return (36);
	else if (str[0] == 'u')
		return (37);
	else if (str[0] == 'o')
		return (38);
	else if (str[0] == 'x')
		return (39);
	else if (str[0] == 'X')
		return (40);
	else
		return (ft_one_conv(str));
}
