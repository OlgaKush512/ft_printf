/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_p_alignements_i_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okushnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 19:55:03 by okushnir          #+#    #+#             */
/*   Updated: 2021/07/26 19:55:05 by okushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	condition_p(char *s, int i, t_flags flag)
{
	int	res;

	res = 0;
	if (i == 0 && flag.prec < 0)
		res = write(1, "0x0", 3);
	else if (i == 0 && flag.prec >= 0)
	{
		res = write(1, "0x", 2) + flag.prec;
		p_nul(flag.prec, 0);
	}
	else
	{
		ft_putstr("0x");
		if (flag.prec > (int)ft_strlen(s))
		{
			p_nul(flag.prec, (int)ft_strlen(s));
			res += flag.prec + 2;
		}
		ft_putstr(s);
		if (flag.prec < 0 && modul(flag.width) < (int)ft_strlen(s))
			res += (int)ft_strlen(s) + 2;
		else if (modul(flag.width) > (int)ft_strlen(s))
			res += ft_width(s, (flag.width + 2), flag.nul) + 2 + ft_strlen(s);
	}
	return (res);
}

char	*alignement_int_no_ind(char *s, t_flags flag, int *turn, int res)
{
	if (*s == '-' && flag.nul == 1)
	{	
		if (flag.width < flag.prec)
		{
			s++;
			*turn = *turn + 1;
			*turn += ft_width(s, modul(flag.width) - res - 1, flag.nul);
		}
		else if (flag.prec == -1)
		{
			ft_putchar('-');
			s++;
			*turn = *turn + 1;
			*turn += ft_width(s, modul(flag.width) - res - 1, flag.nul);
		}
		else
			*turn += ft_width(s, modul(flag.width) - res, 0);
	}
	else
		if (flag.prec != -1 && flag.nul == 1)
			*turn += ft_width(s, modul(flag.width) - res, 0);
	else
		*turn += ft_width(s, modul(flag.width) - res, flag.nul);
	return (s);
}

char	*alignement_int_wth_ind(char *s, t_flags flag, int *turn, int res)
{
	if (*s == '-' && flag.nul == 1)
	{	
		if (flag.width > flag.prec)
			*turn += ft_width(s, flag.width - res - 1, 0);
		else
		{
			s++;
			*turn = *turn + 1;
			turn += ft_width(s, flag.width - res, 0);
		}
	}
	else if (*s == '-' && flag.nul != 1)
	{
		flag.width--;
		*turn += ft_width(s, modul(flag.width) - res, 0);
	}
	else
		*turn += ft_width(s, modul(flag.width) - res, 0);
	return (s);
}

int	alignement_int_neg_wthd(char *s, t_flags fl, int tn, const char p)
{
	int	indicator;
	int	res;

	indicator = 0;
	res = 0;
	if (fl.prec > (int)ft_strlen(s))
	{
		indicator = 1;
		res = fl.prec - (int)ft_strlen(s);
	}
	if (fl.prec != 0)
		tn += condition_int(s, indicator, res, p);
	if (*s == '-' && indicator)
		res = res + 1;
	if (fl.prec != 0)
		tn += ft_width(s, modul(fl.width) - res, 0);
	else
		tn += ft_width(s, modul(fl.width) - res + 1, 0);
	return (tn);
}
