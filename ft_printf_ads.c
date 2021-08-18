/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <jukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 16:18:23 by jukim             #+#    #+#             */
/*   Updated: 2021/06/20 22:16:45 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_shap_sign_check(t_list *flag, int *val)
{
	if (flag->shap_flag == 1)
	{
		write(1, "0x", 2);
		(*val) = (*val) + 2;
	}
}

void	ft_ads_minus_flag(t_list *flag, char *ads_p, int len, int *val)
{
	ft_shap_sign_check(flag, val);
	write(1, ads_p, ft_strlen(ads_p));
	while (flag->width > len)
	{
		write(1, " ", 1);
		flag->width--;
		(*val)++;
	}
}

void	ft_ads_check1(t_list *flag, char *ads_p, int *val)
{
	ft_shap_sign_check(flag, val);
	write(1, ads_p, ft_strlen(ads_p));
	(*val) = (*val) + ft_strlen(ads_p);
}

void	ft_ads_check2(t_list *flag, char *ads_p, int len, int *val)
{
	if (flag->minus_flag == 0)
	{
		while (flag->width > len)
		{
			write(1, " ", 1);
			flag->width--;
			(*val)++;
		}
		ft_shap_sign_check(flag, val);
		write(1, ads_p, ft_strlen(ads_p));
	}
	else if (flag->minus_flag == 1)
		ft_ads_minus_flag(flag, ads_p, len, val);
	(*val) = (*val) + ft_strlen(ads_p);
}

void	ft_ads_check3(t_list *flag, char *ads_p, int len, int *val)
{
	if (flag->minus_flag == 0)
	{
		while (flag->width > flag->precision)
		{
			write(1, " ", 1);
			flag->width--;
			(*val)++;
		}
		ft_shap_sign_check(flag, val);
		while (flag->precision > len - 2)
		{
			write(1, "0", 1);
			flag->precision--;
			(*val)++;
		}
		write(1, ads_p, ft_strlen(ads_p));
	}
	else if (flag->minus_flag == 1)
		ft_ads_minus_flag(flag, ads_p, len, val);
	(*val) = (*val) + ft_strlen(ads_p);
}
