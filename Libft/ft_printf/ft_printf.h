/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunseo <yunseo@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 13:38:54 by yunseo            #+#    #+#             */
/*   Updated: 2024/03/23 13:49:35 by yunseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

// %[flags][width][.precision]specifier
typedef struct s_format
{
	char	flag;
	int		width;
	int		period;
	int		number;
	char	specifier;
}	t_format;

int	ft_printf(const char *fmt, ...);
int	specifier_c(char c);
int	specifier_s(char *s);
int	specifier_p(void *ptr);
int	specifier_d(int n);
int	specifier_u(unsigned int n);
int	specifier_x(unsigned int n, char flag);

int	ft_putchar(char c);
int	ft_puthex(long unsigned int n, char *hex);
int	ft_numlen(long long int d);
#endif
