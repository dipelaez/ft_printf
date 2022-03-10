/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dipelaez <diego.pelaez@hotmail.com.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 13:53:40 by dipelaez          #+#    #+#             */
/*   Updated: 2022/03/10 13:40:30 by dipelaez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (c > 127)
		c %= 256;
	while (*s)
	{
		s++;
		i++;
	}	
	while (i > 0)
	{
		if (*s == c)
			return ((char *)s);
		s--;
		i--;
	}	
	if (*s == c)
		return ((char *)s);
	return (0);
}
