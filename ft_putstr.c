/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hilyas <hilyas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 14:52:33 by hilyas            #+#    #+#             */
/*   Updated: 2026/01/27 18:46:19 by hilyas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int		pos;

	pos = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[pos])
		pos++;
	return (write(1, str, pos));
}
