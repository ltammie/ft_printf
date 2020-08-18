#include "../includes/ft_printf.h"

static	void	no_fraction_part(char **f, int len, int p)
{
	char *tmp;
	char *tmp2;

	(*f)[0] = (char)((*f)[0] == 'z' ? '0' : (*f)[0]);
	tmp = *f;
	if (p == 0)
	{
		*f = ft_strdup("");
		free(tmp);
	}
	else
	{
		tmp2 = ft_fill_str('0', p - len);
		*f = ft_strjoin_free(&tmp, &tmp2);
	}
}

static	int		get_sc_flag(const char *f, int len, char i, int p)
{
	char	last;
	char	prev;

	while (f[len - 1] == '0')
		len--;
	if (p == 0)
		prev = i;
	else
		prev = f[p - 1];
	last = f[p];
	if (len - p == 1 && last == '5' && (prev - '0') % 2 == 0)
		return (1);
	return (0);
}

static	void	round_fraction_part(char **f, int p, int *carry, int fl)
{
	int		tmp_p;
	int		tmp_carry;
	char	*tmp;

	tmp = *f;
	tmp_p = p - 1;
	*carry = (((*f)[p] - '0') + 5) / 10;
	(*f)[p] = (((*f)[p] - '0') + 5) % 10 + '0';
	while (tmp_p != -1 && !fl)
	{
		tmp_carry = *carry;
		*carry = (((*f)[tmp_p] - '0') + tmp_carry) / 10;
		(*f)[tmp_p] = (((*f)[tmp_p] - '0') + tmp_carry) % 10 + '0';
		tmp_p--;
	}
	*f = ft_strsub(*f, 0, p);
	free(tmp);
}

static	void	round_int_part(char **i, int *carry, int sc_flag)
{
	int		len;
	int		tmp_carry;
	char	*tmp;
	char	*tmp2;

	len = (int)ft_strlen(*i) - 1;
	if (!sc_flag && carry != 0)
	{
		while (len >= 0)
		{
			tmp_carry = *carry;
			*carry = (((*i)[len] - '0') + tmp_carry) / 10;
			(*i)[len] = (((*i)[len] - '0') + tmp_carry) % 10 + '0';
			len--;
		}
		if (*carry != 0)
		{
			tmp = ft_fill_str(*carry + '0', 1);
			tmp2 = *i;
			*i = ft_strjoin_free(&tmp, &tmp2);
		}
	}
}

void			use_precision(char **i, char **f, int p)
{
	int len;
	int carry;
	int sc_flag;

	carry = 0;
	len = (int)ft_strlen(*f);
	sc_flag = 0;
	if ((*f)[0] == 'z' || len <= p)
		no_fraction_part(f, len, p);
	else
	{
		sc_flag = get_sc_flag(*f, len, (*i)[0], p);
		round_fraction_part(f, p, &carry, sc_flag);
	}
	round_int_part(i, &carry, sc_flag);
}
