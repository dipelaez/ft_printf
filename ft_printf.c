/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dipelaez <diego.pelaez@hotmail.com.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:23:10 by dipelaez          #+#    #+#             */
/*   Updated: 2022/03/09 16:59:23 by dipelaez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	t_data	data;
	t_node	*temp;

	data.result = 0;
	data.n_print = 0;
	va_start(data.ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
			check_parameter(&fmt, &data);
		else
		{
			if (data.result == 0)
				data.string = ft_new_node(*fmt);
			else
			{
				temp = ft_new_node(*fmt);
				ft_add_node(&data.string, temp);
			}
			fmt++;
			data.result++;
		}
	}
	if (data.result == 0)
		return (0);
	ft_create_buffer(&data);
	write(1, data.buffer, data.result);
	ft_clean_list(&data.string);
	free(data.buffer);
	return (data.result);
}

void	check_parameter(const char **fmt, t_data *data)
{
	**fmt++;
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
    **fmt++;
}

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
	len = ft_cdigit(n);
	str = malloc(sizeof(char) * (len + 1 + signal));
	if (!str)
		return ;
	ptr = &str[len + signal];
	*ptr = '\0';
	ft_strfill(&ptr, n, signal);
	ft_putstr(data, ptr);
	free(ptr);
}
