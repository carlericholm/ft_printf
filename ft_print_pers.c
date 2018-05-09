/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 12:24:33 by cholm             #+#    #+#             */
/*   Updated: 2018/05/09 18:13:03 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_temp_perc(t_point *elem)
{
	char	*temp;
	int		i;

	i = 0;
	temp = ft_strnew(elem->width);
	while (i < elem->width - 1)
	{
		if (elem->opt & (1 << 2))
			temp[i] = '0';
		else
			temp[i] = ' ';
		i++;
	}
	return (temp);
}

char			*ft_in_print_perc(t_point *elem)
{
	char	*str;
	char	*temp;
	int		i;
	char	*ptr_trash;

	i = 0;
	str = ft_strnew(1);
	ptr_trash = str;
	str[0] = elem->convert;
	if (elem->width > 0)
	{
		temp = ft_temp_perc(elem);
		if (elem->opt & (1 << 0))
			str = ft_strjoin(str, temp);
		else
			str = ft_strjoin(temp, str);
		free(ptr_trash);
		free(temp);
	}
	return (str);
}

int				ft_printf_perc(t_point *elem)
{
	char	*str;
	int		length;

	str = NULL;
	if (elem->convert == '%')
	{
		str = ft_strnew(1);
		str[0] = elem->convert;
		return (ft_call_options(str, elem));
	}
	else
		str = ft_in_print_perc(elem);
	ft_putstr(str);
	length = ft_strlen(str);
	free(str);
	return (length);
}

int				ft_printf_big_s(va_list args, t_point *elem)
{
	wchar_t	*str_bis;
	int		i;
	char	*temp;
	char	*temp_bis;
	char	*ptr_trash;

	i = 0;
	temp_bis = ft_strnew(1);
	ptr_trash = NULL;
	if (elem->convert == 'S')
	{
		str_bis = va_arg(args, wchar_t *);
		if (str_bis == NULL)
		{
			ft_putstr("(null)");
			free(temp_bis);
			return (6);
		}
		while (str_bis[i])
		{
			ptr_trash = temp_bis;
			temp = ft_wchar_c(elem, str_bis[i]);
			temp_bis = ft_strjoin(temp_bis, temp);
			free(ptr_trash);
			free(temp);
			i++;
		}
		return (ft_call_options(temp_bis, elem));
	}
	return (0);
}

int				ft_printf_s(va_list args, t_point *elem)
{
	char	*str;
	char	*temp_arg;
	int		length;

	length = 0;
	if (elem->opt & (1 << 9))
	{
		elem->convert = 'S';
		return (ft_printf_big_s(args, elem));
	}
	if (elem->convert == 's')
	{
		if (elem->opt & (1 << 13))
			return (0);
		temp_arg = va_arg(args, char *);
		if (temp_arg == NULL)
			str = ft_strdup("(null)");
		else
			str = ft_strdup(temp_arg);
		ft_precision_s(elem, &str, length);
		length = ft_strlen(str);
		ft_width_flag_s(elem, &str, length);
		ft_putstr(str);
		free(str);
		return (ft_strlen(str));
	}
	return (0);
}

void			ft_sign(t_point *elem, char **str)
{
	char	*temp;
	char	*ptr_trash;

	ptr_trash = *str;
	if (elem->sign < 0)
	{
		temp = ft_strnew(1);
		temp[0] = '-';
		*str = ft_strjoin(temp, *str);
		free(ptr_trash);
		free(temp);
	}
	if (elem->opt & (1 << 1) && elem->sign > 0 &&
			elem->convert != 'u' &&
			elem->convert != 'o' && elem->convert != 'O')
	{
		temp = ft_strnew(1);
		temp[0] = '+';
		*str = ft_strjoin(temp, *str);
		free(ptr_trash);
		free(temp);
	}
	elem->sign = 0;
}
