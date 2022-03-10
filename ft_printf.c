/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dipelaez <diego.pelaez@hotmail.com.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:23:10 by dipelaez          #+#    #+#             */
/*   Updated: 2022/03/10 17:48:22 by dipelaez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	t_data	data;
	t_node	temp;

	data.result = 0;
	data.n_print = 0;
	va_start(data.ap, fmt);
	ft_loop(&data, &fmt, &temp);
	if (data.result == 0)
		return (0);
	ft_create_buffer(&data);
	write(1, data.buffer, data.result);
	ft_clean_list(&data.string);
	free(data.buffer);
	return (data.result);
}

void	ft_loop(t_data *data, const char **fmt, t_node *temp)
{	
	while (**fmt)
	{
		if (**fmt == '%')
		{
			(*fmt)++;
			check_parameter(fmt, data);
			(*fmt)++;
		}
		else
		{
			if (data->result == 0)
				data->string = ft_new_node(**fmt);
			else
			{
				temp = ft_new_node(**fmt);
				ft_add_node(&data->string, temp);
			}
			(*fmt)++;
			data->result++;
		}
	}		
}

void	check_parameter(const char **fmt, t_data *data)
{
	if (**fmt == 'c')
		ft_putchar(data, va_arg(data->ap, int));
	else if (**fmt == 's')
		ft_putstr(data, va_arg(data->ap, char *));
	else if (**fmt == 'd' || **fmt == 'i')
		ft_putint(data, va_arg(data->ap, int));
	else if (**fmt == 'u')
		ft_putunsigint(data, va_arg(data->ap, unsigned int));
	else if (**fmt == 'x')
		ft_itoa_helper(data, 0);
	else if (**fmt == 'X')
		ft_itoa_helper(data, 1);
	else if (**fmt == 'p')
		ft_itoa_address(data);
	else if (**fmt == '%')
		ft_putchar(data, '%');
	else
		ft_putchar(data, **fmt);
}
