/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_return.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:30:58 by clundber          #+#    #+#             */
/*   Updated: 2023/11/15 12:14:45 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putnbr_return(int n)

{
	char			output;
	unsigned int	nb;
	int				count;

	count = 1;
	if (n < 0)
	{
		count += write (1, "-", 1);
		n = -n;
	}
	nb = n;
	output = nb % 10 + 48;
	if (nb / 10 != 0)
		count += ft_putnbr_return(nb / 10);
	write(1, &output, 1);
	return (count);
}
