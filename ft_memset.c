/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:16:00 by cholm             #+#    #+#             */
/*   Updated: 2017/11/10 17:41:14 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*b;

	i = 0;
	b = s;
	while (i < n)
	{
		b[i] = (char)c;
		i++;
	}
	return (s);
}
