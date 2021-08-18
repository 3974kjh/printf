/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <jukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 22:24:02 by jukim             #+#    #+#             */
/*   Updated: 2021/06/21 15:26:29 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != 0)
		i++;
	return (i);
}

void	ft_putchar(char c, int *val)
{
	write(1, &c, 1);
	(*val)++;
}

int		ft_flag_atoi(char **str)
{
	int res;

	res = 0;
	while ('0' <= **str && **str <= '9')
	{
		res = res * 10 + **str - '0';
		(*str)++;
	}
	(*str)--;
	return (res);
}

int		ft_int_len(t_list *flag, int d, char *int_d)
{
	int len;

	if (d < 0)
		len = ft_strlen(int_d) + 1;
	else if (d == 0 && flag->precision == 0)
		len = 0;
	else
		len = ft_strlen(int_d);
	return (len);
}
