/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_s_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okushnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 19:55:15 by okushnir          #+#    #+#             */
/*   Updated: 2021/07/26 19:55:18 by okushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	alignement_s(char *s, t_flags flag)
{
	int	indicator;
	int	sign;
	int	res;

	indicator = 0;
	sign = 0;
	res = 0;
	if (flag.width < 0)
		sign = 1;
	if (flag.prec >= 0 && flag.prec < (int)ft_strlen(s))
	{
		indicator = 1;
		flag.width = modul(flag.width) + ((int)ft_strlen(s) - flag.prec);
	}
	if ((modul(flag.width) > (int)ft_strlen(s)) && sign != 0)
	{
		res += condition(s, indicator, flag.prec, res);
		res += ft_width(s, modul(flag.width), 0);
	}
	else
		res += alignement_s_cond(s, flag, sign, indicator);
	return (res);
}

int	alignement_s_cond(char *s, t_flags flag, int sign, int indicator)
{
	int	res;

	res = 0;
	if ((modul(flag.width) > (int)ft_strlen(s)) && sign == 0)
		res += ft_width(s, modul(flag.width), flag.nul);
	res = condition(s, indicator, flag.prec, res);
	return (res);
}

int	modul(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

int	condition(char *s, int flag, int prec, int res)
{
	if (flag == 1)
	{
		res += prec;
		write(1, s, prec);
	}
	else
	{
		res += (int)ft_strlen(s);
		ft_putstr(s);
	}
	return (res);
}
