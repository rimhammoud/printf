/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihammou <rihammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 12:56:29 by rihammou          #+#    #+#             */
/*   Updated: 2026/11/09 10:26:41 by rihammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <stdarg.h>
#include "libft/libft.h"

int		hex_conv(va_list args);
int		print_nb(va_list args);
int		print_unb(va_list args);
int		print_hex(va_list args, int c);
int		ft_printf(const char *format, ...);
int		flags_check(int c, va_list args, const char *str);
int		print_str(va_list args);
int		conv_check(int c, va_list args);
#endif