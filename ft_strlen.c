/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 11:44:53 by cholm             #+#    #+#             */
/*   Updated: 2018/03/15 13:39:01 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlen(const char *s)
{
	int				i;
	const char		*str;
	size_t			len;

	i = 0;
	len = 0;
	str = s;
	while (str[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}
