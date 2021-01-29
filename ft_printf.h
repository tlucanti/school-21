/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 19:07:34 by tlucanti          #+#    #+#             */
/*   Updated: 2021/01/29 19:07:49 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

# define NULLPTR 0
# define FT_ABS(n) ((n) < 0 ? (-(n)) : (n))
# define FT_ABSNULL(n) ((n) > 0 ? (n) : 0)
# define FT_MIN(a, b) ((a) > (b) ? (b) : (a))
# define FT_MAX(a, b) ((a) > (b) ? (a) : (b))
# define FT_MAX3(a, b, c) (FT_MAX((a), (FT_MAX((b), (c)))))
# define FT_MIN3(a, b, c) (FT_MIN((a), (FT_MIN((b), (c)))))
# define FT_ISDIGIT(a) ((a) >= 48 && (a) <= 57)
# define FT_ISNOTNULL(a) ((a) > 48 && (a) <= 57)
# define FT_STRLEN(str) ((size_t)ft_memchr((str), 0, -1) - (size_t)(str))
# define FT_PUTSTR(str, i) (write(1, str + i, FT_STRLEN(str + i)))
# define MAX_ACCURACY 18

# define EPS 1e-15
# define INF (1e308 * 10)
# define MINF (-10e307 * 10)
# define NAN (INF - INF)
# define IS_PNULL(a) (1. / (a) == INF)
# define IS_MNULL(a) (1. / (a) == MINF)
# define IS_NULL(a) ((a) == 0)
# define IS_PINF(a) ((a) == INF)
# define IS_MINF(a) ((a) == MINF)
# define IS_INF(a) (IS_PINF(a) || IS_MINF(a))
# define IS_NAN(a) ((a) != (a))
# define VALID_DOUBLE(d) (!IS_INF(d) && !IS_NAN(d))

typedef struct	s_format_qualifiers
{
	int			a;
	char		z;
	long long	w;
	long long	q;
	char		s;
	char		o;
}				t_format_qualifiers;

int				ft_printf(const char *buff, ...);
long long		ft_format_parcer(const char **buff,
	t_format_qualifiers format_qualifiers, va_list args,
	long long printed_syms);
long long		ft_format_parcerl(const char **buff,
	t_format_qualifiers format_qualifiers, va_list args,
	long long printed_syms);
long long		ft_format_parcerll(const char **buff,
	t_format_qualifiers format_qualifiers, va_list args,
	long long printed_syms);
long long		ft_format_parcerh(const char **buff,
	t_format_qualifiers format_qualifiers, va_list args,
	long long printed_syms);
long long		ft_format_parcerhh(const char **buff,
	t_format_qualifiers format_qualifiers, va_list args,
	long long printed_syms);
const char		*ft_get_format(const char *buff,
	t_format_qualifiers *format_qualifiers, va_list args);
const char		*ft_get_format_loop(const char *buff,
	t_format_qualifiers *format_qualifiers, va_list args);
long long		ft_atol_set(const char *str, long long *var);

void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memchr_fast(unsigned char **ptr,
	unsigned char ch, size_t xlen);
long long		ft_putcharf(char c, t_format_qualifiers form_qua);
long long		ft_putnstrf(char *str, t_format_qualifiers form_qua);
long long		ft_putnmbrf(unsigned long long n,
	t_format_qualifiers fq, int sgn);
long long		ft_putaddressf(void *ptr, const char *alphabet,
	t_format_qualifiers form_qua);
long long		ft_puthexnbrf(unsigned long long n, const char *alphabet,
	t_format_qualifiers form_qua);
long long		ft_putoctnbrf(unsigned long long n, const char *alphabet,
	t_format_qualifiers form_qua);
long long		ft_pns(char *s, long long count);
int				ft_ispecifier(char a);

int				ft_log10(double d);
int				ft_log10ull(uint64_t d);
double			ft_dpow(double d, int16_t n);
u_int64_t		ft_ullpow(u_int64_t d, int16_t n);
u_int16_t		ft_dnum(u_int64_t ll);
u_int64_t		ft_oddceil(u_int64_t ll, u_int16_t q, int16_t exp10);
int64_t			ft_putll(u_int64_t n, int dot, long long q, u_int16_t clt);
int64_t			ft_put3nbr(int16_t n);
long long		ft_putformat_f(u_int8_t sgn, t_format_qualifiers fq,
	int16_t exp10, uint64_t lll);
long long		ft_putfloatnbrf(double d, t_format_qualifiers fq,
	int16_t exp10);
long long		ft_putformat_e(uint64_t lll, t_format_qualifiers fq,
	int16_t exp10, u_int8_t sign_ceiled);
long long		ft_putfloatnbre(double d, t_format_qualifiers fq,
	int16_t exp10);
u_int16_t		ft_find_zeros(uint64_t ll, u_int32_t start, u_int32_t count);
long long		ft_putfloatnbrg(double d, t_format_qualifiers fq,
	int16_t exp10);
uint64_t		ft_g_switcher1(uint64_t lll, t_format_qualifiers fq,
	int32_t exp10, double d_cpy);
uint64_t		ft_g_switcher2(double d_cpy, t_format_qualifiers fq,
	uint64_t aqf, u_int32_t exp10);
u_int64_t		ft_float_invalid(double d, t_format_qualifiers fq);
long long		ft_putfloatnbr_switcher(double d, t_format_qualifiers fq,
	u_int8_t form);

#endif
