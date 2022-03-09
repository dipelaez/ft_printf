/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dipelaez <dipelaez@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:15:26 by dipelaez          #+#    #+#             */
/*   Updated: 2021/08/31 19:07:14 by dipelaez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			sign;
	unsigned int	nb_unsigned;
	char			digit;

	if (n < 0)
	{
		sign = -1;
		write(fd, "-", 1);
	}
	else
		sign = 1;
	nb_unsigned = n * sign;
	if (nb_unsigned > 9)
		ft_putnbr_fd(nb_unsigned / 10, fd);
	digit = '0' + (nb_unsigned % 10);
	write(fd, &digit, 1);
}
