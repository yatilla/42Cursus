/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatilla <yatilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:03:22 by yatilla           #+#    #+#             */
/*   Updated: 2022/03/16 12:02:24 by yatilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_specifier(va_list arg, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len = ft_putchar(va_arg(arg, int));
	else if (format == 's')
		len = ft_printstr(va_arg(arg, char *));
	else if (format == 'p')
		len = ft_printptr(va_arg(arg, unsigned long long));
	else if (format == 'd' || format == 'i')
		len = ft_putnbr(va_arg(arg, int));
	else if (format == 'u')
		len = ft_print_unsign(va_arg(arg, unsigned int));
	else if (format == 'x' || format == 'X')
		len = ft_printhex(va_arg(arg, unsigned int), format);
	else if (format == '%')
		len = ft_putchar('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		returnval;
	int		i;

	va_start(arg, format);
	i = 0;
	returnval = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			returnval += format_specifier(arg, format[i]);
		}
		else
			returnval += ft_putchar(format[i]);
		i++;
	}
	va_end(arg);
	return (returnval);
}
