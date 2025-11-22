/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdoul <yaabdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 21:44:53 by yaabdoul          #+#    #+#             */
/*   Updated: 2025/11/03 14:18:10 by yaabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conversion(const char *str, size_t *i, va_list *args)
{
	*i = *i + 1;
	if (str[*i] == 'c')
		return (ft_putchar((char)va_arg(*args, int)));
	else if (str[*i] == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (str[*i] == 'd' || str[*i] == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (str[*i] == 'u')
		return (ft_putunsigned(va_arg(*args, unsigned int)));
	else if (str[*i] == 'x' || str[*i] == 'X')
		return (ft_puthex(va_arg(*args, unsigned int), str[*i]));
	else if (str[*i] == 'p')
		return (ft_putptr(va_arg(*args, void *)));
	else if (str[*i] == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		tmp;
	size_t	i;

	count = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			tmp = conversion(str, &i, &args);
		else
			tmp = ft_putchar(str[i]);
		if (tmp >= 0)
			count += tmp;
		i++;
	}
	va_end(args);
	return (count);
}
