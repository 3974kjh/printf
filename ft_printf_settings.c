/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_settings.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <jukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 16:41:33 by jukim             #+#    #+#             */
/*   Updated: 2021/06/21 16:57:01 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_str(t_list *flag, va_list ap, int *val)
{
	char *s;

	s = va_arg(ap, char *);
	if (!s)
		s = "(null)";
	if (flag->precision == -1)
		ft_str_minus_precision(s, flag, val);
	else if (flag->precision == 0)
		ft_str_zero_precision(flag, val);
	else if (flag->precision > 0)
		ft_str_plus_precision(s, flag, val);
}

void	ft_check_char(char **args, t_list *flag, va_list ap, int *val)
{
	char c;

	if (**args == '%')
		c = '%';
	else
		c = va_arg(ap, int);
	if (flag->width <= 1)
	{
		write(1, &c, 1);
		(*val)++;
	}
	else if (flag->width > 1)
		ft_char_print(c, flag, val);
}

void	ft_check_hexu(char **args, t_list *flag, va_list ap, int *val)
{
	unsigned int	x;
	char			str_x[50];

	x = va_arg(ap, unsigned int);
	ft_putnum(args, x, str_x);
	if (flag->precision == 0 && x == 0)
		ft_hexu_check0(flag, val);
	else if (ft_strlen(str_x) >= flag->width &&
			ft_strlen(str_x) >= flag->precision)
	{
		write(1, str_x, ft_strlen(str_x));
		(*val) = (*val) + ft_strlen(str_x);
	}
	else if (ft_strlen(str_x) < flag->width ||
			ft_strlen(str_x) < flag->precision)
	{
		if (flag->precision <= ft_strlen(str_x))
			ft_hexu_check1(flag, str_x, val);
		else if (flag->precision > ft_strlen(str_x))
			ft_hexu_check2(flag, str_x, val);
	}
}

void	ft_check_int(t_list *flag, va_list ap, int *val)
{
	int		d;
	int		len;
	char	int_d[50];

	d = va_arg(ap, int);
	ft_itoa(d, int_d);
	len = ft_int_len(flag, d, int_d);
	if (flag->precision == 0 && d == 0)
		ft_int_check0(flag, val);
	else if (len >= flag->width && len >= flag->precision)
		ft_int_check1(flag, d, int_d, val);
	else if (len < flag->width || len < flag->precision)
	{
		if (flag->precision < len)
			ft_int_check2(flag, d, int_d, val);
		else if (flag->precision >= len)
			ft_int_check3(flag, d, int_d, val);
	}
}

void	ft_check_ads(t_list *flag, va_list ap, int *val)
{
	char				ads_p[50];
	unsigned long long	p;
	int					len;

	p = va_arg(ap, unsigned long long);
	ft_puthex_long(ads_p, p);
	flag->shap_flag = 1;
	len = ft_strlen(ads_p) + 2;
	if (flag->precision == 0 && p == 0)
		ft_ads_check0(flag, val);
	else if (len >= flag->width && len >= flag->precision)
		ft_ads_check1(flag, ads_p, val);
	else if (len < flag->width || len < flag->precision)
	{
		if (flag->precision <= len)
			ft_ads_check2(flag, ads_p, len, val);
		else if (flag->precision > len)
			ft_ads_check3(flag, ads_p, len, val);
	}
}
