/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihammou <rihammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 10:46:49 by rihammou          #+#    #+#             */
/*   Updated: 2026/10/28 15:13:10 by rihammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printstr(va_list args)
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

int	printchar(va_list args)
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
		return (printchar(args));
	else if (c == 's')
		return (printstr(args));
	else if (c == 'p')
		return (hex_conv(args));
	else if (c == 'd' || c == 'i')
		return (print_nb(args));
	else if (c == 'u')
		return (print_unb(args));
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
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int a;
    int b;

    a = printf("Normal: %u\n", 42u);
    fflush(stdout);
    b = ft_printf("Normal: %u\n", 42u);
    printf("Return: %d | %d\n\n", a, b);

    a = printf("Zero: %u\n", 0u);
    fflush(stdout);
    b = ft_printf("Zero: %u\n", 0u);
    printf("Return: %d | %d\n\n", a, b);

    a = printf("UINT_MAX: %u\n", UINT_MAX);
    fflush(stdout);
    b = ft_printf("UINT_MAX: %u\n", UINT_MAX);
    printf("Return: %d | %d\n\n", a, b);

    a = printf("INT_MAX: %u\n", (unsigned int)INT_MAX);
    fflush(stdout);
    b = ft_printf("INT_MAX: %u\n", (unsigned int)INT_MAX);
    printf("Return: %d | %d\n\n", a, b);

    a = printf("Negative cast: %u\n", (unsigned int)-1);
    fflush(stdout);
    b = ft_printf("Negative cast: %u\n", (unsigned int)-1);
    printf("Return: %d | %d\n\n", a, b);

    a = printf("Multiple: %u %u %u\n", 0u, 42u, UINT_MAX);
    fflush(stdout);
    b = ft_printf("Multiple: %u %u %u\n", 0u, 42u, UINT_MAX);
    printf("Return: %d | %d\n", a, b);

    return (0);
}