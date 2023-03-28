/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okushnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 19:54:12 by okushnir          #+#    #+#             */
/*   Updated: 2021/07/26 19:54:14 by okushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	spec(const char p, va_list ap)
{
	int		res;

	res = 0;
	if (p == '%')
	{
		res = 1;
		ft_putchar('%');
	}
	else if (p == 'c')
		res = spec_c(ap);
	else if (p == 's')
		res = spec_s(ap);
	else if ((p == 'd' || p == 'i' || p == 'u'))
		res = spec_int(p, ap);
	else if (p == 'x' || p == 'X')
		res = spec_hex(p, ap);
	else if (p == 'p')
		res = spec_p(ap);
	return (res);
}

int	spec_c(va_list ap)
{
	int	i;

	i = 0;
	i = va_arg(ap, int);
	write(1, &i, 1);
	return (1);
}

int	spec_s(va_list ap)
{
	char	*s;
	int		res;

	res = 0;
	s = NULL;
	s = va_arg(ap, char *);
	if (s)
	{
		ft_putstr(s);
		res = (int)ft_strlen(s);
	}
	else
	{
		ft_putstr("(null)");
		res = 6;
	}
	return (res);
}

int	spec_int(const char p, va_list ap)
{
	long long	i;
	char		*s;
	int			res;

	i = 0;
	res = 0;
	if (p == 'd' || p == 'i')
	{
		i = va_arg(ap, int);
		s = convert(i, 10);
		res = (int)ft_strlen(s);
	}
	else
	{
		i = va_arg(ap, unsigned int);
		s = convert(i, 10);
		res = (int)ft_strlen(s);
	}
	ft_putstr(s);
	return (res);
}

int	spec_hex(const char p, va_list ap)
{
	long long	i;
	char		*s;
	int			res;

	i = 0;
	res = 0;
	if (p == 'x' || p == 'X')
	{
		i = va_arg(ap, unsigned int);
		s = convert(i, 16);
		res = (int)ft_strlen(s);
		if (p == 'x')
			ft_putstr(s);
		else if (p == 'X')
			ft_putstr(toup(s));
	}
	else if (i == 0)
		res += write(1, "0x0", 3);
	return (res);
}
