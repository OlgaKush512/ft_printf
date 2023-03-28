/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okushnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 19:52:31 by okushnir          #+#    #+#             */
/*   Updated: 2021/07/26 19:52:40 by okushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*convert(long long num, long long base, t_flags flag, const char p)
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
	ptr = fin_of_convert(ptr, flag, p, sign);
	return (ptr);
}

char	*convert_p(uintptr_t num, int base, t_flags flag, const char p)
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
	ptr = fin_of_convert(ptr, flag, p, sign);
	return (ptr);
}

char	*fin_of_convert(char *ptr, t_flags flag, const char p, int sign)
{
	if (sign < 0)
		*--ptr = '-';
	else if (flag.plus && (p == 'd' || p == 'i' || p == 'u'))
		*--ptr = '+';
	else if (!flag.plus && flag.espace && (p == 'd' || p == 'i' || p == 'u'))
		*--ptr = ' ';
	else if (flag.diez && (p == 'x' || p == 'X'))
	{
		if (*ptr != '0')
		{
			if (p == 'x')
				*--ptr = 'x';
			else
				*--ptr = 'X';
			*--ptr = '0';
		}
	}
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
