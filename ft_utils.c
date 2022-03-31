/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dipelaez <diego.pelaez@hotmail.com.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:53:11 by dipelaez          #+#    #+#             */
/*   Updated: 2022/03/31 17:09:25 by dipelaez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "ft_printf.h"

int	ft_cdigit(unsigned long int nbr, int base)
{
	int	len;

	if (nbr == 0)
		return (1);
	len = 0;
	while (nbr > 0)
	{
		nbr /= base;
		len++;
	}
	return (len);
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
