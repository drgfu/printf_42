/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkais <kkais@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:23:08 by kkais             #+#    #+#             */
/*   Updated: 2021/12/20 16:23:06 by kkais            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "libft/libft.h"

// first we initialise the structure with zeros
static void	init_reset(t_fmt *fmt)
{
	fmt->offset = 0;
	fmt->pad = 0;
	fmt->width = 0;
	fmt->precision = 0;
	fmt->hashtag = 0;
	fmt->zero = 0;
	fmt->minus = 0;
	fmt->space = 0;
	fmt->plus = 0;
	fmt->dot = 0;
	fmt->upper = 0;
}

// finding out with format it is and which one should you follow
static void	find_flag(char c, t_fmt *fmt)
{
	if (ft_isdigit(c))
	{
		if (fmt->dot || fmt->zero)
			fmt->precision = fmt->precision * 10 + c - '0';
		else
		{
			if (!fmt->width && c == '0')
				fmt->zero = 1;
			else
				fmt->width = fmt->width * 10 + c - '0';
		}
	}
	else if (c == '#')
		fmt->hashtag = 1;
	else if (c == '-')
		fmt->minus = 1;
	else if (c == ' ')
		fmt->space = 1;
	else if (c == '+')
		fmt->plus = 1;
	else if (c == '.')
		fmt->dot = 1;
}

// if the prinf function finds %, it will come here and see which format it is 
static char	*conversion(char *str, t_fmt *fmt)
{
	while (*str && !ft_strchr("cspdiuxX%", *str))
		find_flag(*str++, fmt);
	if (*str == 'c')
		ft_printf_char(fmt);
	else if (*str == 's')
		ft_printf_str(fmt);
	else if (*str == 'p')
		ft_printf_ptr(fmt);
	else if (*str == 'd' || *str == 'i')
		ft_printf_int(fmt);
	else if (*str == 'u')
		ft_printf_uint(*str, 10, fmt);
	else if (*str == 'x' || *str == 'X')
		ft_printf_uint(*str, 16, fmt);
	else if (*str == '%' && ++fmt->len)
		ft_putchar_fd(*str, 1);
	return (++str);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	t_fmt	fmt;

	i = 0;
	fmt.len = 0;
	init_reset(&fmt);
	va_start(fmt.args, str);
	// we go  through the string and look for the %, otherwise we add the character to fd
	while (*str)
	{
		if (*str == '%' && *str++)
		{
			str = conversion((char *)str, &fmt);
			init_reset(&fmt);
		}
		else if (++i)
			ft_putchar_fd(*str++, 1);
	}
	va_end(fmt.args);
	i += fmt.len;
	return (i);
}
