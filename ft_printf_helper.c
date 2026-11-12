/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhaldou <ykhaldou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 13:35:35 by ykhaldou          #+#    #+#             */
/*   Updated: 2026/11/12 11:44:34 by ykhaldou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
		i++;
	return (write(1, str, i));
}

int	ft_putnbr(long n)
{	int		i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i += ft_putchar('-');
	}
	if (n >= 10)
		i += ft_putnbr(n / 10);
	i += ft_putchar('0' + n % 10);
	return (i);
}

int	ft_putunbr(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 10)
		i+= ft_putunbr(n / 10);
	i += ft_putchar('0' + n % 10);
	return (i);
}

int	ft_putnhex(unsigned long n)
{
	int		i;
	char	basex[] = "0123456789abcdef";

	i = 0;
	if (n >= 16)
		i+= ft_putnhex(n / 16);
	i += ft_putchar(basex[n % 16]);
	return (i);
}

int	ft_putnHEX(unsigned long n)
{
	int		i;
	char	basex[] = "0123456789ABCDEF";

	i = 0;
	if (n >= 16)
		i+= ft_putnhex(n / 16);
	i += ft_putchar(basex[n % 16]);
	return (i);
}

int	ft_putptr(unsigned long addr)
{
	int i;

	i = 0;
	if (!addr)
		return (ft_putstr("(nil)"));
	i += ft_putstr("0x");
	i += ft_putnhex(addr);
	return (i);
}
