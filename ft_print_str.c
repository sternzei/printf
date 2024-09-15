/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeper <ezeper@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:05:42 by ezeper            #+#    #+#             */
/*   Updated: 2024/05/10 22:07:10 by ezeper           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *s)
{
	int	i;
	int y;
	i = 0;
	
	while (s[i] != '\0')
	{
		y = write(1, &s[i], 1);
		if(y == -1)
			return(y);
		i++;
	}
	return(1);
}

int	ft_print_str(const char *s)
{
	unsigned int	i;
	int y;

	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	i = 0;
	while (s[i])
	{
		y = write(1, &s[i], 1);
		if(y == -1)
			return(-1);
		i++;
	}
	return (i);
}
