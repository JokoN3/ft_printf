/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/17 16:00:01 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/03/25 17:32:20 by yoneshev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	printf_str(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	printf_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	get_num_len(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

int	printf_putnbr(int n)
{
	char	c;
	int		len;

	if (n == INT_MIN)
		return (write(1, "-2147483648", 11), 11);
	if (n == 0)
		return (write(1, "0", 1), 1);
	len = get_num_len(n);
	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
	}
	if (n >= 10)
		printf_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
	return (len);
}

int	handle_args(va_list *args, char format)
{
	if (format == 'c')
		return (ft_putchar_fd(va_arg(*args, int), 1), 1);
	if (format == 's')
		return (printf_str(va_arg(*args, char *)));
	if (format == 'd' || format == 'i')
		return (printf_putnbr(va_arg(*args, int)));
	return 0;
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
			{
				// handle error
				break ;
			}
			char_count += handle_args(&args, *format);
		}
		else
			char_count += printf_putchar(*format);
		format++;
	}
	va_end(args);
	return (char_count);
}
