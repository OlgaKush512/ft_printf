/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okushnir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 19:53:47 by okushnir          #+#    #+#             */
/*   Updated: 2021/07/26 19:53:51 by okushnir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <stdint.h>

typedef struct s_flags
{
	int	nul;
	int	width;
	int	prec;
	int	diez;
	int	plus;
	int	espace;
	int	turn;
}				t_flags;

size_t		ft_strlen(const char *s);
void		ft_putchar(char c);
void		ft_putstr(char *str);
void		ft_putnbr(int nb);

char		*convert(long long num, long long base, t_flags flag, const char p);
char		*convert_p(uintptr_t num, int base, t_flags flag, const char p);
char		*fin_of_convert(char *ptr, t_flags flag, const char p, int sign);
char		*toup(char *str);
char		*ft_strnew(int count);
int			ft_atoi(const char *str);

void		init_flag(t_flags *flag);
const char	*flags_diez_plus_espace(t_flags *flag, const char *p, int *minus);
const char	*fill_up_flag(t_flags *flag, const char *p);
int			check_spec(const char *p);
int			ft_printf(const char *format, ...);

int			spec(const char p, va_list ap, t_flags flag);
int			alignment_perc(int width, int nul);
void		width_perc(int width, int nul);
int			spec_c(va_list ap, t_flags flag);
int			alignment_c(char *s, int nul, int width);
int			condition_c(char *s, int nul, int width);
int			ft_width(char *s, int width, int nul);
int			spec_s(va_list ap, t_flags flag);
int			alignement_s(char *s, t_flags flag);
int			alignement_s_cond(char *s, t_flags flag, int sign, int indicator);
int			modul(int nb);
int			condition(char *s, int flag, int prec, int res);
int			spec_int(const char p, va_list ap, t_flags flag);
int			alignment_i(char *s, const char p, t_flags flag);
char		*alignment_i_cond(char *s, const char p, t_flags flag, int *turn);
char		*alignement_int_no_ind(char *s, t_flags flag, int *turn, int res);
char		*alignement_int_wth_ind(char *s, t_flags flag, int *turn, int res);
int			alignement_int_neg_wthd(char *s, t_flags fl, int tn, const char p);
int			condition_int(char *s, int flag, int res, const char p);
int			spec_p(va_list ap, t_flags flag);
int			p_nul(int prec, int len);
int			condition_p(char *s, int i, t_flags flag);

void		init_flag(t_flags *flag);
const char	*fill_up_flag(t_flags *flag, const char *p);

#endif
