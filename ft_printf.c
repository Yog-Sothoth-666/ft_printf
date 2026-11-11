/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhaldou <ykhaldou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 12:10:14 by ykhaldou          #+#    #+#             */
/*   Updated: 2026/11/11 15:33:25 by ykhaldou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_arguments(char c, va_list args)
{
				if (c == 'c')
			{
				return (ft_putchar(va_arg(args, int)));
			}
			// else if (c == 's')
			// {}
			// else if (c == 'p')
			// {}
			// else if (c == 'd')
			// {}
			// else if (c == 'i')
			// {}
			// else if (c == 'u')
			// {}
			// else if (c == 'x')
			// {}
			// else if (c == 'X')
			// {}
			// else if (c == '%')
			// {}
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
