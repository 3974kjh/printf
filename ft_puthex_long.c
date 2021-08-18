/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <jukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 15:25:35 by jukim             #+#    #+#             */
/*   Updated: 2021/06/21 16:56:03 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_recal_str(char *ads_p, unsigned long long cp_n, size_t cnt)
{
	ads_p[cnt] = '\0';
	while (cnt > 0)
	{
		ads_p[cnt - 1] = "0123456789abcdef"[cp_n % 16];
		cp_n = cp_n / 16;
		cnt--;
	}
	return (ads_p);
}

static size_t	ft_size_str(unsigned long long cp_n)
{
	size_t count;

	count = 0;
	while (cp_n)
	{
		cp_n = cp_n / 16;
		count++;
	}
	return (count);
}

char			*ft_puthex_long(char *ads_p, unsigned long long n)
{
	unsigned long long cp_n;

	cp_n = n;
	if (n != 0)
		ads_p = ft_recal_str(ads_p, cp_n, ft_size_str(cp_n));
	else
	{
		ads_p[0] = '0';
		ads_p[1] = '\0';
	}
	return (ads_p);
}
