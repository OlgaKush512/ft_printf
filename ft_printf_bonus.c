/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okushnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 19:53:32 by okushnir          #+#    #+#             */
/*   Updated: 2021/07/26 19:53:37 by okushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	init_flag(t_flags *flag)
{
	flag->nul = 0;
	flag->prec = -1;
	flag->width = 0;
	flag->diez = 0;
	flag->plus = 0;
	flag->espace = 0;
	flag->turn = 0;
}

const char	*flags_diez_plus_espace(t_flags *flag, const char *p, int *minus)
{
	while (*p == '#' || *p == '+' || *p == ' ' || *p == '-')
	{
		if (*p == '#')
			flag->diez = 1;
		if (*p == '+')
			flag->plus = 1;
		if (*p == ' ')
			flag->espace = 1;
		if (*p == '-')
			*minus = 1;
		p++;
	}
	return (p);
}

const char	*fill_up_flag(t_flags *flag, const char *p)
{
	int	minus;

	minus = 0;
	p = flags_diez_plus_espace(flag, p, &minus);
	if (*p == '0')
	{
		flag->nul = 1;
		p++;
	}
	if ((*p >= '0' && *p <= '9') || *p == '-')
	{
		flag->width = ft_atoi(p);
		if (minus && flag->width >= 0)
			flag->width = flag->width * -1;
		while ((*p >= '0' && *p <= '9') || *p == '-')
			p++;
	}
	if (*p == '.')
	{
		p++;
		flag->prec = ft_atoi(p);
		while ((*p >= '0' && *p <= '9') || *p == '.')
			p++;
	}
	return (p);
}

int	check_spec(const char *p)
{
	const char	*p1;

	p1 = p;
	if (*p1 == '%' && ft_strlen(p1) > 1)
	{
		p1++;
		while (((*p1 >= '0' && *p1 <= '9') || *p1 == '-' || *p1 == '+'
				|| *p1 == '.' || *p1 == ' ' || *p1 == '#') && *p1 != '\0')
			p1++;
		if (*p1 == 'd' || *p1 == 'u' || *p1 == 'i' || *p1 == 'x'
			|| *p1 == 'X' || *p1 == 'p' || *p1 == 'c'
			|| *p1 == 's' || *p1 == '%')
			return (1);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	const char	*p;
	va_list		ap;
	t_flags		flag;

	p = format;
	va_start(ap, format);
	init_flag(&flag);
	while (*p != '\0')
	{
		if (*p != '%')
		{
			flag.turn++;
			ft_putchar(*p);
		}
		else if (check_spec(p++))
		{
			p = fill_up_flag(&flag, p);
			flag.turn += spec(*p, ap, flag);
		}
		else if (!check_spec(p))
			ft_putstr("Error");
		p++;
	}
	va_end(ap);
	return (flag.turn);
}
