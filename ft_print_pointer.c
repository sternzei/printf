/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeper <ezeper@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:09:01 by ezeper            #+#    #+#             */
/*   Updated: 2024/05/13 16:31:00 by ezeper           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_point(unsigned long int num, char format, int *len)
{
	unsigned long int	rem;
	int					y;

	len = 0;
	rem = num % 16;
	if (num / 16 > 0)
	{
		y = ft_put_point(num / 16, format, len);
		if (y == -1)
			return (-1);
		len += y;
	}
	if (rem <= 9)
	{
		y = ft_putchar_fd(rem + '0', 1);//akm 1-den 16 ya kadar olan karakterleri stringe koy len e gore ostringden cek
		if (y == -1)
			return (-1);
		len += y;
	}
	else
	{
		if (format == 'x')
			ft_putchar_fd(rem - 10 + 'a', 1);
		else if (format == 'X')
			ft_putchar_fd(rem - 10 + 'A', 1);
	}
	(*len)++;
	return(y);
}

static int	ft_put_point(unsigned long int num, char format, int *len)
{
	unsigned long int	rem;
	int					y;
	int					xlen;

	len = 0;
	rem = num % 16;
	if (num / 16 > 0)
	{
		num = num / 16;
	}
	if (rem <= 9)
	{
		y = ft_putchar_fd(rem + '0', 1);//akm 1-den 16 ya kadar olan karakterleri stringe koy len e gore ostringden cek
		if (y == -1)
			return (-1);
		len += y;
	}
	else
	{
		if (format == 'x')
			ft_putchar_fd(rem - 10 + 'a', 1);
		else if (format == 'X')
			ft_putchar_fd(rem - 10 + 'A', 1);
	}
	(*len)++;
}

int	ft_print_pointer(void *ptr)
{
	int					len;
	unsigned long int	num;
	int					y;

	num = (unsigned long int)ptr;
	ft_putstr("0x");
	len = 2;
	if (num == 0)
	{
		y = ft_putchar_fd('0', 1);
		if (y == -1)
			return (-1);
		len += y;
	}
	else
	{
		y = ft_put_point((num), 'x', &len);
		if (y == -1)
			return (-1);
		len += y;
	}
	return (len);
}
