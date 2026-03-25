/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_string.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/25 19:28:19 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/03/25 19:39:59 by yoneshev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	printf_str(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}
