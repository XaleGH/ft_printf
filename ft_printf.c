/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:58:12 by asaux             #+#    #+#             */
/*   Updated: 2023/10/25 10:55:16 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		;
	return (i);
}

void	put_format(int conv, va_list liste, int *count)
{
	if (conv == 'c')
		ft_putchar(va_arg(liste, int), count);
	else if (conv == 's')
		ft_putstr(va_arg(liste, char *), count);
	else if (conv == 'p')
		print_address(liste, count);
	else if (conv == 'd' || conv == 'i')
		ft_putnbr(va_arg(liste, int), count);
	else if (conv == 'u')
		ft_putnbr_ui(va_arg(liste, unsigned int), "0123456789", count);
	else if (conv == 'x')
		ft_putnbr_ui(va_arg(liste, unsigned int), "0123456789abcdef", count);
	else if (conv == 'X')
		ft_putnbr_ui(va_arg(liste, unsigned int), "0123456789ABCDEF", count);
	else if (conv == '%')
		ft_putchar(conv, count);
}

void	print_address(va_list liste, int *count)
{
	unsigned long	pvalue;

	pvalue = va_arg(liste, unsigned long);
	if (!pvalue)
		ft_putstr("(nil)", count);
	else
	{
		ft_putstr("0x", count);
		ft_putnbr_ul(pvalue, "0123456789abcdef", count);
	}
}

int	check_conv(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%');
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	liste;

	i = 0;
	count = 0;
	va_start(liste, format);
	while (format[i])
	{
		if (format[i] != '%')
			ft_putchar(format[i], &count);
		else
		{
			i++;
			if (check_conv(format[i]))
				put_format(format[i], liste, &count);
		}
		i++;
	}
	va_end(liste);
	return (count);
}
