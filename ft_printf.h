/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hilyas <hilyas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 14:53:40 by hilyas            #+#    #+#             */
/*   Updated: 2026/01/20 22:20:05 by hilyas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putstr(char *str);
int	ft_putnbr(long n);
int	ft_puthexnbr(unsigned int n, char spec);
int	ft_putunsigned(unsigned int n);
int	ft_putchar(int c);
int	ft_putadress(unsigned long ptr);

#endif