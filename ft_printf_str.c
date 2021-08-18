/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <jukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 22:05:53 by jukim             #+#    #+#             */
/*   Updated: 2021/06/19 21:55:11 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_str_minus_precision(char *s, t_list *flag, int *val)
{
	if (flag->minus_flag == 0)
	{
		while (flag->width > ft_strlen(s))
		{
			if (flag->zero_flag == 1)
				write(1, "0", 1);
			if (flag->zero_flag == 0)
				write(1, " ", 1);
			flag->width--;
			(*val)++;
		}
		write(1, s, ft_strlen(s));
	}
	else if (flag->minus_flag == 1)
	{
		write(1, s, ft_strlen(s));
		while (flag->width > ft_strlen(s))
		{
			write(1, " ", 1);
			flag->width--;
			(*val)++;
		}
	}
	(*val) = (*val) + ft_strlen(s);
}

void	ft_str_zero_precision(t_list *flag, int *val)
{
	while (flag->width)
	{
		if (flag->minus_flag == 0 && flag->zero_flag == 1)
			write(1, "0", 1);
		if (flag->minus_flag == 1 || flag->zero_flag == 0)
			write(1, " ", 1);
		flag->width--;
		(*val)++;
	}
}

void	ft_str_plus_precision(char *s, t_list *flag, int *val)
{
	if (flag->precision > ft_strlen(s))
		ft_str_plus_precision_check1(s, flag, val);
	else if (flag->precision <= ft_strlen(s))
		ft_str_plus_precision_check2(s, flag, val);
}

void	ft_str_plus_precision_check1(char *s, t_list *flag, int *val)
{
	if (flag->minus_flag == 0)
	{
		while (flag->width > ft_strlen(s))
		{
			if (flag->zero_flag == 1)
				write(1, "0", 1);
			if (flag->zero_flag == 0)
				write(1, " ", 1);
			flag->width--;
			(*val)++;
		}
		write(1, s, ft_strlen(s));
	}
	else if (flag->minus_flag == 1)
	{
		write(1, s, ft_strlen(s));
		while (flag->width > ft_strlen(s))
		{
			write(1, " ", 1);
			flag->width--;
			(*val)++;
		}
	}
	(*val) = (*val) + ft_strlen(s);
}

void	ft_str_plus_precision_check2(char *s, t_list *flag, int *val)
{
	if (flag->minus_flag == 0)
	{
		while (flag->width > flag->precision)
		{
			if (flag->zero_flag == 1)
				write(1, "0", 1);
			if (flag->zero_flag == 0)
				write(1, " ", 1);
			flag->width--;
			(*val)++;
		}
		write(1, s, flag->precision);
	}
	else if (flag->minus_flag == 1)
	{
		write(1, s, flag->precision);
		while (flag->width > flag->precision)
		{
			write(1, " ", 1);
			flag->width--;
			(*val)++;
		}
	}
	(*val) = (*val) + flag->precision;
}
