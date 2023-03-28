/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okushnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 19:53:18 by okushnir          #+#    #+#             */
/*   Updated: 2021/07/26 19:53:22 by okushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *s);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
char	*convert(long long num, long long base);
char	*convert_p(uintptr_t num, int base);
char	*toup(char *str);
int		spec(const char p, va_list ap);
int		spec_c(va_list ap);
int		spec_s(va_list ap);
int		spec_int(const char p, va_list ap);
int		spec_hex(const char p, va_list ap);
int		spec_p(va_list ap);

#endif
