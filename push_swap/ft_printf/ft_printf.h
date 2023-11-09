/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyild <mehmyild@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 21:27:33 by mehmyild          #+#    #+#             */
/*   Updated: 2023/10/27 12:49:18 by mehmyild         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(char x);
int	ft_format(va_list *args, char w);
int	ft_int(int w);
int	ft_unsigned(unsigned int w);
int	ft_string(char *str);
int	ft_hex(unsigned int d, char w);
int	ft_point(unsigned long w, int i);
int	ft_check(char str);
#endif
