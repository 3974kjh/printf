/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <jukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 17:33:35 by jukim             #+#    #+#             */
/*   Updated: 2021/06/22 15:59:50 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_reset(t_list *flag)
{
	flag->minus_flag = 0;
	flag->plus_flag = 0;
	flag->zero_flag = 0;
	flag->space_flag = 0;
	flag->shap_flag = 0;
	flag->width = 0;
	flag->precision = -1;
}

void	ft_flag_parser(char **args, t_list *flag, va_list ap)
{
	if (**args == '-')
		flag->minus_flag = 1;
	else if (**args == '+')
		flag->plus_flag = 1;
	else if (**args == '0')
		flag->zero_flag = 1;
	else if ('1' <= **args && **args <= '9')
		flag->width = ft_flag_atoi(args);
	else if (**args == ' ')
		flag->space_flag = 1;
	else if (**args == '.')
	{
		(*args)++;
		ft_dot_after(args, flag, ap);
		(*args)--;
	}
	else if (**args == '*')
		ft_flag_star(flag, ap);
}

void	ft_setting(char **args, t_list *flag, va_list ap, int *val)
{
	if (**args == 's')
		ft_check_str(flag, ap, val);
	else if (**args == 'c' || **args == '%')
		ft_check_char(args, flag, ap, val);
	else if (**args == 'x' || **args == 'X' || **args == 'u')
		ft_check_hexu(args, flag, ap, val);
	else if (**args == 'd' || **args == 'i')
		ft_check_int(flag, ap, val);
	else if (**args == 'p')
		ft_check_ads(flag, ap, val);
}

void	ft_print_check(char **args, t_list *flag, va_list ap, int *val)
{
	int out;

	out = 0;
	(*args)++;
	ft_flag_reset(flag);
	while (**args != 's' && **args != 'd' && **args != 'i' && **args != 'u' &&
			**args != 'c' && **args != 'x' && **args != 'X' && **args != 'p' &&
			**args != '%')
	{
		if (**args == '-' || **args == '+' || **args == '0' || **args == '*' ||
			('1' <= **args && **args <= '9') || **args == '.' || **args == ' ')
			ft_flag_parser(args, flag, ap);
		else
		{
			out = 1;
			break ;
		}
		(*args)++;
	}
	if (out != 1)
		ft_setting(args, flag, ap, val);
	else
		(*args)--;
}

int		ft_printf(const char *args, ...)
{
	va_list	ap;
	int		val;
	t_list	*flag;

	if (!(flag = (t_list *)malloc(sizeof(t_list))))
		return (-1);
	va_start(ap, args);
	val = 0;
	while (*args)
	{
		if (*args == '%')
			ft_print_check((char **)&args, flag, ap, &val);
		else
			ft_putchar(*args, &val);
		args++;
	}
	va_end(ap);
	free(flag);
	return (val);
}
