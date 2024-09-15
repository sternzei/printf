/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeper <ezeper@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:21:38 by ezeper            #+#    #+#             */
/*   Updated: 2024/05/10 22:27:12 by ezeper           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_hex(unsigned long int num, char format, int *len)
{
	unsigned long int	rem;
	int y;

	rem = num % 16;
	if (num / 16 > 0)
	{
		y = ft_put_hex(num / 16, format, len);
	}
	if (rem <= 9)
	{
		y = ft_putchar_fd(rem + '0', 1);
		if (y == -1)
			return (-1);
	}
	else
	{
		if (format == 'x')
			y = ft_putchar_fd(rem - 10 + 'a', 1);
		else if (format == 'X')
			y = ft_putchar_fd(rem - 10 + 'A', 1);
		if (y == -1)
			return (-1);
	}
	(*len)++;
	return(y);
}

int	ft_print_hex(unsigned int num, char format)
{
	int	len;
	int y;

	len = 0;
	if (num == 0)
	{
		y = ft_putchar_fd('0', 1);
	}
	else
	{
		y = ft_put_hex(num, format, &len);
	}
	return (y);
}
