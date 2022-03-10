/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dipelaez <diego.pelaez@hotmail.com.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:44:59 by dipelaez          #+#    #+#             */
/*   Updated: 2022/03/10 17:27:36 by dipelaez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "ft_printf.h"

t_node	*ft_new_node(char c)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->c = c;
	node->next = NULL;
	return (node);
}

void	ft_add_node(t_node **node, t_node *new)
{
	t_node	*temp;

	temp = *node;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

void	ft_clean_list(t_node **node)
{
	t_node	*list;
	t_node	*temp;

	list = *node;
	while (list->next)
	{
		temp = list->next;
		list->next = temp->next;
		free(temp);
		temp = NULL;
	}
	free(list);
	list = NULL;
}
