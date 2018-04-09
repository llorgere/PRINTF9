/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_two_h_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llorgere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 17:03:47 by llorgere          #+#    #+#             */
/*   Updated: 2018/04/09 17:03:52 by llorgere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_two_h_conv(char *str)
{
	if (str[0] == 'd' || str[0] == 'i')
		return (21);
	else if (str[0] == 'u')
		return (22);
	else if (str[0] == 'o')
		return (23);
	else if (str[0] == 'x')
		return (24);
	else if (str[0] == 'X')
		return (25);
	else if (str[0] == 'D')
		return (9);
	else if (str[0] == 'U')
		return (10);
	else if (str[0] == 'O')
		return (11);
	else
		return (ft_one_conv(str));
}
