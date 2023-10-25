/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:50:57 by asaux             #+#    #+#             */
/*   Updated: 2023/10/25 10:25:28 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		check_conv(char c);
void	put_format(int conv, va_list liste, int *count);
void	ft_putchar(char c, int *count);
void	ft_putstr(char *s, int *count);
void	ft_putnbr(int n, int *count);
void	ft_putnbr_ui(unsigned int nbr, char *base, int *count);
void	ft_putnbr_ul(unsigned long nbr, char *base, int *count);
int		ft_strlen(char *s);
void	print_address(va_list liste, int *count);

#endif