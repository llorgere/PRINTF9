#include "libftprintf.h"
#include <stdio.h>

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	int			j;
	flag_type	flag;
	wii			wiit;
	char		*cur_arg = (char *)format;
	int			ret;
	char		*ret_tab;
	char		*tmp;
	char		*tmp_wide;
	int			ret_wide;
	spe_c		spec;
	
	ret_wide = 0;
	tmp_wide = NULL;
	ret = 0;
	ret_tab = NULL;
	i = 0;
	if (format == NULL)
		return (-1);
	wiit = ft_watinit(format, ft_size_tab(format));
	va_start(ap, format);
	while(wiit.tab[i])
	{
		if (wiit.pos_conv[i] == 0)
		{
			ret = ret + ft_strlen(wiit.tab[i]);
			if(!ret_tab)
				ret_tab = ft_strdup(wiit.tab[i]);
			else
			{
				if(!(tmp = malloc(sizeof(char) * ret + 1)))
					return (0);
				tmp = ft_strncpypf(tmp, ret_tab, ret - ft_strlen(wiit.tab[i]), ret + 1);
				tmp = ft_strncatpf(tmp, wiit.tab[i], ret - ft_strlen(wiit.tab[i]), ft_strlen(wiit.tab[i]));
				free(ret_tab);
				ret_tab = tmp;
			}
			free(wiit.tab[i]);
		}
		else if (wiit.pos_conv[i] == 1)
		{
			flag = ft_arg_conv(wiit.tab[i]); 
			cur_arg = ft_what_type(flag.conv_num, ap, &flag);
			if(flag.conv_num == -1)
			{
				if (flag.tab == NULL)
					cur_arg = ft_strdup(wiit.tab[i]);
				else
				{
					cur_arg = ft_strdup(flag.tab);
					free(flag.tab);
				}
				ret = ret + ft_strlen(cur_arg) ;
				if(!ret_tab)
				{
					ret_tab = ft_strdup(cur_arg);
					if(tmp_wide != NULL)
						free(tmp_wide);
					tmp_wide = ft_nstrdup(ret_tab, ret);
					ret_wide = ret;
				}
				else
				{
					if(!(tmp = malloc(sizeof(char) * ret + 1)))
						return (0);
					tmp = ft_strncpypf(tmp, ret_tab, ret - ft_strlen(cur_arg), ret + 1);
					tmp = ft_strncatpf(tmp, cur_arg, ret - ft_strlen(cur_arg), ft_strlen(cur_arg));
					free(ret_tab);
					ret_tab = tmp;
					if(tmp_wide != NULL)
						free(tmp_wide);
					tmp_wide = ft_nstrdup(ret_tab, ret);
					ret_wide = ret;
				}
			}
			else if ((flag.W > -1 && flag.preci == -1) || (flag.W > -1 && flag.preci > flag.W))
			{
				free(cur_arg);
				while(wiit.tab[i])
				{
					free(wiit.tab[i]);
					i++;
				}
				va_end(ap);
				free(wiit.pos_conv);
				free(wiit.tab);
				free(ret_tab);
				if(tmp_wide != NULL)
				{
					ft_nputstr(tmp_wide, ret_wide);
					free(tmp_wide);
				}
				return (-1);
			}
			else if (flag.conv_num == 6 || flag.conv_num == 14)
			{
				spec = ft_special_c(cur_arg, flag);
				if(!(spec.tab))
					return (-1);
				ret = ret + spec.len;
				if(!ret_tab)
				{
					j = 0;
					if(!(ret_tab = malloc(sizeof(char) * ret + 1)))
						return (0);
					while (j <= ret)
					{
						ret_tab[j] = spec.tab[j];
						j++;
					}
					tmp_wide = ft_nstrdup(ret_tab, ret);
					ret_wide = ret;
					if(tmp_wide != NULL)
						free(tmp_wide);
					tmp_wide = ft_nstrdup(ret_tab, ret);
					ret_wide = ret;
				}
				else
				{
					if(!(tmp = malloc(sizeof(char) * ret + 1)))
						return (0);
					tmp = ft_strncpypf(tmp, ret_tab, ret - spec.len, ret + 1);
					tmp = ft_strncatpf(tmp, spec.tab, ret - spec.len, spec.len);
					free(ret_tab);
					ret_tab = tmp;
					if(tmp_wide != NULL)
						free(tmp_wide);
					tmp_wide = ft_nstrdup(ret_tab, ret);
					ret_wide = ret;
				}
			}
			else
			{
				cur_arg = ft_flag_use(cur_arg, flag);
				ret = ret + ft_strlen(cur_arg);
				if(!ret_tab)
				{
					if(flag.conv_num == 0 || cur_arg == NULL)
						ret_tab = NULL;
					else
					{
						ret_tab = ft_strdup(cur_arg);
						if(tmp_wide != NULL)
							free(tmp_wide);
						tmp_wide = ft_nstrdup(ret_tab, ret);
						ret_wide = ret;
					}
				}
				else
				{
					if(!(tmp = malloc(sizeof(char) * ret + 1)))
						return (0);
					tmp = ft_strncpypf(tmp, ret_tab, ret - ft_strlen(cur_arg), ret + 1);
					tmp = ft_strncatpf(tmp, cur_arg, ret - ft_strlen(cur_arg), ft_strlen(cur_arg));
					free(ret_tab);
					ret_tab = tmp;
					if(tmp_wide != NULL)
						free(tmp_wide);
					tmp_wide = ft_nstrdup(ret_tab, ret);
					ret_wide = ret;
				}
			}
			free(cur_arg);
			free(wiit.tab[i]);
		}
		i++;
	}
	va_end(ap);
	free(wiit.pos_conv);
	free(wiit.tab);
	if(tmp_wide != NULL)
		free(tmp_wide);
	ft_nputstr(ret_tab, ret);
	free(ret_tab);
	return (ret);
}
