/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihammou <rihammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 20:24:23 by rihammou          #+#    #+#             */
/*   Updated: 2026/11/09 11:13:54 by rihammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_nb(va_list args)
{
	int		nbr;
	int		count;
	long	n;

	count = 0;
	nbr = va_arg(args, int);
	n = nbr;
	ft_putnbr_fd(nbr, 1);
	if (n <= 0)
	{
		count++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	print_unb(va_list args)
{
	unsigned int	nbr;

	nbr = va_arg(args, unsigned int);
	return (print_nbr(nbr, "0123456789", 10));
}
