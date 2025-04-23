/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvon-ah- <gvon-ah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:34:59 by gvon-ah-          #+#    #+#             */
/*   Updated: 2025/01/06 17:04:17 by gvon-ah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	aux_str(char *src)
{
	if (!src)
		return (write(1, "(null)", 6));
	else
		return (write(1, src, ft_strlen(src)));
}

int	aux_ptr(unsigned long int ptr)
{
	int	i;

	i = 0;
	if (!ptr)
	{
		i += write (1, "(nil)", 5);
	}
	else
	{
		i += write(1, "0x", 2);
		i += aux_putpt(ptr, EX_LOW_BASE, 0);
	}
	return (i);
}

static int	is_char(const char *src, const char c)
{
	while (*src)
	{
		if (*src == c)
			return (1);
		src++;
	}
	return (0);
}

int	aux_flag(int c, va_list *args)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += ft_putchar(va_arg(*args, int));
	if (c == 's')
		i += aux_str(va_arg(*args, char *));
	if (c == 'p')
		i += aux_ptr(va_arg(*args, long int));
	if (c == 'd' || c == 'i')
		i += aux_putnbr(va_arg(*args, int), 0);
	if (c == 'u')
		i += aux_putunbr(va_arg(*args, unsigned int), 0);
	if (c == 'x')
		i += aux_putbs(va_arg(*args, unsigned int), EX_LOW_BASE, 0);
	if (c == 'X')
		i += aux_putbs(va_arg(*args, unsigned int), EX_UP_BASE, 0);
	if (c == '%')
		i += write(1, "%", 1);
	return (i);
}

int	ft_printf(const	char *src, ...)
{
	int		len;
	va_list	args;
	size_t	i;

	if (!src)
		return (-1);
	len = 0;
	va_start(args, src);
	i = 0;
	while (src[i])
	{
		if (src[i] == '%' && is_char(POSSIBLE_FLAGS, src[i + 1]))
			len += aux_flag(src[++i], &args);
		else if (src[i])
			len += write(1, &src[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
