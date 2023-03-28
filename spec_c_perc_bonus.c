/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_c_perc_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okushnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 19:54:37 by okushnir          #+#    #+#             */
/*   Updated: 2021/07/26 19:54:39 by okushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	alignment_c(char *s, int nul, int width)
{
	int	res;

	res = 0;
	if (width > 1)
	{
		if (*s == '\0')
		{
			res += ft_width("1", width, nul) + 1;
			write(1, "\0", 1);
		}
		else
		{
			res += ft_width(s, width, nul);
			res += (int)ft_strlen(s);
			ft_putstr(s);
		}
	}
	else
		res = condition_c(s, nul, width);
	return (res);
}

int	condition_c(char *s, int nul, int width)
{
	int	res;

	res = 0;
	res += (int)ft_strlen(s);
	if (*s == '\0')
	{
		write(1, "\0", 1);
		res += ft_width("1", width, nul) + 1;
	}
	else
	{
		ft_putstr(s);
		res += ft_width(s, width, nul);
	}
	return (res);
}

int	ft_width(char *s, int width, int nul)
{
	int	len;
	int	k;
	int	res;

	len = ft_strlen(s);
	k = 0;
	res = 0;
	if (modul(width) > len)
	{
		width = modul(width);
		res = width - len;
		while (k < (width - len))
		{
			if (nul != 0)
				ft_putchar('0');
			else
				ft_putchar(' ');
			k++;
		}
	}
	return (res);
}

int	alignment_perc(int width, int nul)
{
	int	res;

	res = 0;
	if (modul(width) > 1)
	{
		res += modul(width);
		if ((width * -1) > 1)
		{
			ft_putchar('%');
			width_perc(width, 0);
		}
		else
		{
			width_perc(width, nul);
			ft_putchar('%');
		}
	}
	else
	{
		res += 1;
		ft_putchar('%');
	}
	return (res);
}

void	width_perc(int width, int nul)
{
	int	k;

	k = 0;
	while (k < (modul(width) - 1))
	{
		if (nul != 0)
			ft_putchar('0');
		else
			ft_putchar(' ');
		k++;
	}
}
