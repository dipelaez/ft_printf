/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dipelaez <diego.pelaez@hotmail.com.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:54:27 by dipelaez          #+#    #+#             */
/*   Updated: 2022/03/23 20:28:44 by dipelaez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
**---------------------------------Libraries------------------------------------
*/

# include    "libft.h"
# include    <stdarg.h>
# include    <stdio.h>

/*
**----------------------------------Structs-------------------------------------
*/

typedef struct s_node {
	char			c;
	struct s_node	*next;
}	t_node;

typedef struct s_data {
	va_list	ap;
	int		result;
	char	*buffer;
	int		n_print;
	t_node	*string;
	t_node	*head;
}	t_data;

/*
**-------------------------ft_printf main functions-----------------------------
*/

int		ft_printf(const char *fmt, ...);
void	check_parameter(const char **fmt, t_data *data);
void	ft_loop(t_data *data, const char **fmt, t_node *temp);

/*
**----------------------linked list management functions------------------------
*/

t_node	*ft_new_node(char c);
void	ft_add_node(t_node **node, t_node *new);
void	ft_clean_list(t_node **node);

/*
**--------------------------string related functions----------------------------
*/

void	ft_putchar(t_data *data, char c);
void	ft_putstr(t_data *data, char *str);
void	ft_strfill(char **ptr, long int nbr, int signal);

/*
**--------------------------number related functions----------------------------
*/

void	ft_putint(t_data *data, int nbr);
void	ft_putunsigint(t_data *data, unsigned int nbr);

/*
**-------------------------ft_printf utils functions----------------------------
*/

int		ft_cdigit(unsigned long int nbr, int base);
void	ft_create_buffer(t_data *data);
void	ft_itoa_helper(t_data *data, int flag);
char	*ft_itoa_base(unsigned long int nbr, int base, int upper);
void	ft_itoa_address(t_data *data);

#endif
