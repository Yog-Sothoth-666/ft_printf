/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhaldou <ykhaldou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 12:10:14 by ykhaldou          #+#    #+#             */
/*   Updated: 2026/11/13 17:51:40 by ykhaldou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_arguments(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char*)));
	else if (c == 'p')
		return (ft_putptr((unsigned long)va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putunbr(va_arg(args, int)));
	else if (c == 'x')
		return (ft_putnhex(va_arg(args, int)));
	else if (c == 'X')
		return (ft_putnHEX(va_arg(args, int)));
	else if (c == '%')
		ft_putchar('%');
	else
	{
		ft_putchar('%');
		ft_putchar(c);
	}
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar(*format);
			i++;
		}
		else
		{
			format++;
			i += ft_arguments(*format, args);
		}
		format++;
	}
	va_end(args);
	return (i);
}
