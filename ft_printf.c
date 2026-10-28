/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihammou <rihammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 10:46:49 by rihammou          #+#    #+#             */
/*   Updated: 2026/10/28 13:25:38 by rihammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		conv_check(int c, va_list args);
int		printstr(va_list args);
int		printchar(va_list args);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		size;

	i = 0;
	size = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			ft_putchar_fd(format[i], 1);
			size++;
		}
		else
		{
			size += conv_check(format[i + 1], args);
			i++;
		}
		i++;
	}
	return (size);
}
int	conv_check(int c, va_list args)
{
	if (c == '%')
		ft_putchar_fd(c, 1);
	else if (c == 'c')
		return(printchar(args));
	else if (c == 's')
		return(printstr(args));
	else if (c == 'p')
		
	return (1);

}
int printstr(va_list args)
{
	char *str;

	str = va_arg(args, char *);
	if(!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}
int printchar(va_list args)
{
	char c;

	c = va_arg(args, int);
	ft_putchar_fd(c, 1);
	return (1);
}
int hex_conv(char *ptr, va_list args)
{
	char	*base;
	long	nbr;

	nbr = &ptr;
	base = "0123456789abcdef";
	ft_putstr_fd("0x", 1);
	print_nbr(nbr, base, 16);
	return ;
}

void	print_nbr(long nbr, char *base, int length)
{
	int		remainder;
	char	*output;

	if (nbr == 0)
		return ;
	remainder = nbr % length;
	output = &base[remainder];
	print_nbr((nbr / length), base, length);
	write(1, output, 1);
}
