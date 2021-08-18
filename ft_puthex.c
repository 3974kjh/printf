/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <jukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 15:25:35 by jukim             #+#    #+#             */
/*   Updated: 2021/06/20 20:51:39 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_recal_str(char **args, char *str_x,
		unsigned int cp_n, size_t cnt)
{
	size_t i;

	if (**args == 'x' || **args == 'X')
		i = 16;
	else
		i = 10;
	str_x[cnt] = 0;
	while (cnt > 0)
	{
		if (**args == 'X')
			str_x[cnt - 1] = "0123456789ABCDEF"[cp_n % i];
		else
			str_x[cnt - 1] = "0123456789abcdef"[cp_n % i];
		cp_n = cp_n / i;
		cnt--;
	}
	return (str_x);
}

static size_t	ft_size_str(char **args, unsigned int cp_n)
{
	size_t	count;
	size_t	i;

	count = 0;
	if (**args == 'x' || **args == 'X')
		i = 16;
	else
		i = 10;
	while (cp_n)
	{
		cp_n = cp_n / i;
		count++;
	}
	return (count);
}

char			*ft_putnum(char **args, unsigned int n, char *str_x)
{
	unsigned int	cp_n;

	cp_n = n;
	if (n != 0)
		ft_recal_str(args, str_x, cp_n, ft_size_str(args, cp_n));
	else
	{
		str_x[0] = '0';
		str_x[1] = '\0';
	}
	return (str_x);
}
