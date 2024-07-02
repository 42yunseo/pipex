/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_func1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunseo <yunseo@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 22:35:04 by yunseo            #+#    #+#             */
/*   Updated: 2024/03/24 14:19:21 by yunseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	specifier_c(char c)
{
	int	tmp;

	tmp = ft_putchar(c);
	if (tmp == -1)
		return (-1);
	return (1);
}

int	specifier_s(char *s)
{
	int	cnt;
	int	tmp;

	if (s == NULL)
		return (specifier_s("(null)"));
	cnt = 0;
	while (*s != '\0')
	{
		tmp = ft_putchar(*s);
		if (tmp == -1)
			return (-1);
		cnt += tmp;
		s++;
	}
	return (cnt);
}

int	specifier_p(void *ptr)
{
	int					cnt;
	char				*hex;
	long unsigned int	add;

	if (ptr == NULL)
		return (specifier_s("(nil)"));
	cnt = 0;
	hex = "0123456789abcdef";
	add = (long unsigned int)ptr;
	cnt += specifier_s("0x");
	cnt += ft_puthex(add, hex);
	return (cnt);
}

int	specifier_d(int n)
{
	int		cnt;
	char	tmp;

	cnt = 0;
	if (n == -2147483648)
		return (specifier_s("-2147483648"));
	if (n < 0)
	{
		cnt += specifier_c('-');
		n = -n;
	}
	if (n / 10 != 0)
		cnt += specifier_d(n / 10);
	tmp = n % 10 + '0';
	cnt += specifier_c(tmp);
	return (cnt);
}

int	specifier_u(unsigned int n)
{
	int		cnt;
	char	tmp;

	cnt = 0;
	if (n / 10 != 0)
		cnt += specifier_u(n / 10);
	tmp = n % 10 + '0';
	cnt += specifier_c(tmp);
	return (cnt);
}
