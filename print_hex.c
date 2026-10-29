/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihammou <rihammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 13:20:21 by rihammou          #+#    #+#             */
/*   Updated: 2026/10/29 10:45:32 by rihammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_nbr(unsigned long nbr, char *base, int length)
{
	int		count;
	int		remainder;

	count = 0;
	if (nbr >= (unsigned long)length)
		count += print_nbr(nbr / length, base, length);
	remainder = nbr % length;
	write(1, &base[remainder], 1);
	return (count + 1);
}

int	hex_conv(va_list args)
{
	char			*base;
	unsigned long	nbr;

	nbr = (unsigned long)va_arg(args, void *);
	if (nbr == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	base = "0123456789abcdef";
	ft_putstr_fd("0x", 1);
	return (2 + print_nbr(nbr, base, 16));
}

int	print_hex(va_list args, int c)
{
	unsigned int	nbr;

	nbr = va_arg(args, unsigned int);
	if (c == 'X')
		return (print_nbr(nbr, "0123456789ABCDEF", 16));
	return (print_nbr(nbr, "0123456789abcdef", 16));
}
