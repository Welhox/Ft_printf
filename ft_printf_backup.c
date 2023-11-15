/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:59:15 by clundber          #+#    #+#             */
/*   Updated: 2023/11/15 11:11:27 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

static int	ft_putchar(char c)

{
	write(1, &c, 1);
	return (1);
}

static int	ft_putstr(char *s)

{
	int	count;

	count = 0;
	if (!s)
	{
		write (1, "(null)", 6);
		count += 6;
		return (count);
	}
	while (*s)
	{
		write(1, s, 1);
		s++;
		count++;
	}
	return (count);
}

static int	ft_putunbr(unsigned int nbr)

{
	char			output;
	int				count;

	count = 1;
	output = nbr % 10 + 48;
	if (nbr / 10 != 0)
		count += ft_putunbr(nbr / 10);
	write(1, &output, 1);
	return (count);
}

static int	ft_putnbr(int n)

{
	char			output;
	unsigned int	nb;
	int				count;

	count = 1;
	if (n < 0)
	{
		write (1, "-", 1);
		n = -n;
		count++;
	}
	nb = n;
	output = nb % 10 + 48;
	if (nb / 10 != 0)
		count += ft_putnbr(nb / 10);
	write(1, &output, 1);
	return (count);
}

static int	ft_puthex(unsigned long nbr, int caps)

{
	int		count;
	char	*hex;
	char	output;

	count = 0;
	if (caps == 0)
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
/* 	if (nbr < 0)
		nbr = -nbr; */
	output = hex[nbr % 16];
	if (nbr / 16 != 0)
		count += ft_puthex((nbr / 16), caps);
	count += ft_putchar(output);
	return (count);
}

/* static int	ft_puthex_u(unsigned long long nbr, int caps)

{
	int		count;
	char	*hex;
	char	output;

	count = 0;
	if (caps == 0)
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	//if (nbr < 0)
	//	nbr = -nbr;
	output = hex[nbr % 16];
	if (nbr / 16 != 0)
		count += ft_puthex_u((nbr / 16), caps);
	count += ft_putchar(output);
	return (count);
} */

static int	ft_print_special(const char s, va_list ap)

{
	int	count;

	count = 0;
	if (s == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (s == 's')
		count += ft_putstr(va_arg(ap, char*));
	else if (s == 'd')
		count += ft_putnbr(va_arg(ap, int)); 
	else if (s == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (s == 'u')
		count += ft_putunbr(va_arg(ap, unsigned int));
	else if (s == 'x')
		count += ft_puthex(va_arg(ap,unsigned int), 0);
	else if (s == 'X')
		count += ft_puthex(va_arg(ap, unsigned int), 1);
	else if (s == 'p')
	{
		count += write(1, "0x", 2);
		//count += 2;
		count += ft_puthex(va_arg(ap, long long), 0);
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
		{
			write(1, &str[i], 1);
			counter++;
		}
		i++;
	}
	va_end(ap);
	return (counter);
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
