/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/17 15:59:14 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/03/25 19:54:24 by yoneshev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	printf_str(char *s);
int	printf_putchar(char c);
int	printf_putnbr(int n);
int	get_num_len(long long n);
int	printf_putunsigned(unsigned int n);
int	get_hex_len(unsigned long n);
int	print_hex(unsigned int n, char *hex);
int	print_address(uintptr_t n, int recur, char *hex);

#endif