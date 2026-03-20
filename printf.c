/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/17 16:00:01 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/03/20 18:36:03 by yoneshev      ########   odam.nl         */
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

int	handle_args(va_list *args, char format)
{
	if (format == 'c')
		return (ft_putchar_fd(va_arg(*args, int), 1), 1);
	if (format == 's')
		return (printf_str(va_arg(*args, char *)));
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
			char_count++;
		format++;
	}
	va_end(args);
	return (char_count);
}

int main()
{
	int x = printf("%s%c", "hello", '!');
	printf("\n%d", x);
}