/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihammou <rihammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 16:35:41 by rihammou          #+#    #+#             */
/*   Updated: 2026/11/04 13:58:38 by rihammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	align(va_list args, const char *str)
{
	int	i;
	int	len;
	int	width;
	int	size;

	i = 0;
	size = 0;
	if (ft_isdigit(*str))
	{
		width = ft_atoi(str);
		while (ft_isdigit(*str))
    		str++;
		len = conv_check(*str, args, str, 1);
		size =  width - len;
		while (i < size)
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
		return (i + len);
	}
	else
		return (conv_check(*str, args, str, 1));
}

int	flags_check(int c, va_list args, const char *str)
{
	if (c == '-')
		align(args, str);
}
// int	print_zero(va_list args, const char *str)
// {
// 	int	i;
	
// 	i = ft_atoi(str) - ft_strlen(args);
// 	while (i > 0)
// 	{
// 		ft_putchar_fd('0', 1);
// 		i--;
// 	}
// 	print_str(args);
// }