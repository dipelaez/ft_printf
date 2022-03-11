/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dipelaez <diego.pelaez@hotmail.com.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:33:45 by dipelaez          #+#    #+#             */
/*   Updated: 2022/03/11 15:34:58 by dipelaez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "ft_printf.h"

void	ft_putchar(t_data *data, char c)
{
	t_node	*temp;

	if (!ft_isprint(c))
		data->n_print++;
	if (data->result == 0)
		data->string = ft_new_node(c);
	else
	{
		temp = ft_new_node(c);
		ft_add_node(&data->string, temp);
	}
	data->result++;
}

void	ft_putstr(t_data *data, char *str)
{
	int			i;
	const char	*temp;

	i = 0;
	if (!str)
	{
		temp = "(null)";
		while (temp[i])
		{
			ft_putchar(data, temp[i]);
			i++;
		}
		return ;
	}
	while (str[i])
	{
		ft_putchar(data, str[i]);
		i++;
	}
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
