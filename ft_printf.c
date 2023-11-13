/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:59:15 by clundber          #+#    #+#             */
/*   Updated: 2023/11/13 14:01:15 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "libftprintf.h"

static int ft_puthex(long nbr, int caps)

{
	int		count;
	char	*hex;

	count = 0;
	if (caps == 0)
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
		count++;
	}
	else if (nbr > 16)
	{
		ft_puthex((nbr /= 16), caps);
		ft_putchar_fd(hex[nbr % 16], 1);
		//write(1, &hex[nbr % 16], 1);
		return (count);
	}
		else
	{
		ft_putchar_fd(hex[nbr], 1);
		count++;
		return (count);
	}



	return (count);
}

static int ft_print_special(const char s, va_list ap)

{
	int	count;

	count = 0;
	if (s == 'c')
		ft_putchar_fd(va_arg(ap, int), 1);
	else if (s == 's')
		ft_putstr_fd(va_arg(ap, char*), 1);
	else if (s == 'd')
		ft_putnbr_fd(va_arg(ap, int), 1);  //should be float?
	else if (s == 'i')
		ft_putnbr_fd(va_arg(ap, int), 1);
	else if (s == 'u')
		ft_putnbr_fd(va_arg(ap, unsigned int), 1);
	else if (s == 'x')
		count += ft_puthex(va_arg(ap, long), 0); //lowercase hex
	else if (s == 'X')
		count += ft_puthex(va_arg(ap, long), 1); //uppercase hex
	//else if (s == '%') */
	//	ft_putchar_fd(ap, s, 1); 
	else
		write(1, &s, 1);
	return (count);
}
int	ft_printf (const char *str, ...)

{
	va_list ap;
	int		counter;

	va_start(ap, str);
	counter = 0;
	while(str[counter])
	{
		if (str[counter] == '%')
		{
			counter++;
			counter += ft_print_special(str[counter], ap);
		}
		else
			write(1, &str[counter], 1);
		counter++;
	}
	va_end(ap);
	return(counter);
}
/*	Has to handle cspdiuxX%
	allowed functions: malloc, free, write, va_start, va_arg, va_copy, va_end.
	should return the ammount of printed characters.
	No buffer management
	%c Prints a single character.
	%s Prints a string (as defined by the common C convention).
	%p The void * pointer argument has to be printed in hexadecimal format.
	%d Prints a decimal (base 10) number.
	%i Prints an integer in base 10.
	%u Prints an unsigned decimal (base 10) number.
	%x Prints a number in hexadecimal (base 16) lowercase format.
	%X Prints a number in hexadecimal (base 16) uppercase format.
	%% Prints a percent sign.

*/
