/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:27:09 by clundber          #+#    #+#             */
/*   Updated: 2023/11/13 17:18:18 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"

int	ft_printf (const char *, ...);

int	main(void)

{
	int	a = 10;
	void *b = &a;

printf("%c\n", '?');
ft_printf("%c\n", '?');

/* printf("OG %c\n", '0');
ft_printf("FT %c\n", '0');

printf("OG%c\n", '0');
ft_printf("FT%c\n", '0');
printf("OG %c \n", '0');
ft_printf("FT %c \n", '0');
printf("OG %c\n", '0' - 256);
ft_printf("FT %c\n", '0' - 256);
printf("OG%c \n", '0' + 256);
ft_printf("FT%c \n", '0' + 256);
printf("OG %c %c %c \n", '0', 0, '1');
ft_printf("FT %c %c %c \n", '0', 0, '1');
printf("OG %c %c %c \n", ' ', ' ', ' ');
ft_printf("FT %c %c %c \n", ' ', ' ', ' ');
printf("OG %c %c %c \n", '1', '2', '3');
ft_printf("FT %c %c %c \n", '1', '2', '3');
printf("OG %c %c %c \n", '2', '1', 0);
ft_printf("FT %c %c %c \n", '2', '1', 0);
printf("OG %c %c %c \n", 0, '1', '2');
ft_printf("FT %c %c %c \n", 0, '1', '2'); */














printf("OG This is %% test %s\n", "Hello");
ft_printf("FT This is %% test %s\n", "Hello");

printf("OG This is str test %s\n", "Hello");
ft_printf("FT This is str test %s\n", "Hello");

printf("OG This is int test %i\n", 42);
ft_printf("FT This is int test %i\n", 42);

printf("OG This is d int test %d\n", 1337);
ft_printf("FT This is d int test %d\n", 1337);

printf("OG This is u int test %d\n", -123456789);
ft_printf("FT This is u int test %d\n", -123456789);

printf("OG This is low hex test %x\n", 25135135);
ft_printf("FT This is low hex test %x\n", 25135135);

printf("OG This is HIGH hex test %X\n", -344897534);
ft_printf("FT This is HIGH hex test %X\n", -344897534);

printf("OG void pointer test = %p\n", b);
ft_printf("FT void pointer test = %p\n", b);

printf("OG = %i\n", printf("OG Testing %s %s okei %i and do  not forget the %i hexas coming up %x and %%sign\n", "Mamma", "mia", 42, -27, 258943));
printf("FT = %i\n", ft_printf("FT Testing %s %s okei %i and do  not forget the %i hexas coming up %x and %%sign\n", "Mamma", "mia", 42, -27, 258943));

//printf("%i", write(1, "Hello", 5));
}