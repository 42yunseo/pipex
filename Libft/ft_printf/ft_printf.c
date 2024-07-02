/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunseo <yunseo@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:49:45 by yunseo            #+#    #+#             */
/*   Updated: 2024/04/10 15:37:44 by yunseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_conversion(t_format *f, va_list *args)
{
	if (f->specifier == 'c')
		return (specifier_c(va_arg(*args, int)));
	else if (f->specifier == 's')
		return (specifier_s(va_arg(*args, char *)));
	else if (f->specifier == 'p')
		return (specifier_p(va_arg(*args, void *)));
	else if (f->specifier == 'd')
		return (specifier_d(va_arg(*args, int)));
	else if (f->specifier == 'i')
		return (specifier_d(va_arg(*args, int)));
	else if (f->specifier == 'u')
		return (specifier_u(va_arg(*args, unsigned int)));
	else if (f->specifier == 'x')
		return (specifier_x(va_arg(*args, unsigned int), 'x'));
	else if (f->specifier == 'X')
		return (specifier_x(va_arg(*args, unsigned int), 'X'));
	else if (f->specifier == '%')
		return (ft_putchar('%'));
	else
		return (-1);
}

// %[flag][width][.precision]specifier
int	make_format(const char **fmt, t_format *f)
{
	int	idx;

	idx = 0;
	if (ft_strrchr("-+ #0", (*fmt)[idx]) != NULL)
		f->flag = (*fmt)[idx++];
	f->width = ft_atoi(&(*fmt)[idx]);
	if (f->width != 0)
		idx += ft_numlen(f->width);
	if ((*fmt)[idx] == '.')
	{
		f->period = 1;
		f->number = ft_atoi(&(*fmt)[idx]);
		if (f->number != 0)
			idx += ft_numlen(f->number);
	}
	if (ft_strrchr("cspdiuxX%", (*fmt)[idx]) != NULL)
		f->specifier = (*fmt)[idx];
	if (f->specifier == 0)
		return (-1);
	(*fmt) += idx;
	return (1);
}

int	ft_nextfmt(const char **fmt, t_format *f, va_list *args)
{
	int	tmp;

	if (**fmt == '%')
	{
		(*fmt)++;
		if (make_format(fmt, f) == -1)
			return (-1);
		tmp = ft_conversion(f, args);
		if (tmp == -1)
			return (-1);
	}
	else
	{
		tmp = ft_putchar(**fmt);
		if (tmp == -1)
			return (-1);
	}
	return (tmp);
}

int	err_free(t_format *f)
{
	free(f);
	return (-1);
}

int	ft_printf(const char *fmt, ...)
{
	va_list		args;
	t_format	*f;
	int			cnt;
	int			tmp;

	cnt = 0;
	va_start(args, fmt);
	f = (t_format *)malloc(sizeof(t_format));
	if (f == NULL || fmt == NULL)
		return (-1);
	while (*fmt != '\0')
	{
		ft_memset(f, 0, sizeof(f));
		tmp = ft_nextfmt(&fmt, f, &args);
		if (tmp == -1)
			return (err_free(f));
		cnt += tmp;
		fmt++;
	}
	free(f);
	va_end(args);
	return (cnt);
}
