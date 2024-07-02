/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_func_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunseo <yunseo@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 22:39:45 by yunseo            #+#    #+#             */
/*   Updated: 2024/03/23 22:39:46 by yunseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	int	tmp;

	tmp = write(1, &c, 1);
	if (tmp == -1)
		return (-1);
	return (tmp);
}

int	ft_puthex(long unsigned int n, char *hex)
{
	int		cnt;
	int		tmp;

	cnt = 0;
	if (n / 16 != 0)
		cnt += ft_puthex(n / 16, hex);
	tmp = ft_putchar(hex[n % 16]);
	if (tmp == -1)
		return (-1);
	cnt += tmp;
	return (cnt);
}

int	ft_numlen(long long int d)
{
	long long int	len;

	len = 0;
	if (d <= 0)
		len++;
	while (d != 0)
	{
		len++;
		d /= 10;
	}
	return (len);
}
