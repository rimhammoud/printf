/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihammou <rihammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 10:46:49 by rihammou          #+#    #+#             */
/*   Updated: 2026/11/09 10:23:44 by rihammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	print_char(va_list args)
{
	char	c;

	c = va_arg(args, int);
	ft_putchar_fd(c, 1);
	return (1);
}

int	conv_check(int c, va_list args)
{
	if (c == '%')
	{
		ft_putchar_fd(c, 1);
		return (1);
	}
	else if (c == 'c')
		return (print_char(args));
	else if (c == 's')
		return (print_str(args));
	else if (c == 'p')
		return (hex_conv(args));
	else if (c == 'd' || c == 'i')
		return (print_nb(args));
	else if (c == 'u')
		return (print_unb(args));
	else if (c == 'x' || c == 'X')
		return (print_hex(args, c));
	return (0);
}

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
	va_end(args);
	return (size);
}
