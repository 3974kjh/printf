/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_zero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <jukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 22:12:39 by jukim             #+#    #+#             */
/*   Updated: 2021/06/21 15:57:26 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_int_check0(t_list *flag, int *val)
{
	(*val) = (*val) + flag->width;
	while (flag->width)
	{
		write(1, " ", 1);
		flag->width--;
	}
}

void	ft_hexu_check0(t_list *flag, int *val)
{
	(*val) = (*val) + flag->width;
	while (flag->width)
	{
		write(1, " ", 1);
		flag->width--;
	}
}

void	ft_ads_check0(t_list *flag, int *val)
{
	if (flag->minus_flag == 1)
		ft_shap_sign_check(flag, val);
	while (flag->width > 2)
	{
		write(1, " ", 1);
		flag->width--;
		(*val)++;
	}
	if (flag->minus_flag == 0)
		ft_shap_sign_check(flag, val);
}

void	ft_minus_d_check(int d, int *len, t_list *flag)
{
	if (d < 0)
	{
		(*len)--;
		flag->width--;
	}
}

void	ft_len_zero(int len, char *int_d)
{
	if (len == 0)
		;
	else
		write(1, int_d, ft_strlen(int_d));
}
