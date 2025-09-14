/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malfarah <malfarah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 14:04:54 by malfarah          #+#    #+#             */
/*   Updated: 2025/09/14 17:13:06 by malfarah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// # include <stdio.h>
// # include <stdlib.h>
// # include <string.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *frmt, ...);
int	ft_putchar(char c);
int	ft_puthexa(unsigned long n, char c);
int	ft_putnbr(int n);
int	ft_putstr(char *s);
int	ft_putunbr(unsigned int n);
int	ft_putv(void *x);

#endif