/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okushnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 19:52:55 by okushnir          #+#    #+#             */
/*   Updated: 2021/07/26 19:52:57 by okushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	const char	*p;
	va_list		ap;
	int			res;

	p = format;
	va_start(ap, format);
	res = 0;
	while (*p != '\0')
	{
		if (*p != '%')
		{
			res++;
			ft_putchar(*p);
		}
		else if (*p == '%')
		{
			p++;
			res += spec(*p, ap);
		}
		p++;
	}
	va_end(ap);
	return (res);
}
