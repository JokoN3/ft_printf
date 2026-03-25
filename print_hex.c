/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_hex.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/25 19:33:08 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/03/25 19:53:35 by yoneshev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_hex_len(unsigned long n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		i++;
		n /= 16;
	}
	return (i);
}

int	print_hex(unsigned int n, char *hex)
{
	int		len;

	if (n == 0)
		return (write(1, "0", 1), 1);
	len = get_hex_len(n);
	if (n >= 16)
		print_hex(n / 16, hex);
	write(1, &hex[n % 16], 1);
	return (len);
}

int	print_address(uintptr_t n, int recur, char *hex)
{
	int		len;

	len = 0;
	if (!n)
		return (write(1, "(nil)", 5));
	if (recur == 0)
		len = write(1, "0x", 2);
	recur = 1;
	len += get_hex_len((unsigned long) n);
	if (n >= 16)
		print_address(n / 16, recur, "0123456789abcdef");
	write(1, &hex[n % 16], 1);
	return (len);
}
