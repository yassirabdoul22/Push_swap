/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdoul <yaabdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 21:47:13 by yaabdoul          #+#    #+#             */
/*   Updated: 2025/11/02 21:50:32 by yaabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int	ft_printf(const char *format, ...);
int	ft_putunsigned(unsigned int n);
int	ft_puthex(unsigned int n, const char format);
int	ft_putptr(void *ptr);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int c);

#endif
