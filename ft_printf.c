/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:59:15 by clundber          #+#    #+#             */
/*   Updated: 2023/11/10 18:09:11 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


static void ft_print_special(const char s, va_list ap)

{
	int	count;

	count = 0;
	if (s == 'c')
		count += ft_putchar_fd(ap, char, 1);
	else if (s == s)
		count += ft_putstr(ap, char*, 1);
	else if (s == d)
		count += ft_putnbr_fd(ap, int, 1);  //should be float?
	else if (s == i)
		count += ft_putnbr_fd(ap, int, 1);
	else if (s == u)
		count += ft_putnbr_fd(ap, int, 1); //unsigned decimal
	else if (s == x)
		count += ft_puthex(ap, int); //lowercase hex
	else if (s == X)
		count += ft_puthex(ap, int); //uppercase hex
	else if (s == %)
			count += ft_putchar_fd(ap, char, 1);
	else
		count += write(1, &s, 1);
	return (count);
}
int	ft_printf (const char *str, ...)

{
	va_list ap;
	int		counter;

	va_start(ap, str);
	counter = 0;
	while(*str)
	{
		if (*str == %)
		{
			count++;
			count += ft_print_special(*s, ap);
		}
		else
			write(1, str, 1);
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
