/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hilyas <hilyas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 14:51:59 by hilyas            #+#    #+#             */
/*   Updated: 2026/01/20 22:20:18 by hilyas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_hex_char(unsigned long n)
{
	char	hex_char;

	if (n < 10)
		hex_char = n + '0';
	else
		hex_char = n - 10 + 'a';
	return (write(1, &hex_char, 1));
}

static int	recursive_hex(unsigned long n)
{
	int	total;

	total = 0;
	if (n > 15)
	{
		total += recursive_hex(n / 16);
		total += print_hex_char(n % 16);
	}
	else
		total += print_hex_char(n);
	return (total);
}

int	ft_putadress(unsigned long point)
{
	int	result;

	result = write(1, "0x", 2);
	if (point == 0)
		result += write(1, "0", 1);
	else
		result += recursive_hex(point);
	return (result);
}
