/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llorgere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 18:14:28 by llorgere          #+#    #+#             */
/*   Updated: 2018/04/09 18:50:14 by llorgere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*ft_p_conv_null(void)
{
	char	*tab;

	if (!(tab = (char *)malloc(sizeof(*tab) * (6))))
		return (0);
	tab[0] = '(';
	tab[1] = 'n';
	tab[2] = 'i';
	tab[3] = 'l';
	tab[4] = ')';
	tab[5] = '\0';
	return (tab);
}

static char		*ft_llg_to_hex_malloc(long long unsigned int n, int j)
{
	char	*tab;

	if (!(tab = (char *)malloc(sizeof(*tab) * (j + 1))))
		return (0);
	tab[j] = '\0';
	if (n == 0)
		tab[0] = 48;
	while (n > 0)
	{
		if (n % 16 < 10)
			tab[j - 1] = (n % 16) + '0';
		else
			tab[j - 1] = (n % 16) + 'a' - 10;
		n = n / 16;
		j--;
	}
	return (tab);
}

static char		*ft_init_str(int j)
{
	int		k;
	char	*tab;

	k = 2;
	if (!(tab = malloc(sizeof(char) * (3 + j))))
		return (NULL);
	tab[0] = '0';
	tab[1] = 'x';
	while (k <= (2 + j))
	{
		tab[k] = '\0';
		k++;
	}
	return (tab);
}

char			*ft_p_conv(long long unsigned int n)
{
	long long unsigned int	i;
	int						j;
	char					*tmp;
	char					*tab;

	i = n;
	j = 0;
	if (i == 0)
		return (ft_p_conv_null());
	while (i > 0)
	{
		i = i / 16;
		j++;
	}
	tab = ft_init_str(j);
	tmp = ft_llg_to_hex_malloc(n, j);
	tab = ft_strcat(tab, tmp);
	free(tmp);
	return (tab);
}
