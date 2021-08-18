/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <jukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 21:49:18 by jukim             #+#    #+#             */
/*   Updated: 2021/06/22 15:31:15 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_int_sign_check(t_list *flag, int d, int *val)
{
	if (flag->plus_flag || flag->space_flag || d < 0)
	{
		if (flag->plus_flag == 1)
			write(1, "+", 1);
		else if (flag->space_flag == 1)
			write(1, " ", 1);
		else
			write(1, "-", 1);
		(*val)++;
	}
}

void	ft_int_minus_flag(t_list *flag, int d, char *int_d, int *val)
{
	int len;
	int cp_precision;

	len = ft_int_len(flag, d, int_d);
	ft_minus_d_check(d, &len, flag);
	if ((flag->precision > -1) && (flag->precision > len))
		cp_precision = flag->precision;
	else
		cp_precision = len;
	ft_int_sign_check(flag, d, val);
	while (flag->precision > len)
	{
		write(1, "0", 1);
		flag->precision--;
		(*val)++;
	}
	write(1, int_d, ft_strlen(int_d));
	while (flag->width > cp_precision)
	{
		write(1, " ", 1);
		flag->width--;
		(*val)++;
	}
}

void	ft_int_check1(t_list *flag, int d, char *int_d, int *val)
{
	ft_int_sign_check(flag, d, val);
	if ((d < 0) && (flag->precision == ft_strlen(int_d) + 1))
	{
		write(1, "0", 1);
		(*val)++;
	}
	write(1, int_d, ft_strlen(int_d));
	(*val) = (*val) + ft_strlen(int_d);
}

void	ft_int_check2(t_list *flag, int d, char *int_d, int *val)
{
	int len;

	len = ft_int_len(flag, d, int_d);
	if (flag->minus_flag == 0)
	{
		if (flag->precision == -1 && flag->zero_flag == 1)
			ft_int_sign_check(flag, d, val);
		while (flag->width > len)
		{
			if (flag->precision == -1 && flag->zero_flag == 1)
				write(1, "0", 1);
			else
				write(1, " ", 1);
			flag->width--;
			(*val)++;
		}
		if (!(flag->precision == -1 && flag->zero_flag == 1))
			ft_int_sign_check(flag, d, val);
		ft_len_zero(len, int_d);
	}
	else if (flag->minus_flag == 1)
		ft_int_minus_flag(flag, d, int_d, val);
	(*val) = (*val) + ft_strlen(int_d);
}

void	ft_int_check3(t_list *flag, int d, char *int_d, int *val)
{
	int len;

	len = ft_int_len(flag, d, int_d);
	if (flag->minus_flag == 0)
	{
		if (d < 0)
			flag->precision++;
		while (flag->width > flag->precision)
		{
			write(1, " ", 1);
			flag->width--;
			(*val)++;
		}
		ft_int_sign_check(flag, d, val);
		while (flag->precision > len)
		{
			write(1, "0", 1);
			flag->precision--;
			(*val)++;
		}
		write(1, int_d, ft_strlen(int_d));
	}
	else if (flag->minus_flag == 1)
		ft_int_minus_flag(flag, d, int_d, val);
	(*val) = (*val) + ft_strlen(int_d);
}
