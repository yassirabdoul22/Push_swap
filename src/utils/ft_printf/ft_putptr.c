/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdoul <yaabdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 21:45:59 by yaabdoul          #+#    #+#             */
/*   Updated: 2025/11/02 21:46:00 by yaabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_hex(unsigned long n)
{
	int		count;
	char	c;

	count = 0;
	if (n >= 16)
		count += ft_putptr_hex(n / 16);
	c = "0123456789abcdef"[n % 16];
	count += write(1, &c, 1);
	return (count);
}

int	ft_putptr(void *ptr)
{
	unsigned long	n;
	int				count;

	n = (unsigned long)ptr;
	count = 0;
	if (!ptr)
		return (write(1, "(nil)", 5));
	count += write(1, "0x", 2);
	count += ft_putptr_hex(n);
	return (count);
}
