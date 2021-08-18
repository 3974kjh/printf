/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexu.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <jukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 22:14:37 by jukim             #+#    #+#             */
/*   Updated: 2021/06/20 22:16:56 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexu_minus_flag(t_list *flag, char *x, int *val)
{
	int cp_precision;

	if (flag->precision > ft_strlen(x))
		cp_precision = flag->precision;
	else
		cp_precision = ft_strlen(x);
	while (flag->precision > ft_strlen(x))
	{
		write(1, "0", 1);
		flag->precision--;
		(*val)++;
	}
	write(1, x, ft_strlen(x));
	while (flag->width > cp_precision)
	{
		write(1, " ", 1);
		flag->width--;
		(*val)++;
	}
}

void	ft_hexu_check1(t_list *flag, char *x, int *val)
{
	if (flag->minus_flag == 0)
	{
		while (flag->width > ft_strlen(x))
		{
			if (flag->precision == -1 && flag->zero_flag == 1)
				write(1, "0", 1);
			else
				write(1, " ", 1);
			flag->width--;
			(*val)++;
		}
		write(1, x, ft_strlen(x));
	}
	else if (flag->minus_flag == 1)
		ft_hexu_minus_flag(flag, x, val);
	(*val) = (*val) + ft_strlen(x);
}

void	ft_hexu_check2(t_list *flag, char *x, int *val)
{
	if (flag->minus_flag == 0)
	{
		while (flag->width > flag->precision)
		{
			write(1, " ", 1);
			flag->width--;
			(*val)++;
		}
		while (flag->precision > ft_strlen(x))
		{
			write(1, "0", 1);
			flag->precision--;
			(*val)++;
		}
		write(1, x, ft_strlen(x));
	}
	else if (flag->minus_flag == 1)
		ft_hexu_minus_flag(flag, x, val);
	(*val) = (*val) + ft_strlen(x);
}
