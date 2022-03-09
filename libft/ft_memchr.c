/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dipelaez <dipelaez@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 13:50:47 by dipelaez          #+#    #+#             */
/*   Updated: 2021/08/19 13:50:49 by dipelaez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*i;

	if (c > 127)
		c %= 256;
	i = (unsigned char *)s;
	while (n--)
	{
		if (*i == (unsigned char)c)
			return (i);
		i++;
	}
	return (0);
}
