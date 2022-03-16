/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatilla <yatilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:40:33 by yatilla           #+#    #+#             */
/*   Updated: 2022/03/16 11:46:34 by yatilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_putnbr(int nbr);
int		ft_printstr(char *str);
int		ft_putchar(char a);
int		ft_printptr(unsigned long long num);
int		ft_printhex(unsigned int num, char format);
int		ft_print_unsign(unsigned int u);

int		format_specifier(va_list arg, const char format);
int		hexlen(unsigned int num);
int		ptrlen(unsigned long long num);
void	ft_printbig(unsigned int num, int len, char *str);
void	ft_printsm(unsigned int num, int len, char *str);
void	*ft_memset(void *s, int val, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);

#endif
