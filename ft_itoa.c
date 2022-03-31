/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dipelaez <diego.pelaez@hotmail.com.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:07:27 by dipelaez          #+#    #+#             */
/*   Updated: 2022/03/31 17:08:44 by dipelaez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "ft_printf.h"

char	*ft_itoa_base(unsigned int nbr, int base, int upper)
{
	const char			*hold_base;
	char				*ptr;
	char				*str;
	unsigned long int	nbr_cpy;
	int					len;

	if (upper)
		hold_base = "0123456789ABCDEF";
	else
		hold_base = "0123456789abcdef";
	nbr_cpy = nbr;
	len = ft_cdigit(nbr_cpy, base);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	ptr = &str[len];
	*ptr = '\0';
	if (!nbr)
		*(--ptr) = hold_base[nbr_cpy / base];
	while (nbr_cpy)
	{
		*(--ptr) = hold_base[nbr_cpy % base];
		nbr_cpy /= base;
	}
	return (ptr);
}

char	*ft_itoa_pointer(unsigned long int nbr, int base, int upper)
{
	const char			*hold_base;
	char				*ptr;
	char				*str;
	unsigned long int	nbr_cpy;
	int					len;

	if (upper)
		hold_base = "0123456789ABCDEF";
	else
		hold_base = "0123456789abcdef";
	nbr_cpy = nbr;
	len = ft_cdigit(nbr_cpy, base);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	ptr = &str[len];
	*ptr = '\0';
	if (!nbr)
		*(--ptr) = hold_base[nbr_cpy / base];
	while (nbr_cpy)
	{
		*(--ptr) = hold_base[nbr_cpy % base];
		nbr_cpy /= base;
	}
	return (ptr);
}

void	ft_itoa_helper(t_data *data, int flag)
{
	char	*result;

	result = ft_itoa_base(va_arg(data->ap, unsigned int), 16, flag);
	ft_putstr(data, result);
	free(result);
}

void	ft_itoa_address(t_data *data)
{
	unsigned long	ads_cpy;
	char			*prefix;
	char			*temp;
	char			*nbr;

	prefix = "0x";
	ads_cpy = va_arg(data->ap, unsigned long);
	temp = ft_itoa_pointer(ads_cpy, 16, 0);
	nbr = ft_strjoin(prefix, temp);
	if (!ft_strncmp(nbr, "0x0", 3))
	{
		prefix = "(nil)";
		ft_putstr(data, (char *)prefix);
	}
	else
		ft_putstr(data, nbr);
	free(temp);
	free(nbr);
}
