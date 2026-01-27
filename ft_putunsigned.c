/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hilyas <hilyas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 14:53:04 by hilyas            #+#    #+#             */
/*   Updated: 2026/01/27 18:46:29 by hilyas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int nbr)
{
	int		written;

	written = 0;
	if (nbr > 9)
		written += ft_putunsigned(nbr / 10);
	written += ft_putchar((nbr % 10) + '0');
	return (written);
}
