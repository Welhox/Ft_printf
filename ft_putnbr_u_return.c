/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u_return.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber <clundber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:33:47 by clundber          #+#    #+#             */
/*   Updated: 2023/11/15 12:14:28 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putnbr_u_return(unsigned int nbr)

{
	char			output;
	int				count;

	count = 1;
	output = nbr % 10 + 48;
	if (nbr / 10 != 0)
		count += ft_putnbr_u_return(nbr / 10);
	write(1, &output, 1);
	return (count);
}
