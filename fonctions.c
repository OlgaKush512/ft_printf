/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okushnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 19:52:06 by okushnir          #+#    #+#             */
/*   Updated: 2021/07/26 19:52:11 by okushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert(long long num, long long base)
{
	static char	representation[] = "0123456789abcdef";
	static char	buffer[50];
	char		*ptr;
	int			sign;

	ptr = &buffer[50];
	*ptr = '\0';
	sign = 1;
	if (num < 0)
	{
		num = -num;
		sign = -1;
	}
	*--ptr = representation[num % base];
	num /= base;
	while (num != 0)
	{
		*--ptr = representation[num % base];
		num /= base;
	}
	if (sign < 0)
		*--ptr = '-';
	return (ptr);
}

char	*convert_p(uintptr_t num, int base)
{
	static char	representation[] = "0123456789abcdef";
	static char	buffer[50];
	char		*ptr;
	int			sign;

	ptr = &buffer[50];
	*ptr = '\0';
	sign = 1;
	*--ptr = representation[num % base];
	num /= base;
	while (num != 0)
	{
		*--ptr = representation[num % base];
		num /= base;
	}
	if (sign < 0)
		*--ptr = '-';
	return (ptr);
}

char	*toup(char *str)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] >= 97 && str[i] <= 122)
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}

char	*ft_strnew(int count)
{
	char	*arr;
	int		i;

	i = 0;
	arr = (char *)malloc(sizeof(char) * count);
	if (arr != (void *)0)
	{
		while (i < count)
		{
			arr[i] = '\0';
			i++;
		}
	}
	return (arr);
}

int	spec_p(va_list ap)
{
	void		*i;
	char		*s;
	int			res;
	uintptr_t	n;

	res = 0;
	i = va_arg(ap, void *);
	n = (uintptr_t)i;
	s = convert_p(n, 16);
	res += (int)ft_strlen(s) + 2;
	ft_putstr("0x");
	ft_putstr(s);
	return (res);
}
