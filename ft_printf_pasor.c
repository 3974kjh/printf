/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pasor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <jukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 21:39:21 by jukim             #+#    #+#             */
/*   Updated: 2021/06/20 21:58:25 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_dot_after(char **args, t_list *flag, va_list ap)
{
	int i;

	i = 0;
	if (**args == ' ' || **args == '+' || **args == '-')
		flag->precision = 0;
	else if ('0' <= **args && **args <= '9')
	{
		flag->precision = ft_flag_atoi(args);
		(*args)++;
	}
	else if (**args == '*')
	{
		i = va_arg(ap, int);
		if (i < 0)
			flag->precision = -1;
		else
			flag->precision = i;
		(*args)++;
	}
	else if (**args == 's' || **args == 'd' || **args == 'i' || **args == 'c'
			|| **args == 'x' || **args == 'X' || **args == 'p' || **args == '%'
			|| **args == 'u')
		flag->precision = 0;
}

void	ft_flag_star(t_list *flag, va_list ap)
{
	int i;

	i = va_arg(ap, int);
	if (i < 0)
	{
		flag->minus_flag = 1;
		flag->width = -i;
	}
	else
		flag->width = i;
}
