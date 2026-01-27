/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hilyas <hilyas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 14:53:22 by hilyas            #+#    #+#             */
/*   Updated: 2026/01/20 22:19:49 by hilyas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	process_format(char f, va_list args)
{
	if (f == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (f == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (f == 'd' || f == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (f == 'x' || f == 'X')
		return (ft_puthexnbr(va_arg(args, unsigned int), f));
	if (f == 'p')
		return (ft_putadress(va_arg(args, unsigned long)));
	if (f == '%')
		return (ft_putchar('%'));
	if (f == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));
	return (write(1, &f, 1));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total;
	int		i;

	if (write(1, "", 0) < 0)
		return (-1);
	va_start(args, format);
	total = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			total += process_format(format[i + 1], args);
			i++;
		}
		else
			total += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (total);
}
