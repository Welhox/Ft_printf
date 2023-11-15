/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:59:15 by clundber          #+#    #+#             */
/*   Updated: 2023/11/15 12:15:12 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

static int	ft_print_special(const char s, va_list ap)

{
	int	count;

	count = 0;
	if (s == 'c')
		count += ft_putchar_return(va_arg(ap, int));
	else if (s == 's')
		count += ft_putstr_return(va_arg(ap, char *));
	else if (s == 'd' || s == 'i')
		count += ft_putnbr_return(va_arg(ap, int));
	else if (s == 'u')
		count += ft_putnbr_u_return(va_arg(ap, unsigned int));
	else if (s == 'x')
		count += ft_printhex(va_arg(ap, unsigned int), 0);
	else if (s == 'X')
		count += ft_printhex(va_arg(ap, unsigned int), 1);
	else if (s == 'p')
	{
		count += write(1, "0x", 2);
		count += ft_printhex(va_arg(ap, long long), 0);
	}
	else
		count += write(1, &s, 1);
	return (count);
}

int	ft_printf(const char *str, ...)

{
	va_list	ap;
	int		counter;
	int		i;

	i = 0;
	va_start(ap, str);
	counter = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			counter += ft_print_special(str[i], ap);
		}
		else
			counter += write(1, &str[i], 1);
		i++;
	}
	va_end(ap);
	return (counter);
}
