#include "../includes/ft_printf.h"

static	char	*float_to_str(t_d d, const char *str, t_cp *z)
{
	int			e;
	int			i;
	char		*res;
	char		*int_part;
	char		*fr_part;

	i = 0;
	e = (int)d.t_ds.e - 16383;
	int_part = get_int_part(&e, &i, str);
	fr_part = get_fraction_part(&e, &i, str);
	use_precision(&int_part, &fr_part, z->precision);
	if (z->hash_flag || z->precision != 0)
	{
		res = ft_strjoin(int_part, ".");
		free(int_part);
		int_part = res;
	}
	res = ft_strjoin_free(&int_part, &fr_part);
	return (res);
}

static	char	*check_inf_nan(t_d d, const char *str)
{
	int i;
	int n;

	i = 1;
	n = 0;
	while (i < 64)
		n += str[i++] == '1' ? 1 : 0;
	if (n > 0)
		return (ft_strdup("nan"));
	else
		return (ft_strdup("inf"));
}

static	char	*p1(t_cp *z, t_d d, int len, char *str)
{
	char		*tmp1;
	char		*tmp2;
	int			f;

	f = (ft_strcmp("inf", str) == 0 || ft_strcmp("nan", str) == 0) ? 1 : 0;
	if (z->zero_flag && !f)
	{
		tmp2 = ft_fill_str('0', z->width - len - z->pf - z->sf - (int)d.t_ds.s);
		str = ft_strjoin_free(&tmp2, &str);
	}
	if (z->pf && (int)d.t_ds.s == 0 && ft_strcmp("nan", str) != 0)
	{
		tmp1 = ft_strjoin("+", str);
		free(str);
		str = tmp1;
	}
	if ((int)d.t_ds.s == 1)
	{
		tmp1 = ft_strjoin("-", str);
		free(str);
		str = tmp1;
	}
	return (str);
}

static	char	*p2(t_cp *z, t_d d, int len, char *str)
{
	char		*tmp1;
	char		*tmp2;

	if (!z->pf && (int)d.t_ds.s == 0 && z->sf && ft_strcmp("nan", str) != 0)
	{
		tmp1 = ft_strjoin(" ", str);
		free(str);
		str = tmp1;
	}
	len = (int)ft_strlen(str);
	if (z->minus_flag)
	{
		tmp2 = ft_fill_str(' ', z->width - len);
		str = ft_strjoin_free(&str, &tmp2);
	}
	else
	{
		tmp2 = ft_fill_str(' ', z->width - len);
		str = ft_strjoin_free(&tmp2, &str);
	}
	return (str);
}

void			f_pr(t_cp *z, va_list ap)
{
	int			len;
	char		*str;
	char		*mantissa;
	t_d			d;

	d.d = (long double)cast_f(z, ap);
	mantissa = ft_ulltoa_base(d.t_ds.m, 2);
	str = (int)d.t_ds.e == 32767 ? check_inf_nan(d, mantissa)
			: float_to_str(d, mantissa, z);
	free(mantissa);
	len = (int)ft_strlen(str);
	z->sf = (int)d.t_ds.s == 1 ? 0 : z->sf;
	z->pf = (int)d.t_ds.s == 1 ? 0 : z->pf;
	str = p1(z, d, len, str);
	str = p2(z, d, len, str);
	z->n_chars += (int)ft_strlen(str);
	ft_putstr(str);
	free(str);
}
