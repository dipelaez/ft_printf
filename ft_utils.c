/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dipelaez <diego.pelaez@hotmail.com.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:53:11 by dipelaez          #+#    #+#             */
/*   Updated: 2022/03/10 13:45:39 by dipelaez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "ft_printf.h"

int	ft_cdigit(long int nbr)
{
	int	len;

	if (nbr == 0)
		return (1);
	len = 0;
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

void	ft_strfill(char **ptr, long int n, int signal)
{
	if (n == 0)
		*(--*ptr) = '0';
	while (n > 0)
	{
		*(--*ptr) = n % 10 + '0';
		n /= 10;
	}
	if (signal == 1)
		*(--*ptr) = '-';
}

void	ft_putunsigint(t_data *data, unsigned int nbr)
{
	unsigned int	n;
	char			*ptr;
	char			*str;
	int				len;

	n = nbr;
	len = ft_cdigit(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return ;
	ptr = &str[len];
	*ptr = '\0';
	ft_strfill(&ptr, n, 0);
	ft_putstr(data, ptr);
	free(ptr);
}

void	ft_create_buffer(t_data *data)
{
	int		i;
	t_node	*temp;

	data->buffer = malloc(sizeof(char) * data->result);
	i = 0;
	temp = data->string;
	while (temp->next != NULL)
	{
		data->buffer[i] = temp->c;
		i++;
		temp = temp->next;
	}
	data->buffer[i] = temp->c;
}

char	*ft_itoa_base(unsigned long int n, int base, int upper)
{
	const char			*hold_base;
	char				*ptr;
	char				*str;
	unsigned long int	n_cpy;
	int					len;

	if (upper)
		hold_base = "0123456789ABCDEF";
	else
		hold_base = "0123456789abcdef";
	n_cpy = n;
	len = ft_cdigit_unsigned(n_cpy, base);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	ptr = &str[len];
	*ptr = '\0';
	if (!n)
		*(--ptr) = hold_base[n_cpy / base];
	while (n_cpy)
	{
		*(--ptr) = hold_base[n_cpy % base];
		n_cpy /= base;
	}
	return (ptr);
}

void	ft_itoa_helper(t_data *data, int flag)
{
	char	*result;

	result = ft_itoa_base(va_arg(data->ap, unsigned long int), 16, flag);
	ft_putstr(data, result);
	free(result);
}

int	ft_cdigit_unsigned(unsigned long int x, int base)
{
	int	len;

	if (x == 0)
		return (1);
	len = 0;
	while (x > 0)
	{
		x /= base;
		len++;
	}
	return (len);
}

void	ft_itoa_address(t_data *data)
{
	unsigned long	ads_cpy;
	char			*prefix;
	char			*temp;
	char			*nbr;

	prefix = "0x";
	ads_cpy = va_arg(data->ap, unsigned long);
	temp = ft_itoa_base(ads_cpy, 16, 0);
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
