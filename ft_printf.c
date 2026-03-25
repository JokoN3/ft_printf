/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/17 16:00:01 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/03/25 20:07:26 by yoneshev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_args(va_list *args, char format)
{
	if (format == 'c')
		return (ft_putchar_fd(va_arg(*args, int), 1), 1);
	if (format == 's')
		return (printf_str(va_arg(*args, char *)));
	if (format == 'd' || format == 'i')
		return (printf_putnbr(va_arg(*args, int)));
	if (format == 'u')
		return (printf_putunsigned(va_arg(*args, unsigned int)));
	if (format == 'x')
		return (print_hex(va_arg(*args, unsigned int), "0123456789abcdef"));
	if (format == 'X')
		return (print_hex(va_arg(*args, unsigned int), "0123456789ABCDEF"));
	if (format == '%')
		return (ft_putchar_fd('%', 1), 1);
	if (format == 'p')
		return (print_address(va_arg(*args, uintptr_t), 0, "0123456789abcdef"));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		char_count;

	char_count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!*format)
				break ;
			char_count += handle_args(&args, *format);
		}
		else
			char_count += printf_putchar(*format);
		format++;
	}
	va_end(args);
	return (char_count);
}
