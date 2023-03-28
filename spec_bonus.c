/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okushnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 19:54:24 by okushnir          #+#    #+#             */
/*   Updated: 2021/07/26 19:54:28 by okushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	spec(const char p, va_list ap, t_flags flag)
{
	int		res;

	res = 0;
	if (p == '%')
	{
		res = alignment_perc(flag.width, flag.nul);
	}
	else if (p == 'c')
		res = spec_c(ap, flag);
	else if (p == 's')
		res = spec_s(ap, flag);
	else if ((p == 'd' || p == 'i' || p == 'u' || p == 'x' || p == 'X' ))
		res = spec_int(p, ap, flag);
	else if (p == 'p')
		res = spec_p(ap, flag);
	return (res);
}

int	spec_c(va_list ap, t_flags flag)
{
	int		i;
	char	*s;
	int		res;

	res = 0;
	i = va_arg(ap, int);
	if (i == 0)
		res = alignment_c("\0", flag.nul, flag.width);
	s = ft_strnew(2);
	s[0] = i;
	if (s[0] == '\0' && flag.width == 0)
		res = 1;
	else if (s[0] != '\0')
		res = alignment_c(s, flag.nul, flag.width);
	free(s);
	return (res);
}

int	spec_s(va_list ap, t_flags flag)
{
	char	*s;
	int		res;

	res = 0;
	s = NULL;
	s = va_arg(ap, char *);
	if (s)
		res = alignement_s(s, flag);
	else
		res = alignement_s("(null)", flag);
	return (res);
}

int	spec_int(const char p, va_list ap, t_flags flag)
{
	long long	i;
	char		*s;
	int			res;

	i = 0;
	res = 0;
	s = NULL;
	if (p == 'u' || p == 'd' || p == 'i')
	{
		if (p == 'u')
			i = va_arg(ap, unsigned int);
		else if (p == 'd' || p == 'i')
			i = va_arg(ap, int);
		s = convert(i, 10, flag, p);
	}
	else if (p == 'x' || p == 'X')
	{
		i = va_arg(ap, unsigned int);
		s = convert(i, 16, flag, p);
		if (p == 'X')
			toup(s);
	}
	res += alignment_i(s, p, flag);
	return (res);
}

int	spec_p(va_list ap, t_flags flag)
{
	void		*i;
	char		*s;
	int			res;

	res = 0;
	i = va_arg(ap, void *);
	s = convert_p((uintptr_t)i, 16, flag, 'p');
	if ((flag.width > (int)ft_strlen(s)))
	{
		if (i == 0 && flag.prec < 0)
			res += ft_width(s, flag.width - 2, flag.nul) + write(1, "0x0", 3);
		else if (i == 0 && flag.prec >= 0)
			res += ft_width(s, flag.width - 1, flag.nul) + write(1, "0x", 2);
		else
		{
			res += ft_width(s, flag.width - 2, flag.nul) + 2
				+ (int)ft_strlen(s);
			ft_putstr("0x");
			p_nul(flag.prec, (int)ft_strlen(s));
			ft_putstr(s);
		}
	}
	else
		res += condition_p(s, (uintptr_t)i, flag);
	return (res);
}
