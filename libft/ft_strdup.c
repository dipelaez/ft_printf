/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dipelaez <dipelaez@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 13:52:00 by dipelaez          #+#    #+#             */
/*   Updated: 2021/09/04 22:31:07 by dipelaez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strdup(const char	*s)
{
	char		*s_cpy;
	size_t		s_len;

	s_len = ft_strlen(s);
	s_cpy = (char *) malloc(s_len + 1);
	if (!s_cpy)
		return (NULL);
	ft_memcpy(s_cpy, s, s_len);
	s_cpy[s_len] = '\0';
	return (s_cpy);
}
