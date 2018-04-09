/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llorgere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 02:28:07 by llorgere          #+#    #+#             */
/*   Updated: 2018/04/09 21:06:30 by llorgere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	flag_type	ft_conv_adjust(flag_type flag)
{
	if (flag.j == 1)
	{
		flag.h = 0;
		flag.l = 0;
		flag.z = 0;
	}
	else if (flag.l == 2)
	{
		flag.h = 0;
		flag.z = 0;
	}
	else if(flag.z == 1)
	{
		flag.l = 0;
		flag.h = 0;
	}
	else if(flag.l == 1)
		flag.h = 0;
	else
		return (flag);
	return (flag);
}

static	int			ft_what_convn(flag_type flag, char *str)
{
	flag = ft_conv_adjust(flag);
	if (flag.j == 1)
		return (ft_two_j_conv(str));
	else if(flag.l == 2)
		return (ft_three_l_conv(str));
	else if (flag.z == 1)
		return (ft_two_z_conv(str));
	else if (flag.l == 1)
		return (ft_two_l_conv(str));
	else if (flag.h == 1)
		return (ft_two_h_conv(str));
	else if(flag.h == 2)
		return (ft_three_h_conv(str));
	else
		return (ft_one_conv(str));
}

static	flag_type	ft_flag_init(void)
{
	flag_type	flag;

	flag.conv_num = 0;
	flag.width = -1;
	flag.preci = -1;
	flag.minus = 0;
	flag.plus = 0;
	flag.dies = 0;
	flag.zero = 0;
	flag.space = 0;
	flag.point = 0;
	flag.j = 0;
	flag.h = 0;
	flag.l = 0;
	flag.z = 0;
	flag.tab = NULL;
	flag.W = -1;
	return (flag);
}

int		ft_flagfirst(flag_type *flag, int i, char *tab, int *tmp2)
{
	if (i == *tmp2 && tab[i] == '-' && flag->minus == 0 && flag->width < 0 && flag->preci < 0)
	{
		flag->minus++;
		return(i++);
	}
	else if (i == *tmp2 && tab[i] == '+' && flag->plus == 0)
	{
		flag->plus++;
		return(i++);
	}
	else if (i == *tmp2 && tab[i] == 'l' && flag->l < 2)
	{
		flag->l++;
		return(i++);
	}
	else if (i == *tmp2 && tab[i] == 'h' && flag->h < 2)
	{
		flag->h++;
		return(i++);
	}
	else if (i == *tmp2 && tab[i] == 'j' && flag->j == 0)
	{
		flag->j++;
		return(i++);
	}
	else
		return(i);
}

int		ft_flagsecond(flag_type *flag, int i, char *tab, int *tmp2)
{
	if ((i == *tmp2) && tab[i] == 'z' && flag->z == 0)
	{
		flag->z++;
		return(i++);
		i++;
	}
	if (i == *tmp2 && tab[i] == ' ' && flag->space == 0 && flag->width < 0 && flag->preci < 0)
	{
		flag->space++;
		return(i++);
		i++;
	}
	if (i == *tmp2 && tab[i] == '0' && flag->zero == 0 && flag->width < 0 && flag->preci < 0)
	{
		flag->zero++;
		return(i++);
		i++;
	}
	if (i == *tmp2 && tab[i] == '#' && flag->dies == 0)
	{
		flag->dies++;
		return(i++);
	}
	else
		return(i);
}

int		ft_flagthird(flag_type *flag, int i, char *tab, int *tmp2)
{
	int		tmp;
	char	*tabpw;

	tmp = 0;
	tabpw = NULL;
	if (i == *tmp2 && tab[i] > '0' && tab[i] <= '9' && flag->width < 0 && flag->preci < 0)
	{
		tmp = i;
		while (tab[i] >= '0' && tab[i] <= '9')
			i++;
		tabpw = ft_strndup(tab + tmp, i - tmp + 1);
		flag->width = ft_atoi(tabpw);
		free(tabpw);
		return (i);
	}
	/*
	if (i == *tmp2 && tab[i] == '.' && flag->preci < 0)
	{
		if (tab[i + 1] < '0' || tab[i + 1] > '9')
		{
			flag->preci = 0;
			return(i++);
		}
		else
		{
			i++;
			tmp = i;
			while (tab[i] >= '0' && tab[i] <= '9')
				i++;
			tabpw = ft_strndup(tab + tmp, i - tmp + 1);
			flag->preci = ft_atoi(tabpw);
			free(tabpw);
			return (i);
		}
	}
	if ((i == *tmp2) && (tab[i] == '+' || tab[i] == ' ' || tab[i] == '#' ||
		tab[i] == '-' || tab[i] == '0' || tab[i] == '.' || (tab[i] >= '0' &&
		tab[i] <= '9') || tab[i] == 'j' || tab[i] == 'h' || tab[i] == 'l' ||
		tab[i] == 'z'))
			return(i++);
	*/
	else
		return(i);
}

flag_type			ft_arg_conv(char *tab)
{
	int			i;
	int			tmp;
	int			tmp2;
//	int			count;
	flag_type	flag;
	char 	*tabpw;

	i = 1;
	tmp = 0;
	//count = 0;
	flag = ft_flag_init();
	while (tab[i] != 'd' && tab[i] != 'i' && tab[i] != 's' &&
			tab[i] != 'p' && tab[i] != 'S' && tab[i] !='D' &&
			tab[i] != 'U' && tab[i] !='O' && tab[i] != 'o' &&
			tab[i] != 'u' && tab[i] !='x' && tab[i] !='X' &&
			tab[i] != 'c' && tab[i] !='C'  && tab[i] !='\0'
			&& tab[i] != '%')
	{
//		tmp2 = count;
		i = ft_flagfirst(&flag, i, tab, &tmp2);
		/*
		   if (tab[i] == '-' && flag.minus == 0 && flag.width < 0 && flag.preci < 0)
		   {
		   flag.minus++;
		   i++;
		   }
		   else if (tab[i] == '+' && flag.plus == 0)
		   {
		   flag.plus++;
		   i++;
		   }
		   else if (tab[i] == 'l' && flag.l < 2)
		   {
		   flag.l++;
		   i++;
		   }
		   else if (tab[i] == 'h' && flag.h < 2)
		   {
		   flag.h++;
		   i++;
		   }
		   else if (tab[i] == 'j' && flag.j == 0)
		   {
		   flag.j++;
		   i++;
		   }
		   */
		//else if (tab[i] == 'z' && flag.z == 0)
		/*
		   if (tab[i] == 'z' && flag.z == 0)
		   {
		   flag.z++;
		   i++;
		   }
		   else if (tab[i] == ' ' && flag.space == 0 && flag.width < 0 && flag.preci < 0)
		   {
		   flag.space++;
		   i++;
		   }
		   else if (tab[i] == '0' && flag.zero == 0 && flag.width < 0 && flag.preci < 0)
		   {
		   flag.zero++;
		   i++;
		   }
		   else if (tab[i] == '#' && flag.dies == 0)
		   {
		   flag.dies++;
		   i++;
		   }
		   */
		i = ft_flagsecond(&flag, i, tab, &tmp2);
		
		if (tab[i] > '0' && tab[i] <= '9' && flag.width < 0 && flag.preci < 0)
		{
			tmp = i;
			while (tab[i] >= '0' && tab[i] <= '9')
				i++;
			tabpw = ft_strndup(tab + tmp, i - tmp + 1);
			flag.width = ft_atoi(tabpw);
			free(tabpw);
		}
		
		//i = ft_flagthird(&flag, i, tab, &tmp2);
		else if (tab[i] == '.' && flag.preci < 0)
		{
			if (tab[i + 1] < '0' || tab[i + 1] > '9')
			{
				flag.preci = 0;
				i++;
			}
			else
			{
				i++;
				tmp = i;
				while (tab[i] >= '0' && tab[i] <= '9')
					i++;
				tabpw = ft_strndup(tab + tmp, i - tmp + 1);
				flag.preci = ft_atoi(tabpw);
				free(tabpw);
			}
		}
		
		else if ((tab[i] == '+' || tab[i] == ' ' || tab[i] == '#' || tab[i] == '-' || tab[i] == '0' || tab[i] == '.' || (tab[i] >= '0' && tab[i] <= '9') || tab[i] == 'j' || tab[i] == 'h' || tab[i] == 'l' || tab[i] == 'z'))
			i++;
		
		//else
		//if(i == tmp2)
		else
		{
			tmp = i;
			while (tab[i] != '\0')
				i++;
			if (tmp != i)
				flag.tab = ft_strndup(tab + tmp, i - tmp + 1);
			flag.conv_num = -1;
			return (flag);
		}
	}
	flag.conv_num = ft_what_convn(flag, tab + i);
	return (flag);
}
