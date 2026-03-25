/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_numbers.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: yoneshev <yoneshev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/25 19:30:54 by yoneshev      #+#    #+#                 */
/*   Updated: 2026/03/25 19:31:03 by yoneshev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_num_len(long long n)
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

int	printf_putunsigned(unsigned int n)
{
	char	c;
	int		len;

	if (n == 0)
		return (write(1, "0", 1), 1);
	len = get_num_len(n);
	if (n >= 10)
		printf_putunsigned(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
	return (len);
}
