/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_int_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okushnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 19:54:50 by okushnir          #+#    #+#             */
/*   Updated: 2021/07/26 19:54:53 by okushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	alignment_i(char *s, const char p, t_flags flag)
{
	int	res;
	int	turn;

	res = 0;
	turn = 0;
	if (flag.prec > (int)ft_strlen(s))
		res += flag.prec - (int)ft_strlen(s);
	if ((flag.width * -1) > (int)ft_strlen(s))
		turn += alignement_int_neg_wthd(s, flag, turn, p);
	else
		s = alignment_i_cond(s, p, flag, &turn);
	return (turn);
}

char	*alignment_i_cond(char *s, const char p, t_flags flag, int *turn)
{
	int	res;
	int	indicator;
	int	len;

	res = 0;
	indicator = 0;
	len = (int)ft_strlen(s);
	if (*s == '-')
		len = (int)ft_strlen(s) - 1;
	if (flag.prec > len)
	{
		indicator = 1;
		res += flag.prec - (int)ft_strlen(s);
	}
	if (flag.prec == 0)
		*turn += ft_width(s, modul(flag.width) - res + 1, 0);
	else if ((flag.width > (int)ft_strlen(s)) && indicator != 1 && flag.prec)
		s = alignement_int_no_ind(s, flag, turn, res);
	else if (flag.width > (int)ft_strlen(s) && flag.prec > (int)ft_strlen(s))
		s = alignement_int_wth_ind(s, flag, turn, res);
	if (flag.prec != 0)
		*turn += condition_int(s, indicator, res, p);
	return (s);
}

int	condition_int(char *s, int flag, int res, const char p)
{
	int		turn;
	int		i;

	turn = 0;
	i = 0;
	if (*s == '-' && p != 'u')
	{
		s++;
		res++;
		turn += 1;
		ft_putchar('-');
	}
	if (flag == 1)
	{
		while (i < res)
		{
			ft_putchar('0');
			i++;
			turn++;
		}
	}	
	ft_putstr(s);
	turn += ft_strlen(s);
	return (turn);
}

int	p_nul(int prec, int len)
{
	int	res;
	int	prout;

	res = 0;
	prout = 0;
	if (prec > len)
	{
		prout = prec - len;
		while (prout--)
			ft_putchar('0');
	}
	return (res);
}
