/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsgn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeper <ezeper@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:45:13 by ezeper            #+#    #+#             */
/*   Updated: 2024/05/10 20:27:37 by ezeper           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	unsigned int	i;
	size_t			len;
	char			*dup;

	i = 0;
	len = ft_strlen(s1);
	if (s1 == NULL)
	{
		return (NULL);
	}
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (dup != NULL)
	{
		while (s1[i])
		{
			dup[i] = s1[i];
			i++;
		}
		dup[i] = '\0';
	}
	return (dup);
}

static long	callen(unsigned int num)
{
	long	len;

	if (num == 0)
	{
		return (0);
	}
	len = 0;
	if (num < 0)
	{
		len++;
		num = -num;
	}
	while (num != 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa_unsgn(unsigned int n)
{
	char			*r;
	unsigned int	l;

	l = callen(n);
	if (n == 0)
		return (ft_strdup("0"));
	r = (char *)malloc((l + 1) * sizeof(char));
	if (!r)
		return (NULL);
	r[l--] = '\0';
	if (n < 0)
		n = -1 * n;
	r[0] = '-';
	while (n > 0)
	{
		r[l] = (n % 10) + '0';
		n = n / 10;
		l--;
	}
	return (r);
}

int	ft_print_unsgn(unsigned int n)
{
	unsigned int	len;
	char			*num;

	num = ft_itoa_unsgn(n);
	len = ft_print_str(num);
	free(num);
	return (1);
}
