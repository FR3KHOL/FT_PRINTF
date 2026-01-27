/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hilyas <hilyas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 14:52:14 by hilyas            #+#    #+#             */
/*   Updated: 2026/01/27 18:45:58 by hilyas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	get_hex_char(unsigned int n, int uppercase)
{
	if (n < 10)
		return (n + '0');
	if (uppercase)
		return (n - 10 + 'A');
	return (n - 10 + 'a');
}

int	ft_puthexnbr(unsigned int nbr, char x)
{
	int		count;
	char	c;

	count = 0;
	if (nbr > 15)
		count += ft_puthexnbr(nbr / 16, x);
	c = get_hex_char(nbr % 16, (x == 'X'));
	count += write(1, &c, 1);
	return (count);
}
