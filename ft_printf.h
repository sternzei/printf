/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeper <ezeper@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:48:07 by ezeper            #+#    #+#             */
/*   Updated: 2024/05/10 20:14:25 by ezeper           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
#define PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_print_char(char c);
int		ft_print_str(const char *s);
int	ft_putchar_fd(const char c, int fd);
int		ft_print_dig(int n);
int		ft_print_unsgn(unsigned int n);
int		ft_print_pointer(void *ptr);
int		ft_print_hex(unsigned int num, char format);
int	ft_putstr(const char *s);

#endif
