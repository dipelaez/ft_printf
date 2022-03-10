/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dipelaez <diego.pelaez@hotmail.com.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:23:10 by dipelaez          #+#    #+#             */
/*   Updated: 2022/03/10 13:27:52 by dipelaez         ###   ########.fr       */
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
		{
			fmt++;
			check_parameter(&fmt, &data);
			fmt++;
		}
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
	printf("temp = %s\n", temp);
	printf("prefix = %s\n", prefix);
	nbr = ft_strjoin(prefix, temp);
	printf("nbr = %s\n\n", nbr);
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
