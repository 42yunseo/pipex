/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_func2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunseo <yunseo@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 23:04:18 by yunseo            #+#    #+#             */
/*   Updated: 2024/03/23 23:04:19 by yunseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	specifier_x(unsigned int n, char flag)
{
	int		cnt;
	char	*lower_hex;
	char	*upper_hex;

	cnt = 0;
	lower_hex = "0123456789abcdef";
	upper_hex = "0123456789ABCDEF";
	if (flag == 'x')
		cnt += ft_puthex(n, lower_hex);
	else
		cnt += ft_puthex(n, upper_hex);
	return (cnt);
}
