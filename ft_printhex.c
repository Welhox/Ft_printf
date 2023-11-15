/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:18:56 by clundber          #+#    #+#             */
/*   Updated: 2023/11/15 12:12:40 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned long nbr, int caps)

{
	int		count;
	char	*hex;
	char	output;

	count = 0;
	if (caps == 0)
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	output = hex[nbr % 16];
	if (nbr / 16 != 0)
		count += ft_printhex((nbr / 16), caps);
	count += ft_putchar_return(output);
	return (count);
}