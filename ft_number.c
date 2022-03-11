/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dipelaez <diego.pelaez@hotmail.com.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:40:18 by dipelaez          #+#    #+#             */
/*   Updated: 2022/03/11 15:41:04 by dipelaez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "ft_printf.h"

void	ft_putunsigint(t_data *data, unsigned int nbr)
{
	unsigned int	n;
	char			*ptr;
	char			*str;
	int				len;

	n = nbr;
	len = ft_cdigit(n, 10);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return ;
	ptr = &str[len];
	*ptr = '\0';
	ft_strfill(&ptr, n, 0);
	ft_putstr(data, ptr);
	free(ptr);
}

void	ft_putint(t_data *data, int nbr)
{
	long int	n;
	char		*ptr;
	char		*str;
	int			signal;
	int			len;

	signal = 0;
	n = nbr;
	if (n < 0)
	{
		signal = 1;
		n = -n;
	}
	len = ft_cdigit(n, 10);
	str = malloc(sizeof(char) * (len + 1 + signal));
	if (!str)
		return ;
	ptr = &str[len + signal];
	*ptr = '\0';
	ft_strfill(&ptr, n, signal);
	ft_putstr(data, ptr);
	free(ptr);
}
