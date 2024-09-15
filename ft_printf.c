/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeper <ezeper@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 20:10:48 by ezeper            #+#    #+#             */
/*   Updated: 2024/05/10 22:17:49 by ezeper           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format(const char *specifier, va_list argp)
{
	int	count;

	count = 0;
	if (*specifier == 'c')
		count = ft_print_char(va_arg(argp, int));
	else if (*specifier == 'd' || *specifier == 'i')
		count = ft_print_dig(va_arg(argp, int));
	else if (*specifier == 's')
		count = ft_print_str(va_arg(argp, const char *));
	else if (*specifier == 'x')
		count = ft_print_hex(va_arg(argp, unsigned long int), 'x');
	else if (*specifier == 'X')
		count = ft_print_hex(va_arg(argp, unsigned long int), 'X');
	else if (*specifier == 'u')
		count = ft_print_unsgn(va_arg(argp, unsigned int));
	else if (*specifier == 'p')
		count = ft_print_pointer(va_arg(argp, void *));
	else if (*specifier == '%')
		count = ft_print_char('%');
	else
		count = write(1, specifier++, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	argp;
	int		count;
	int		result;

	count = 0;
	va_start(argp, format);
	while (*format)
	{
		if (*format == '%')
		{
			result = print_format(++format, argp);
			if (result == -1)
				return (-1);
			count += result;
			++format;
		}
		else
		{
			if (write(1, format++, 1) != 1)
				return (-1);
			count++;
		}
	}
	va_end(argp);
	return (count);
}
