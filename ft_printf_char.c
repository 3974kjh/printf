/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <jukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 13:44:43 by jukim             #+#    #+#             */
/*   Updated: 2021/06/20 14:56:53 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char_print(char c, t_list *flag, int *val)
{
	(*val) = (*val) + flag->width;
	if (flag->minus_flag == 0)
	{
		while (flag->width - 1 != 0)
		{
			if (flag->zero_flag == 0)
				write(1, " ", 1);
			if (flag->zero_flag == 1)
				write(1, "0", 1);
			flag->width--;
		}
		write(1, &c, 1);
	}
	else if (flag->minus_flag == 1)
	{
		write(1, &c, 1);
		while (flag->width - 1 != 0)
		{
			write(1, " ", 1);
			flag->width--;
		}
	}
}
