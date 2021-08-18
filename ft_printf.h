/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <jukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:55:55 by jukim             #+#    #+#             */
/*   Updated: 2021/06/21 16:57:23 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_list
{
	int		minus_flag;
	int		plus_flag;
	int		zero_flag;
	int		space_flag;
	int		shap_flag;
	int		width;
	int		precision;
}				t_list;

void			ft_flag_parser(char **args, t_list *flag, va_list ap);
void			ft_dot_after(char **args, t_list *flag, va_list ap);
void			ft_flag_star(t_list *flag, va_list ap);

void			ft_check_str(t_list *flag, va_list ap, int *val);
void			ft_str_minus_precision(char *s, t_list *flag, int *val);
void			ft_str_zero_precision(t_list *flag, int *val);
void			ft_str_plus_precision(char *s, t_list *flag, int *val);
void			ft_str_plus_precision_check1(char *s, t_list *flag, int *val);
void			ft_str_plus_precision_check2(char *s, t_list *flag, int *val);

void			ft_check_char(char **args, t_list *flag, va_list ap, int *val);
void			ft_char_print(char c, t_list *flag, int *val);

void			ft_check_hexu(char **args, t_list *flag, va_list ap, int *val);
void			ft_hexu_minus_flag(t_list *flag, char *x, int *val);
void			ft_hexu_check0(t_list *flag, int *val);
void			ft_hexu_check1(t_list *flag, char *x, int *val);
void			ft_hexu_check2(t_list *flag, char *x, int *val);
char			*ft_putnum(char **args, unsigned int n, char *str_x);

void			ft_check_int(t_list *flag, va_list ap, int *val);
char			*ft_itoa(int n, char *int_d);
void			ft_int_sign_check(t_list *flag, int d, int *val);
int				ft_int_len(t_list *flag, int d, char *int_d);
void			ft_int_minus_flag(t_list *flag, int d, char *int_d, int *val);
void			ft_minus_d_check(int d, int *len, t_list *flag);
void			ft_len_zero(int len, char *int_d);
void			ft_int_check0(t_list *flag, int *val);
void			ft_int_check1(t_list *flag, int d, char *int_d, int *val);
void			ft_int_check2(t_list *flag, int d, char *int_d, int *val);
void			ft_int_check3(t_list *flag, int d, char *int_d, int *val);

void			ft_check_ads(t_list *flag, va_list ap, int *val);
void			ft_shap_sign_check(t_list *flag, int *val);
void			ft_ads_minus_flag(t_list *flag, char *ads_p, int len, int *val);
void			ft_ads_check0(t_list *flag, int *val);
void			ft_ads_check1(t_list *flag, char *ads_p, int *val);
void			ft_ads_check2(t_list *flag, char *ads_p, int len, int *val);
void			ft_ads_check3(t_list *flag, char *ads_p, int len, int *val);
char			*ft_puthex_long(char *ads_p, unsigned long long n);

void			ft_flag_reset(t_list *flag);
void			ft_setting(char **args, t_list *flag, va_list ap, int *val);
void			ft_print_check(char **args, t_list *flag, va_list ap, int *val);
void			ft_putchar(char c, int *val);
int				ft_printf(const char *args, ...);

int				ft_flag_atoi(char **str);
int				ft_strlen(char *str);
#endif
