/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hilyas <hilyas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 14:51:42 by hilyas            #+#    #+#             */
/*   Updated: 2026/01/27 18:45:20 by hilyas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_digit(long n)
{
	char	digit_char;

	digit_char = n + '0';
	return (write(1, &digit_char, 1));
}

static int	recursive_print(long n)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		count += recursive_print(n / 10);
		count += write_digit(n % 10);
	}
	else
		count += write_digit(n);
	return (count);
}

int	ft_putnbr(long nbr)
{
	int		count;

	count = 0;
	if (nbr < 0)
	{
		count += write(1, "-", 1);
		nbr = -nbr;
	}
	count += recursive_print(nbr);
	return (count);
}
