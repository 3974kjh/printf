/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <jukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 14:07:12 by jukim             #+#    #+#             */
/*   Updated: 2021/06/20 18:51:18 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_recal_str(char *int_d, size_t cp_n, size_t cnt)
{
	int_d[cnt] = '\0';
	while (cnt > 0)
	{
		int_d[cnt - 1] = cp_n % 10 + '0';
		cp_n = cp_n / 10;
		cnt--;
	}
	return (int_d);
}

static size_t	ft_size_str(size_t cp_n)
{
	size_t count;

	count = 0;
	while (cp_n)
	{
		cp_n = cp_n / 10;
		count++;
	}
	return (count);
}

char			*ft_itoa(int n, char *int_d)
{
	size_t	cp_n;

	cp_n = n;
	if (n != 0)
	{
		if (n < 0)
			cp_n = -cp_n;
		ft_recal_str(int_d, cp_n, ft_size_str(cp_n));
	}
	else
	{
		int_d[0] = '0';
		int_d[1] = '\0';
	}
	return (int_d);
}
