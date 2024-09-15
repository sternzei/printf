/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeper <ezeper@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:37:31 by ezeper            #+#    #+#             */
/*   Updated: 2024/05/10 20:11:47 by ezeper           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	int y;
	y = write(fd, &c, 1);
	return(y);
}

int	ft_print_char(char c)
{
	int y;
	y = ft_putchar_fd(c, 1);
	return (y);
}
